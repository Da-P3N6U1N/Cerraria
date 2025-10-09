#include <stdlib.h>
#include <time.h>
#include "game.h"
#include "constants.h"
#include "tile.h"
#include <raylib.h>
#include "tileset.h"
#include "camera.h"
#include "noise.h"
#include "chunk_map.h"
#include <stdio.h>

camera_t camera;
chunk_map_t map;

value_noise_t noise, noise2;

const int SEED = 67;

void game_init()
{
    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_TITLE);  
    SetTargetFPS(60); 

    init_tile_types();
    tileset_create("res/tileset.png", 3);
    camera = camera_make(TILE_SIZE * (TILE_X_AMOUNT / 2), (WINDOW_HEIGHT / 2));
    noise = value_noise_create(TILE_X_AMOUNT, smoothstep, SEED);
    noise2 = value_noise_create(TILE_X_AMOUNT, smoothstep, SEED + 100);

    map = chunk_map_create((TILE_X_AMOUNT + CHUNK_SIZE - 1) / CHUNK_SIZE, (TILE_Y_AMOUNT + CHUNK_SIZE - 1) / CHUNK_SIZE);

    for (int i = 0; i < TILE_X_AMOUNT; i++)
    {
        int y = (int)value_noise_advanced_eval(&noise, i, 0.1f, 10) + TILE_Y_AMOUNT / 3;

        for (int j = TILE_Y_AMOUNT - 1; j > y; j--)
            chunk_map_set_tile(&map, i, j, tile_create(TILE_DIRT));

        chunk_map_set_tile(&map, i, y, tile_create(TILE_GRASS));
    }
}

bool game_update(double deltaTime)
{
    (void)deltaTime;

    if (WindowShouldClose())
        return false;

    camera_change_pos(&camera, ((IsKeyDown(KEY_D) - IsKeyDown(KEY_A)) * CAMERA_SPEED), ((IsKeyDown(KEY_S) - IsKeyDown(KEY_W)) * CAMERA_SPEED));

    printf("%f %f\n", camera_get_x(&camera), camera_get_y(&camera));

    return true;
}

void game_render()
{
    BeginDrawing();

    ClearBackground(SKYBLUE);

    BeginMode2D(camera.camera);

    chunk_map_render(&map, 0, 0, &camera, 3, 2);
    
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

