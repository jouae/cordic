/*  
 * A Coordinate Rotation DIgital Computer(CORDIC) C library
 *
 * Copyright (c) 2024 Yan-Jie, Chen
 */
#include <stdint.h>

typedef int32_t fixed_t;

#define FIXED_INTEGER_BITS 23
#define FIXED_FRACTION_BITS 8

/*
 * CORDIC algorithms
 */

/*
 * Conventional CORDIC using floating point
 *
 * see
 * Volder, Jack E. "The CORDIC trigonometric computing technique."
 * IRE Transactions on electronic computers 3 (1959): 330-334.
 */
float conv_sin(float theta);
float conv_cos(float theta);
float conv_sincos(float theta);
float conv_tan(float theta);

/*
 * CORDIC with look up table
 */
fixed_t LUT_sin(fixed_t theta);
fixed_t LUT_cos(fixed_t theta);
fixed_t LUT_sincos(fixed_t theta);
fixed_t LUT_tan(fixed_t theta);

/*
 * Scale-free CORDIC
 *
 * see
 * Dhar, Anindya S., and Swapna Banerjee. 
 * "An array architecture for fast computation of discrete Hartley transform."
 * IEEE transactions on circuits and systems 38.9 (1991): 1095-1098.
 */
fixed_t SF_sin(fixed_t theta);
fixed_t SF_cos(fixed_t theta);
fixed_t SF_sincos(fixed_t theta);
fixed_t SF_tan(fixed_t theta);

/*
 * Hybird CORDIC
 */
fixed_t hybird_sin(fixed_t theta);
fixed_t hybird_cos(fixed_t theta);
fixed_t hybird_sincos(fixed_t theta);
fixed_t hybird_tan(fixed_t theta);