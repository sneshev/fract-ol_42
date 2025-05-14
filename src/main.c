#include "fractol.h"

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

    if (!draw_fractol_mandelbrot(data))
        return (free(data), 1);

    mlx_event_handle(data);
    mlx_loop(data->mlx);
}
