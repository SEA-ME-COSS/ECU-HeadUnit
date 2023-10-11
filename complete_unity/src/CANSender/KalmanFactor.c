#include "KalmanFactor.h"


double speed_sensor_estimation[SIZE] = {0, 0};
double speed_sensor_letterP[SIZE][SIZE] = {{100, 0},
                                           {0, 100}};
double speed_sensor_dt = 1;
double speed_sensor_renewed_e[SIZE], speed_sensor_renewed_P[SIZE][SIZE];
double speed_sensor_measuredstate;

