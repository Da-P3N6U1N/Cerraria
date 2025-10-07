#include "tileset.h"
#include "raylib.h"
#include "constants.h"

tileset_t tileset;

void tileset_create(const char* path, int tile_width)
{
    tileset.texture = LoadTexture(path);
    tileset.tile_width = tile_width;
}

void tileset_draw_id(int id, int x, int y)
{
    int srcX = (id % tileset.tile_width) * TILE_SIZE;
    int srcY = (id / tileset.tile_width) * TILE_SIZE;
    
    DrawTextureRec(
        tileset.texture, 
        (Rectangle){srcX, srcY, TILE_SIZE, TILE_SIZE}, 
        (Vector2){x * TILE_SIZE, y * TILE_SIZE}, 
        WHITE
    );
}
