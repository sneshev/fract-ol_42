#include "fractol.h"

#define TEMP 2

#define WHITE 0x00FFFFFF
#define RED   0x00FF0000
#define GREEN 0x0000FF00

void put_image_pixel(t_data *data, int x, int y, int color)
{
    void *addr;
    int bpp;
    int line_length;

    addr = data->img_info->addr;
    bpp = data->img_info->bpp;
    line_length = data->img_info->line_length;

    int bytes_per_pixel = bpp / 8;
    char *pixel = addr + (y * line_length + x * bytes_per_pixel);
    *(unsigned int *)pixel = color;
}

// z(n+1) = z^2 + c;
static int calculate_point(double *c) 
{
    double z[3];
    int count;

    count = 0;
    z[X] = 0;
    z[Y] = 0;
    while (count++ < ITERATIONS)
    {
        z[TEMP] = z[X] * z[X] - z[Y] * z[Y] + c[X];
        z[Y] = 2 * z[X] * z[Y] + c[Y];
        z[X] = z[TEMP];
        if (z[X] * z[X] + z[Y] * z[Y] >= 4)
            return (count);
        }
    return (count);
}

int find_color(int iterations)
{
    if (iterations < 6)
        return 0xFF0000 + iterations * 99;
    if (iterations == ITERATIONS)
        return 0x000000;
    return 0xFF0000 + iterations * 50;
}

int draw_fractol(t_data *data) // MANDELBROT
{
    double step[2];
    double c[2];
    int pix_color;
    int x;
    int y;

    step[X] = (data->range_max[X] - data->range_min[X]) / WIDTH;
    step[Y] = (data->range_max[Y] - data->range_min[Y]) / HEIGHT;
    x = 0;
    y = 0;
    while (y < HEIGHT)
    {
        c[Y] = data->range_min[Y] + y * step[Y];
        while (x < WIDTH)
        {
            c[X] = data->range_min[X] + x * step[X];
            pix_color = find_color(calculate_point(c));
            put_image_pixel(data, x, y, pix_color);
            x++;
        }
        y++;
        x = 0;
    }

    mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
    return (1);
}