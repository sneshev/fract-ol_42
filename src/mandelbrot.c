#include "fractol.h"
#include "../minilibx/mlx.h"

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

int draw_mandelbrot(t_data *data)
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
            pix_color = find_colors(calculate_point(c), data->color_set);
            put_image_pixel(data, x, y, pix_color);
            x++;
        }
        y++;
        x = 0;
    }
    mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
    return (1);
}


static void adjust_fractal_bounds(t_data *data)
{
    double aspect_ratio;
    double range[2];
    double center[2];

    aspect_ratio = (double)WIDTH / (double)HEIGHT;
    center[X] = (MAX_REAL + MIN_REAL) / 2.0;
    center[Y] = (MAX_IMAG + MIN_IMAG) / 2.0;
    range[X] = MAX_REAL - MIN_REAL;
    range[Y] = MAX_IMAG - MIN_IMAG;
    if (WIDTH > HEIGHT)
        range[X] = range[Y] * aspect_ratio;
    else if (WIDTH < HEIGHT)
        range[Y] = range[X] / aspect_ratio;
    
    data->range_min[X] = center[X] - range[X] / 2.0;
    data->range_max[X] = center[X] + range[X] / 2.0;
    data->range_min[Y] = center[Y] - range[Y] / 2.0;
    data->range_max[Y] = center[Y] + range[Y] / 2.0;
}

t_data *init_mandelbrot(void)
{
    t_data *data;

    data = (t_data *)malloc(sizeof (t_data));
    if (!data)
        return (NULL);
    data->type = MANDELBROT;
    data->color_set = 0;
    data->z[X] = 0.0; //idk what to initialize
    data->z[Y] = 0.0; //idk what to initialize
    data->c[X] = 0.0; //idk what to initialize
    data->c[Y] = 0.0; //idk what to initialize
    adjust_fractal_bounds(data);
    return (data);
}
