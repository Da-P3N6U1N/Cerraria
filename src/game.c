#include <stdlib.h>
#include <time.h>
#include "game.h"
#include "constants.h"
#include "tile.h"
#include <raylib.h>
#include "tileset.h"

tile_t tiles[TILE_X_AMOUNT][TILE_Y_AMOUNT];

void game_init()
{
    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_TITLE);  
    SetTargetFPS(60); 

    srand(time(NULL));

    init_tile_types();
    tileset_create("res/tileset.png", 3);

    for (int i = 0; i < TILE_X_AMOUNT; i++)
    {
        for (int j = 0; j < TILE_Y_AMOUNT; j++)
        {
            tiles[i][j] = tile_create(rand() % 4);
        }
    }
}

bool game_update(double deltaTime)
{
    if (WindowShouldClose())
        return false;



    return true;
}

void game_render()
{
    BeginDrawing();

    ClearBackground(RAYWHITE);

    for (int i = 0; i < TILE_X_AMOUNT; i++)
    {
        for (int j = 0; j < TILE_Y_AMOUNT; j++)
        {
            tile_draw(tiles[i][j], i, j);
        }
    }

    EndDrawing();
}

void game_free()
{
    CloseWindow();
}

void game_run()
{
    game_init();

    while (game_update(GetFrameTime()))
        game_render();

    game_free();
}

