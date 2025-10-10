#pragma once

#include <stdlib.h>
#include <time.h>
#include "lerp.h"
#include "random.h"

float cosine_interpolation(float x);
float smoothstep(float x);
float default_smooth_func(float x);

typedef float (*smooth_function)(float);

typedef struct
{
    float* rand_values;
    int seed;
    smooth_function smooth_func;
} value_noise_t;

value_noise_t value_noise_create(int size, smooth_function func, int seed);
void value_noise_destroy(value_noise_t* noise);

float value_noise_eval(value_noise_t* noise, float x);
float value_noise_advanced_eval(value_noise_t* noise, float x, float frequency, float amplitude);