#pragma once

#include <raylib.h>
#include <stdbool.h>


typedef enum 
{
    TILE_AIR,
    TILE_DIRT,
    TILE_STONE,
    TILE_GRASS,
} tile_id_t;

typedef struct 
{
    char* name;
    bool solid;
    int texture_id;
} tile_data_t;

typedef struct
{
    tile_id_t id;
} tile_t;

void init_tile_types();

tile_t tile_create(tile_id_t id);

void tile_draw(tile_t tile, int x, int y);