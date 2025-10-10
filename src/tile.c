#include "constants.h"
#include <raylib.h>
#include "tileset.h"
#include "tile.h"

static tile_data_t global_tile_types[4];


void init_tile_types()
{
    global_tile_types[TILE_AIR].name = "Air";
    global_tile_types[TILE_AIR].solid = false;
    
    global_tile_types[TILE_DIRT].name = "Dirt";
    global_tile_types[TILE_DIRT].solid = true;
    global_tile_types[TILE_DIRT].texture_id = 0;

    global_tile_types[TILE_STONE].name = "Stone";
    global_tile_types[TILE_STONE].solid = true;
    global_tile_types[TILE_STONE].texture_id = 1;

    global_tile_types[TILE_GRASS].name = "Grass";
    global_tile_types[TILE_GRASS].solid = true;
    global_tile_types[TILE_GRASS].texture_id = 2;

    return;
}

tile_t tile_create(tile_id_t id)
{
    tile_t t;
    t.id = id;
    return t;
}

void tile_draw(tile_t tile, int x, int y)
{
    if (global_tile_types[tile.id].solid == false)
        return;
    
    tileset_draw_id(global_tile_types[tile.id].texture_id, x, y);
}