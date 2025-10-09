#pragma once

#include "chunk.h"
#include <stdlib.h>
#include <stdint.h>
#include "camera.h"

typedef struct 
{
    chunk_t *chunks;
    int chunk_count_x;
    int chunk_count_y;
} chunk_map_t;

int chunk_map_index(const chunk_map_t *map, int cx, int cy);
chunk_map_t chunk_map_create(int chunk_count_x, int chunk_count_y);
void chunk_map_destroy(chunk_map_t *map);
chunk_t * chunk_map_get_chunk(chunk_map_t *map, int chunkX, int chunkY);
tile_t chunk_map_get_tile(chunk_map_t *map, int x, int y);
void chunk_map_set_tile(chunk_map_t *map, int x, int y, tile_t tile);
void chunk_map_render(chunk_map_t *map, int offsetX, int offsetY, camera_t *camera, int chunks_from_camera_x, int chunks_from_camera_y);