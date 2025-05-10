#include "fractol.h"

void print_coordinates(t_data *data)
{
    printf("z_real -> %f\n", data->z[X]);
    printf("z_imag -> %f\n", data->z[Y]);
    printf("c_real -> %f\n", data->c[X]);
    printf("c_imag -> %f\n", data->c[Y]);
}