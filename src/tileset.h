#pragma once

#include <raylib.h>

typedef struct
{
    Texture texture;
    int tile_width;
} tileset_t;

void tileset_create(const char* path, int tile_width);
void tileset_draw_id(int id, float x, float y);
void tileset_free();