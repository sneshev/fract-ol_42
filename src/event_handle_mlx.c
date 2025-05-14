#include "fractol.h"

#define ESC 65307 
#define UP 65362
#define DOWN 65364
#define LEFT 65361
#define RIGHT 65363
#define W 119
#define S 83
#define A 65
#define D 68


void scroll(t_data *data, double zoom);

void move(int direction)
{
    if (direction == UP)
        printf("move up\n"); fflush(NULL); // REMOVE PRINTF
    if (direction == DOWN)
        printf("move down\n"); fflush(NULL); // REMOVE PRINTF
    if (direction == LEFT)
        printf("move left\n"); fflush(NULL); // REMOVE PRINTF
    if (direction == RIGHT)
        printf("move right\n"); fflush(NULL); // REMOVE PRINTF
}

int set_keyhooks(int key, void *data_ptr)
{
    t_data *data;

    data = (t_data *)data_ptr;
    if (key >= LEFT && key <= DOWN)
        move(key);
    if (key == ESC)
    {
        printf ("window closed\n"); fflush(NULL); // REMOVE PRINTF
        free_data(data_ptr);
        exit(0);
    }
    if (key == W)
        scroll(data, ZOOM);
    if (key == S)
        scroll(data, 1 / ZOOM);
}

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
    draw_fractol(data);
}

void move_center(t_data *data, double raw_mouse_x, double raw_mouse_y)
{
    double mouse_pos[2];
    mouse_pos[X] = data->range_min[X] + (raw_mouse_x / (double)WIDTH) * (data->range_max[X] - data->range_min[X]);
    mouse_pos[Y] = data->range_min[Y] + (raw_mouse_y / (double)HEIGHT) * (data->range_max[Y] - data->range_min[Y]);

    data->range_min[X] = mouse_pos[X] - (data->range_max[X] - data->range_min[X]) / 2.0;
    data->range_max[X] = mouse_pos[X] + (data->range_max[X] - data->range_min[X]) / 2.0;
    data->range_min[Y] = mouse_pos[Y] - (data->range_max[Y] - data->range_min[Y]) / 2.0;
    data->range_max[Y] = mouse_pos[Y] + (data->range_max[Y] - data->range_min[Y]) / 2.0;
    draw_fractol(data);
}

int set_mouse_events(int button, int mouse_x, int mouse_y, void *data_ptr)
{
    t_data *data;

    data = (t_data *)data_ptr;
    if (button == 1)
    {
        move_center(data, mouse_x, mouse_y);
    }
    if (button == 4) // zoom in
    {
        scroll(data, ZOOM);
    }
    if (button == 5) // zoom out
    {
        scroll(data, 1 / ZOOM);
    }
}

void mlx_event_handle(t_data *data)
{
    mlx_hook(data->win, 4, 4, set_mouse_events, data);
    mlx_key_hook(data->win, set_keyhooks, data);
}