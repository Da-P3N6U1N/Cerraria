#include "camera.h"

camera_t camera_make(float x, float y)
{
    Camera2D camera = { 0 };
    camera.target = (Vector2){ x, y };
    camera.offset = (Vector2){ WINDOW_WIDTH / 2.0f, WINDOW_HEIGHT / 2.0f };
    camera.rotation = 0.0f;
    camera.zoom = 1.5f;

    camera_t c; c.camera = camera;

    return c;
}


void camera_set_pos(camera_t *c, float x, float y)
{
    c->camera.target = (Vector2){ x, y };
}

void camera_change_pos(camera_t *c, float deltaX, float deltaY)
{
    c->camera.target = ((Vector2){ c->camera.target.x + deltaX, c->camera.target.y + deltaY });
}

float camera_get_x(camera_t *c)
{
    return c->camera.target.x;
}

float camera_get_y(camera_t *c)
{
    return c->camera.target.y;
}