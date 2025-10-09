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

// it will have 9 values,
// [1] [2] [3]
// [4] [5] [6]
// [7] [8] [9]
// [5] is the tile being rendered
// return the texture id to be drawn
typedef int (*special_render)(tile_id_t *ids, int x, int y);

typedef struct 
{
    char* name;
    bool solid;
    int texture_id;
    special_render render;
} tile_data_t;

typedef struct
{
    tile_id_t id;
} tile_t;

void init_tile_types();

tile_t tile_create(tile_id_t id);

void tile_draw(tile_t tile, int x, int y);