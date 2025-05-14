#include "fractol.h"

#define ESC 65307 
#define W 119
#define S 83
#define A 65
#define D 68
#define LEFT 65361
#define UP 65362
#define RIGHT 65363
#define DOWN 65364

#define MIN 0
#define MAX 1

void scroll(t_data *data, double zoom)
{
    double new_range[2];
    double center[2];

    center[X] = (data->range_max[X] + data->range_min[X]) / 2.0;
    center[Y] = (data->range_max[Y] + data->range_min[Y]) / 2.0;

    new_range[X] = (data->range_max[X] - data->range_min[X]) * zoom;
    new_range[Y] = (data->range_max[Y] - data->range_min[Y]) * zoom;
    
    data->range_min[X] = center[X] - new_range[X] / 2.0;
    data->range_max[X] = center[X] + new_range[X] / 2.0;
    data->range_min[Y] = center[Y] - new_range[Y] / 2.0;
    data->range_max[Y] = center[Y] + new_range[Y] / 2.0;

    draw_fractol_mandelbrot(data);
}

void move_center(t_data *data, double raw_mouse_x, double raw_mouse_y)
{
    double mouse_pos[2];
    double range[2][2];

    mouse_pos[X] = data->range_min[X] + (raw_mouse_x / (double)WIDTH) * (data->range_max[X] - data->range_min[X]);
    mouse_pos[Y] = data->range_min[Y] + (raw_mouse_y / (double)HEIGHT) * (data->range_max[Y] - data->range_min[Y]);

    range[MIN][X] = data->range_min[X];
    range[MAX][X] = data->range_max[X];
    range[MIN][Y] = data->range_min[Y];
    range[MAX][Y] = data->range_max[Y];

    data->range_min[X] = mouse_pos[X] - (range[MAX][X] - range[MIN][X]) / 2.0;
    data->range_max[X] = mouse_pos[X] + (range[MAX][X] - range[MIN][X]) / 2.0;
    data->range_min[Y] = mouse_pos[Y] - (range[MAX][Y] - range[MIN][Y]) / 2.0;
    data->range_max[Y] = mouse_pos[Y] + (range[MAX][Y] - range[MIN][Y]) / 2.0;

    draw_fractol_mandelbrot(data);
}

int set_mouse_events(int button, int mouse_x, int mouse_y, void *data_ptr)
{
    t_data *data;

    data = (t_data *)data_ptr;

    if (button == 1)
        move_center(data, mouse_x, mouse_y);
    
    if (button == 4) // zoom in
        scroll(data, ZOOM);

    if (button == 5) // zoom out
        scroll(data, 1 / ZOOM);
}

int set_keyhooks(int key, void *data_ptr)
{
    t_data *data;

    data = (t_data *)data_ptr;
    if (key == ESC)
    {
        write(1, "window closed\n", 15);
        free_data(data_ptr);
        exit(0);
    }
    if (key == W)
        scroll(data, ZOOM);
    if (key == S)
        scroll(data, 1 / ZOOM);
    if (key == UP)
        move_center(data, WIDTH / 2, HEIGHT / 2 - HEIGHT * MOVE);
    if (key == DOWN)
        move_center(data, WIDTH / 2, HEIGHT / 2 + HEIGHT * MOVE);
    if (key == LEFT)
        move_center(data, WIDTH / 2 - WIDTH * MOVE, HEIGHT / 2);
    if (key == RIGHT)
        move_center(data, WIDTH / 2 + WIDTH * MOVE, HEIGHT / 2);
}

void mlx_event_handle(t_data *data)
{
    mlx_hook(data->win, 4, 4, set_mouse_events, data);
    mlx_key_hook(data->win, set_keyhooks, data);
}