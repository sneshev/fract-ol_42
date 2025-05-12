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

    data = init_fract_and_mlx_data(argc, argv);
    if (!data)
        return (printf("invalid data\n"), 1);
    print_coordinates(data);


    free_data(data);
}