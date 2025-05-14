#include "fractol.h"

#define TEMP 2

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
    while (count < ITERATIONS)
    {
        z[TEMP] = z[X] * z[X] - z[Y] * z[Y] + c[X];
        z[Y] = 2 * z[X] * z[Y] + c[Y];
        z[X] = z[TEMP];
        if (z[X] * z[X] + z[Y] * z[Y] >= 4)
            return (count);
        count++;
    }
    
    return (count);
}


int draw_fractol_mandelbrot(t_data *data)
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
            pix_color = find_colors(calculate_point(c), 0);
            put_image_pixel(data, x, y, pix_color);
            x++;
        }
        y++;
        x = 0;
    }

    mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
    return (1);
}