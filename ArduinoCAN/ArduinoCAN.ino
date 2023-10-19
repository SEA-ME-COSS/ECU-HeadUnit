#include <mcp2515.h>


struct can_frame canMsg1;
MCP2515 mcp2515(9);

const byte PulsesPerRevolution = 20;      // Number of pulses per one complete rotor revolution
const unsigned long ZeroTimeout = 100000; // Timeout to detect absence of a pulse signal (in microseconds)
const byte numReadings = 2;                // Number of readings to average for stability

volatile unsigned long LastTimeWeMeasured;
volatile unsigned long PeriodBetweenPulses = ZeroTimeout + 1000; // Initialize pulse period
volatile unsigned long PeriodAverage = ZeroTimeout + 1000;       // Initialize average pulse period
unsigned long FrequencyRaw;               // Raw frequency of the pulse signal
unsigned long FrequencyReal;              // Real frequency of the pulse signal
unsigned long RPM;                        // Revolutions per minute (computed from frequency)
unsigned int PulseCounter = 1;            // Counter for pulse events
unsigned long PeriodSum;                  // Sum of pulse periods

unsigned long LastTimeCycleMeasure = LastTimeWeMeasured; // Store the last measured time
unsigned long CurrentMicros = micros();                  // Current time in microseconds
unsigned int AmountOfReadings = 1;                      // Number of readings for averaging
unsigned int ZeroDebouncingExtra;                        // Extra time to debounce zero pulses
unsigned long readings[numReadings];                    // Store recent RPM readings
unsigned long readIndex;                                // Index for reading buffer
unsigned long total;                                    // Sum of RPM readings for averaging
unsigned long average;                                  // Average RPM value


void setup() 
{
  // Attach an interrupt to digital pin 3 that triggers when a rising pulse is detected
  attachInterrupt(digitalPinToInterrupt(3), Pulse_Event, RISING);

  // Initialize the MCP2515 controller and set the CAN bus speed and mode
  mcp2515.reset();
  mcp2515.setBitrate(CAN_500KBPS, MCP_16MHZ);
  mcp2515.setNormalMode();
}


void loop() 
{
  // Store the current time and handle time rollover
  LastTimeCycleMeasure = LastTimeWeMeasured;
  CurrentMicros = micros();
  if (CurrentMicros < LastTimeCycleMeasure) 
  {
    LastTimeCycleMeasure = CurrentMicros;
  }

  // Calculate the raw frequency of the pulse signal
  FrequencyRaw = 10000000000 / PeriodAverage;
  
  // Check for zero pulse condition and apply debouncing
  if (PeriodBetweenPulses > ZeroTimeout - ZeroDebouncingExtra || CurrentMicros - LastTimeCycleMeasure > ZeroTimeout - ZeroDebouncingExtra) 
  {
    FrequencyRaw = 0;
    ZeroDebouncingExtra = 2000;
  } 
  else 
  {
    ZeroDebouncingExtra = 0;
  }

  // Convert the raw frequency to a more manageable value
  FrequencyReal = FrequencyRaw / 10000;

  // Calculate RPM from the frequency and convert units
  RPM = FrequencyRaw / PulsesPerRevolution * 60;
  RPM = RPM / 10000;

  // Update the rolling average of RPM readings
  total = total - readings[readIndex];
  readings[readIndex] = RPM;
  total = total + readings[readIndex];
  readIndex = readIndex + 1;

  if (readIndex >= numReadings) 
  {
    readIndex = 0;
  }

  average = total / numReadings;

  // Prepare a CAN message with the RPM value
  canMsg1.can_id  = 0x0F6;
  canMsg1.can_dlc = 2;
  canMsg1.data[0] = (RPM & 0xFF00) >> 8;
  canMsg1.data[1] = (RPM & 0x00FF);

  // Send the CAN message
  mcp2515.sendMessage(&canMsg1);
}


void Pulse_Event() 
{
  // Calculate the time between pulses and update variables for averaging
  PeriodBetweenPulses = micros() - LastTimeWeMeasured;
  LastTimeWeMeasured = micros();

  if (PulseCounter >= AmountOfReadings)  
  {
    // Calculate the average period and reset variables
    PeriodAverage = PeriodSum / AmountOfReadings;
    PulseCounter = 1;
    PeriodSum = PeriodBetweenPulses;

    // Dynamically adjust the number of readings for averaging
    int RemappedAmountOfReadings = map(PeriodBetweenPulses, 40000, 5000, 1, 10);
    RemappedAmountOfReadings = constrain(RemappedAmountOfReadings, 1, 10);
    AmountOfReadings = RemappedAmountOfReadings;
  } 
  else 
  {
    PulseCounter++;
    PeriodSum = PeriodSum + PeriodBetweenPulses;
  }
}
