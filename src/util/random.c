#include "random.h"

double util_drand48() 
{
    double x = 0.0;
    double denom = (double)RAND_MAX + 1.0;
    double factor = 1.0;

    while (factor < PRECISION) 
    {
        x = x * denom + rand();
        factor *= denom;
    }
    
    return x / factor;
}

double util_drand48_signed() 
{
    double u = util_drand48();
    return u * 2.0 - 1.0;
}

int util_seed_rand(int seed) 
{
    srand((unsigned int)seed);
    return seed;
}