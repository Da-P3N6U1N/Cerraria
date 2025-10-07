#pragma once

#include <stdbool.h>

void game_run();

void game_init();
bool game_update(double deltaTime);
void game_render();
void game_free();