#ifndef KALMANFACTOR_H
#define KALMANFACTOR_H


#define SIZE 2


extern double speed_sensor_estimation[SIZE];
extern double speed_sensor_letterP[SIZE][SIZE];
extern double speed_sensor_dt;
extern double speed_sensor_renewed_e[SIZE], speed_sensor_renewed_P[SIZE][SIZE];
extern double speed_sensor_measuredstate;


#endif

