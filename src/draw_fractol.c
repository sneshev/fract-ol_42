#include "fractol.h"

#define TEMP 2
#define WHITE 0x00FFFFFF
#define RED   0x00FF0000
#define GREEN 0x0000FF00


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

void calculate_fractol()
{

}

int draw_fractol(t_data *data)
{
    print_data(data);

    for (int y = 0; y < 2160 / 3; y++)
    {
        for (int x = 0; x < 3840; x++)
            put_image_pixel(data, x, y, 0x00FFFFFF);
    }
    for (int y = 2160 / 3; y < 2160 * 2 / 3; y++)
    {
        for (int x = 0; x < 3840; x++)
            put_image_pixel(data, x, y, 0x0000FF00);
    }
    for (int y = 2160 * 2 / 3; y < 2160; y++)
    {
        for (int x = 0; x < 3840; x++)
            put_image_pixel(data, x, y, 0x00FF0000);
    }
    mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}