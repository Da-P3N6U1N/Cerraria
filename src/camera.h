#pragma once

#include "raylib.h"
#include "constants.h"

typedef struct
{
    Camera2D camera;
} camera_t;

camera_t camera_make(float x, float y);
void camera_set_pos(camera_t *c, float x, float y);
void camera_change_pos(camera_t *c, float deltaX, float deltaY);
float camera_get_x(camera_t *c);
float camera_get_y(camera_t *c);