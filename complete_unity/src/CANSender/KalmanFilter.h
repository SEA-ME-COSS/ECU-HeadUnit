#ifndef KALMANFILTER_H
#define KALMANFILTER_H


#ifdef __cplusplus
extern "C" {
#endif


#include <stdint.h>
#include <math.h>

#include "KalmanFactor.h"


#define SIZE 2
#define MEASURE_SIZE 1


void matrix_multiply(double A[SIZE][SIZE], double B[SIZE][SIZE], double result[SIZE][SIZE]);
void kalmanFilter_(double measuredstate, double estimation[SIZE], double letterP[SIZE][SIZE], double dt, double renewed_e[SIZE], double renewed_P[SIZE][SIZE]);
uint16_t filter(uint16_t speed_sensor_rpm);


#ifdef __cplusplus
}
#endif


#endif

