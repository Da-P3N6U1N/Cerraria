#include "chunk_map.h"

int chunk_map_index(const chunk_map_t *map, int cx, int cy)
{
    return cx * map->chunk_count_y + cy;
}

chunk_map_t chunk_map_create(int chunk_count_x, int chunk_count_y)
{
    chunk_map_t map;
    map.chunk_count_x = chunk_count_x;
    map.chunk_count_y = chunk_count_y;
    map.chunks = NULL;

    if (chunk_count_x <= 0 || chunk_count_y <= 0) 
    {
        map.chunk_count_x = 0;
        map.chunk_count_y = 0;
        return map;
    }

    long long total = (long long)chunk_count_x * (long long)chunk_count_y;
    if (total > (long long) (SIZE_MAX / sizeof(chunk_t))) 
    {
        map.chunk_count_x = 0;
        map.chunk_count_y = 0;
        return map;
    }

    map.chunks = (chunk_t *) malloc((size_t) total * sizeof(chunk_t));
    if (map.chunks == NULL) 
    {
        map.chunk_count_x = 0;
        map.chunk_count_y = 0;
        return map;
    }

    int cx, cy;
    for (cx = 0; cx < chunk_count_x; cx++)
     {
        for (cy = 0; cy < chunk_count_y; cy++) 
        {
            int idx = chunk_map_index(&map, cx, cy);
            map.chunks[idx] = chunk_create_empty();
        }
    }

    return map;
}

void chunk_map_destroy(chunk_map_t *map)
{
    if (map == NULL)
        return;
    if (map->chunks != NULL)
    {
        free(map->chunks);
        map->chunks = NULL;
    }
    map->chunk_count_x = 0;
    map->chunk_count_y = 0;
}

chunk_t * chunk_map_get_chunk(chunk_map_t *map, int chunkX, int chunkY)
{
    if (map == NULL)
        return NULL;
    if (chunkX < 0 || chunkX >= map->chunk_count_x)
        return NULL;
    if (chunkY < 0 || chunkY >= map->chunk_count_y)
        return NULL;

    int idx = chunk_map_index(map, chunkX, chunkY);
    return &map->chunks[idx];
}

tile_t chunk_map_get_tile(chunk_map_t *map, int x, int y)
{
    tile_t out = tile_create(TILE_AIR);

    if (map == NULL) 
        return out;
    if (x < 0 || y < 0) 
        return out;

    int chunkX = x / CHUNK_SIZE;
    int chunkY = y / CHUNK_SIZE;
    chunk_t *chunk = chunk_map_get_chunk(map, chunkX, chunkY);
    if (chunk == NULL) 
        return out;

    int localX = x - chunkX * CHUNK_SIZE;
    int localY = y - chunkY * CHUNK_SIZE;

    if (localX < 0 || localX >= CHUNK_SIZE || localY < 0 || localY >= CHUNK_SIZE)
        return out;

    return chunk_get_tile(chunk, localX, localY);
}

void chunk_map_set_tile(chunk_map_t *map, int x, int y, tile_t tile)
{
    if (map == NULL)
        return;
    if (x < 0 || y < 0)
        return;

    int chunkX = x / CHUNK_SIZE;
    int chunkY = y / CHUNK_SIZE;
    chunk_t *chunk = chunk_map_get_chunk(map, chunkX, chunkY);
    if (chunk == NULL)
        return;

    int localX = x - chunkX * CHUNK_SIZE;
    int localY = y - chunkY * CHUNK_SIZE;

    if (localX < 0 || localX >= CHUNK_SIZE || localY < 0 || localY >= CHUNK_SIZE)
        return;

    chunk_set_tile(chunk, localX, localY, tile);
}

void chunk_map_render(chunk_map_t *map, int offsetX, int offsetY, camera_t *camera, int chunks_from_camera_x, int chunks_from_camera_y)
{
    if (map == NULL || map->chunks == NULL)
        return;

    int camera_chunk_x = (int)((camera->camera.target.x - offsetX) / (CHUNK_SIZE * TILE_SIZE));
    int camera_chunk_y = (int)((camera->camera.target.y - offsetY) / (CHUNK_SIZE * TILE_SIZE));

    int cx, cy;
    for (cx = 0; cx < map->chunk_count_x; cx++) 
    {
        for (cy = 0; cy < map->chunk_count_y; cy++) 
        {
            if (abs(cx - camera_chunk_x) <= chunks_from_camera_x &&
                abs(cy - camera_chunk_y) <= chunks_from_camera_y)
            {
                int idx = chunk_map_index(map, cx, cy);
                int chunkOffsetX = offsetX + cx * CHUNK_SIZE * TILE_SIZE;
                int chunkOffsetY = offsetY + cy * CHUNK_SIZE * TILE_SIZE;
                chunk_render(&map->chunks[idx], chunkOffsetX, chunkOffsetY);
            }
        }
    }
}
