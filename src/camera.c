#include "camera.h"

camera_t camera_make(float x, float y, float border_left, float border_right, float border_top, float border_bottom)
{
    Camera2D camera = { 0 };
    camera.offset = (Vector2){ WINDOW_WIDTH / 2.0f, WINDOW_HEIGHT / 2.0f };
    camera.rotation = 0.0f;
    camera.zoom = 1.5f;

    camera_t c; c.camera = camera;
    
    c.border_left = border_left;
    c.border_right = border_right;
    c.border_top = border_top;
    c.border_bottom = border_bottom;
    
    
    camera_set_pos(&c, x, y);
    return c;
}

void camera_set_pos(camera_t *c, float x, float y)
{
    c->camera.target = (Vector2){ x, y };

    if (c->camera.target.x < c->border_left) c->camera.target.x = c->border_left;
    if (c->camera.target.x > c->border_right) c->camera.target.x = c->border_right;
    if (c->camera.target.y < c->border_top) c->camera.target.y = c->border_top;
    if (c->camera.target.y > c->border_bottom) c->camera.target.y = c->border_bottom;
}

void camera_change_pos(camera_t *c, float deltaX, float deltaY)
{
    camera_set_pos(c, c->camera.target.x + deltaX, c->camera.target.y + deltaY);
}

float camera_get_x(camera_t *c)
{
    return c->camera.target.x;
}

float camera_get_y(camera_t *c)
{
    return c->camera.target.y;
}