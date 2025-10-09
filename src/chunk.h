#pragma once

#include "tile.h"
#include "tileset.h"
#include "constants.h"

typedef struct
{
    tile_t tiles[CHUNK_SIZE][CHUNK_SIZE];
} chunk_t;

chunk_t chunk_create_empty();
tile_t chunk_get_tile(chunk_t* chunk, int x, int y);
void chunk_set_tile(chunk_t* chunk, int x, int y, tile_t tile);
void chunk_render(chunk_t* chunk, int offsetX, int offsetY);