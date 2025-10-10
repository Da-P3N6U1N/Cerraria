#include "lerp.h"

float lerp(float lo, float hi, float t)
{
    return lo * (1 - t) + hi * t;
}