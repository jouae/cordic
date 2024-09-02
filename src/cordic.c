#include <math.h>
#include <stdio.h>
#include "cordic.h"

#define MAX_ITER 15
#define PI 3.141592654

/*
 * compute_factor - Compute the scale factor 
 *
 * @n: the maximum iteration of CORDIC
 */
float compute_factor(int n) {
    float k = 1.0;
    
    for(int i = 0; i < n; i++)
    {
        k /= sqrtf(1.0 + powf(2, -2*i));
    }
    
    return k;
}

float conv_sincos(float theta, float *x, float *y) {
    float sum_angle, temp;

    sum_angle = 0.0;
    *x = compute_factor(MAX_ITER);
    *y = 0.0;

    theta = fmod(theta, 360.0);

    for(int i = 0; i < MAX_ITER; i++)
    {
        temp = *x;
        if(sum_angle < theta)
        {
            /* Rotate counterclockwise*/
            *x -= powf(2, -i) * *y;
            *y += powf(2, -i) * temp;
            sum_angle += atanf(powf(2, -i)) * 180.0 / PI;
        }
        else
        {
            /* Rotate clockwise */
            *x += powf(2, -i) * *y;
            *y -= powf(2, -i) * temp;
            sum_angle -= atanf(powf(2, -i)) * 180.0 / PI;
        }
    }

    return 0;
}

float conv_sin(float theta) {
    float x, y;

    conv_sincos(theta, &x, &y);

    return y;
}

float conv_cos(float theta) {
    float x, y;

    conv_sincos(theta, &x, &y);

    return x;
}