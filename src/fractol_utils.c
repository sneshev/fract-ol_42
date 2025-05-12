#include "fractol.h"

void free_data(t_data *data)
{
    if (data->z)
        free(data->z);
    if (data->c)
        free(data->c);
    if (data->img)
        mlx_destroy_image(data->mlx, data->img);
    if (data->win)
        mlx_destroy_window(data->mlx, data->win);
    if (data->mlx)
    {
        mlx_destroy_display(data->mlx);
        free(data->mlx);
    }
    if (data)
        free(data);
}

static double atod_fractional(char *str)
{
    double fraction = 0.0;
    double divisor = 10.0;

    if (*str == '.')
    {
        str++;
        while (*str && *str >= '0' && *str <= '9')
        {
            fraction += (*str - '0') / divisor;
            divisor *= 10.0;
            str++;
        }
    }
    return (fraction);
}

double atod(char *str)
{
    double nb;
    int sign;

    nb = 0.0;
    sign = 1;

    if (*str == '-')
    {
        sign = -1;
        str++;
    }
    while (*str && *str != '.')
    {
        if (*str >= '0' && *str <= '9')
        {
            nb = nb * 10 + (*str - '0');
        }
        else
        {
            return 0.0;
        }
        str++;
    }
    return sign * (nb + atod_fractional(str));
}

