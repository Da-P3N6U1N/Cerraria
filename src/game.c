#include <stdlib.h>
#include <time.h>
#include "game.h"
#include "constants.h"
#include "tile.h"
#include <raylib.h>
#include "tileset.h"
#include "camera.h"
#include "noise.h"

tile_t tiles[TILE_X_AMOUNT][TILE_Y_AMOUNT];
camera_t camera;

value_noise_t noise;

void game_init()
{
    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_TITLE);  
    SetTargetFPS(60); 

    srand(time(NULL));

    init_tile_types();
    tileset_create("res/tileset.png", 3);
    camera = camera_make(TILE_SIZE * (TILE_X_AMOUNT / 2), -(WINDOW_HEIGHT / 3));
    noise = value_noise_create(TILE_X_AMOUNT, smoothstep, 0);

    for (int i = 0; i < TILE_X_AMOUNT; i++)
    {
        int y = (int)value_noise_advanced_eval(&noise, i, 0.05f, 10);

        for (int j = TILE_Y_AMOUNT - 1; j >= y; j--)
            tiles[i][j] = tile_create(TILE_DIRT);
    }
}

bool game_update(double deltaTime)
{
    (void)deltaTime;

    if (WindowShouldClose())
        return false;

    camera_change_pos(&camera, ((IsKeyDown(KEY_D) - IsKeyDown(KEY_A)) * CAMERA_SPEED), ((IsKeyDown(KEY_S) - IsKeyDown(KEY_W)) * CAMERA_SPEED));

    return true;
}

void game_render()
{
    BeginDrawing();

    ClearBackground(SKYBLUE);

    BeginMode2D(camera.camera);

    for (int i = 0; i < TILE_X_AMOUNT; i++)
    {
        for (int j = 0; j < TILE_Y_AMOUNT; j++)
        {
            tile_draw(tiles[i][j], i, j);
        }
    }
    
    EndMode2D();

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

