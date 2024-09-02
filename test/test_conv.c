#include "cordic.h"
#include <math.h>
#include <stdio.h>

int main()
{
    float x ,y;
    
    printf("Trig degree: CORDIC, math.h\n");
    for(float i = 0; i < 91; i++)
    {
        x = conv_cos(i);
        y = conv_sin(i);
        printf("cos %-3.f degree: %-10.6f, %-10.6f\n", i, x, cosf(i*PI/180.0));
        printf("sin %-3.f degree: %-10.6f, %-10.6f\n\n", i, y, sinf(i*PI/180.0));
    }
    
    return 0;
}