#include "chunk.h"

chunk_t chunk_create_empty()
{
    chunk_t chunk;
    for (int i = 0; i < CHUNK_SIZE; i++)
        for (int j = 0; j < CHUNK_SIZE; j++)
            chunk.tiles[i][j] = tile_create(TILE_AIR);
    
    return chunk;
}

tile_t chunk_get_tile(chunk_t* chunk, int x, int y)
{
    if (x < 0 || x >= CHUNK_SIZE || y < 0 || y >= CHUNK_SIZE)
        return tile_create(TILE_AIR);
    
    return chunk->tiles[x][y];
}

void chunk_set_tile(chunk_t* chunk, int x, int y, tile_t tile)
{
    if (x < 0 || x >= CHUNK_SIZE || y < 0 || y >= CHUNK_SIZE)
        return;
    
    chunk->tiles[x][y] = tile;
}

void chunk_render(chunk_t* chunk, int offsetX, int offsetY)
{
    for (int i = 0; i < CHUNK_SIZE; i++)
        for (int j = 0; j < CHUNK_SIZE; j++)
            tile_draw(chunk->tiles[i][j], offsetX + i * TILE_SIZE, offsetY + j * TILE_SIZE);
}