#include "fractol.h"


int draw_fractol(t_data *data)
{
    if (data->type == MANDELBROT)
        return (draw_mandelbrot(data));
    return -1;
}