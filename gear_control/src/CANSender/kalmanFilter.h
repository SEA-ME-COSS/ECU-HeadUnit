#ifndef KALMANFILTER_H
#define KALMANFILTER_H


#ifdef __cplusplus
extern "C" {
#endif


// Include necessary header
#include <stdint.h>
#include <math.h>


#define SIZE 2
#define MEASURE_SIZE 1


extern double speed_sensor_estimation[SIZE];
extern double speed_sensor_letterP[SIZE][SIZE];
extern double speed_sensor_dt;
extern double speed_sensor_renewed_e[SIZE], speed_sensor_renewed_P[SIZE][SIZE];
extern double speed_sensor_measuredstate;

void matrix_multiply(double A[SIZE][SIZE], double B[SIZE][SIZE], double result[SIZE][SIZE]);
void kalmanFilter_(double measuredstate, double estimation[SIZE], double letterP[SIZE][SIZE], double dt, double renewed_e[SIZE], double renewed_P[SIZE][SIZE]);
uint16_t filter(uint16_t speed_sensor_rpm);


#ifdef __cplusplus
}
#endif


#endif

