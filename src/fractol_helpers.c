#include "fractol.h"

void print_coordinates(t_data *data)
{
    printf("type: ");
    if (data->type == MANDELBROT)
        printf("mandelbrot\n");
    else
        printf("julia\n");
    printf("z_real -> %f\n", data->z[X]);
    printf("z_imag -> %f\n", data->z[Y]);
    printf("c_real -> %f\n", data->c[X]);
    printf("c_imag -> %f\n", data->c[Y]);
}