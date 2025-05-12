#include "fractol.h"

void print_coordinates(t_data *data)
{
    printf("type: ");
    if (data->type == MANDELBROT)
        printf("mandelbrot\n");
    else if (data->type == JULIA)
        printf("julia\n");
    if (data->z)
    {
        printf("z_real -> %f\n", data->z[X]);
        printf("z_imag -> %f\n", data->z[Y]);
    }
    if (data->c)
    {
        printf("c_real -> %f\n", data->c[X]);
        printf("c_imag -> %f\n", data->c[Y]);    
    }
}


void print_data(t_data *data)
{
    print_coordinates(data);
    printf("\n");
    printf("mlx: ");
    if (data->mlx)
        printf("%p\n", data->mlx);
    else
        printf("NULL\n");
    printf("win: ");
    if (data->win)
        printf("%p\n", data->win);
    else
        printf("NULL\n");
    printf("img: ");
    if (data->img)
        printf("%p\n", data->img);
    else
        printf("NULL\n");
    printf("\n");
    printf("img_info: \n");
    printf("addr: ");
    if (data->img_info && data->img_info->addr)
        printf("%p\n", data->img_info->addr);
    else
        printf("NULL\n");
    printf("bpp: ");
    if (data->img_info && data->img_info->bpp)
        printf("%d\n", data->img_info->bpp);
    else
        printf("NULL\n");
    printf("line length: ");
    if (data->img_info && data->img_info->line_length)
        printf("%d\n", data->img_info->line_length);
    else
        printf("NULL\n");
    printf("endian: ");
    if (data->img_info)
        printf("%d\n", data->img_info->endian);
    printf("\n\n");
}
