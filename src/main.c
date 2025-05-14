#include "fractol.h"

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
    draw_fractol(data);
}

void move_center(t_data *data, double mouse_pos[2])
{
    data->range_min[X] = mouse_pos[X] - (data->range_max[X] - data->range_min[X]) / 2.0;
    data->range_max[X] = mouse_pos[X] + (data->range_max[X] - data->range_min[X]) / 2.0;
    data->range_min[Y] = mouse_pos[Y] - (data->range_max[Y] - data->range_min[Y]) / 2.0;
    data->range_max[Y] = mouse_pos[Y] + (data->range_max[Y] - data->range_min[Y]) / 2.0;
    draw_fractol(data);
}

int set_mouse_events(int button, int raw_mouse_x, int raw_mouse_y, void *data_ptr)
{
    t_data *data;
    double mouse_pos[2];

    data = (t_data *)data_ptr;
    mouse_pos[X] = data->range_min[X] + (raw_mouse_x / (double)WIDTH) * (data->range_max[X] - data->range_min[X]);
    mouse_pos[Y] = data->range_min[Y] + (raw_mouse_y / (double)HEIGHT) * (data->range_max[Y] - data->range_min[Y]);
    if (button == 1)
    {
        move_center(data, mouse_pos);
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
}

int main()
{
    int argc = 2;
    char *argv[argc];
    argv[0] = "./fractol";
    argv[1] = "mandelbrot";
    // argv[2] = "1.3";
    // argv[3] = "-2";

    t_data *data;

    data = init_fract(argc, argv);
    if (!data)
        return (printf("invalid data\n"), 1);
    
    if (!init_minilibx(data))
        return (free(data), 1);

    if (!draw_fractol(data))
        return (free(data), 1);

    mlx_event_handle(data);
    mlx_loop(data->mlx);
}
