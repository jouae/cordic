/*
 * A coordinate rotation digital computer using fixed-point C library
 *
 * Copyright (c) 2024 Yan-Jie, Chen
 */

/*
 * Fixed-point type definitions
 *
 * "Qm.f" is a representation of a fixed-point type, where "m" bits are used
 * for the integer part, "f" bits are used for the fractional part, and 1 bit
 * is used for the sign. The total number of used bits is 1 + m + f.
 *
 * fixed_t - A fixed-point type in the Q23.8 format.
 *
 *            Hex                                     Binary
 * Max 0x7fffffff    0111 1111 1111 1111 1111 1111 1111 1111
 * Min 0x80000000    1000 0000 0000 0000 0000 0000 0000 0000
 *         Decimal           Actual
 * Max  2147483647    8388607.99609
 * Min -2147483648         -8388608
 *
 * The tables is based on two's complement representation.
 */

typedef int32_t fixed_t;

#define FIXED_FRACTION_BITS 8
#define FIXED_INTEGER_BITS 23

static inline fixed_t factor_K;

/* trigonometric functions by CORDIC algorithms */

/*
 * Conventional CORDIC
 */
fixed_t conv_sin(fixed_t theta);
fixed_t conv_cos(fixed_t theta);
fixed_t conv_sincos(fixed_t theta);
fixed_t conv_tan(fixed_t theta);

/*
 * CORDIC with look up table
 */
fixed_t LUT_sin(fixed_t theta);
fixed_t LUT_cos(fixed_t theta);
fixed_t LUT_sincos(fixed_t theta);
fixed_t LUT_tan(fixed_t theta);

/*
 * Scaling-free CORDIC
 */
fixed_t SF_sin(fixed_t theta);
fixed_t SF_cos(fixed_t theta);
fixed_t SF_sincos(fixed_t theta);
fixed_t SF_tan(fixed_t theta);

/*
 * hybrid CORDIC
 */
fixed_t hybrid_sin(fixed_t theta);
fixed_t hybrid_cos(fixed_t theta);
fixed_t hybrid_sincos(fixed_t theta);
fixed_t hybrid_tan(fixed_t theta);