#include "noise.h"
#include "constants.h"
#include <math.h>

float lerp(float lo, float hi, float t)
{
    return lo * (1 - t) + hi * t;
}

float default_smooth_func(float x)
{
    return x;
}

float cosine_interpolation(float x)
{
    return (1 - cos(x * M_PI)) * 0.5f;
}

float smoothstep(float x)
{
    return x * x * (3 - 2 * x);
}

value_noise_t value_noise_create(int size, smooth_function func, int seed)
{
    if (seed == 0) seed = time(NULL);

    value_noise_t noise;

    noise.seed = seed;
    noise.smooth_func = func;
    if (func == NULL) noise.smooth_func = default_smooth_func;

    noise.rand_values = (float*)malloc(sizeof(float) * size);

    for (int i = 0; i < size; i++)
        noise.rand_values[i] = (float)rand() / (float)RAND_MAX;

    return noise;
}

float value_noise_eval(value_noise_t* noise, float x)
{
    srand((unsigned int)noise->seed);

    int xMin = (int)x;
    return lerp(noise->rand_values[xMin], noise->rand_values[xMin + 1], noise->smooth_func(x - xMin));
}

float value_noise_advanced_eval(value_noise_t* noise, float x, float frequency, float amplitude)
{
    return amplitude * value_noise_eval(noise, x * frequency);
}

void value_noise_destroy(value_noise_t* noise)
{
    free(noise->rand_values);
}