#pragma once

#include <stdlib.h>
#include <time.h>

// TODO: LATER WORK ON PERLIN NOISE!!!

// smoothening functions
float lerp(float lo, float hi, float t);
float default_smooth_func(float x);
float cosine_interpolation(float x);
float smoothstep(float x);

typedef float (*smooth_function)(float);

typedef struct
{
    float* rand_values;
    int seed;
    smooth_function smooth_func;
} value_noise_t;

value_noise_t value_noise_create(int size, smooth_function func, int seed);

float value_noise_eval(value_noise_t* noise, float x);
float value_noise_advanced_eval(value_noise_t* noise, float x, float frequency, float amplitude);