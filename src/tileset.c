#include "tileset.h"
#include "raylib.h"
#include "constants.h"

tileset_t tileset;
static int tileset_columns = 0;     // number of tiles per row

void tileset_create(const char* path, int tile_width)
{
    tileset.texture = LoadTexture(path);
    tileset.tile_width = tile_width;
    tileset_columns = tile_width;
}

void tileset_draw_id(int texture_id, float x, float y)
{
    int srcX = (texture_id % tileset_columns) * TILE_SIZE;
    int srcY = (texture_id / tileset_columns) * TILE_SIZE;

    Rectangle source = {
        .x = (float)srcX,
        .y = (float)srcY,
        .width = (float)TILE_SIZE,
        .height = (float)TILE_SIZE
    };

    Vector2 target = {
        .x = x,
        .y = y
    };

    DrawTextureRec(tileset.texture, source, target, WHITE);
}

void tileset_free()
{
    UnloadTexture(tileset.texture);
}