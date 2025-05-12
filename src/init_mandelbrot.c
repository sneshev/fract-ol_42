#include "fractol.h"
#include "../minilibx/mlx.h"

static t_data *init_points(t_data *data)
{
    data->type = MANDELBROT;
    data->z = (double *)malloc(2 * sizeof(int));    
    if (!data->z)
        return (free(data), NULL);    
    data->c = (double *)malloc(2 * sizeof(int));    
    if (!data->c)
        return (free(data->z), free(data), NULL);    

    data->z[X] = 0.0; //idk what to initialize
    data->z[Y] = 0.0; //idk what to initialize
    data->c[X] = 0.0; //idk what to initialize
    data->c[Y] = 0.0; //idk what to initialize

    return (data);
}

static int init_window_and_mlx(t_data *data)
{
    data->mlx = (void *)mlx_init();
    if (!data->mlx)
        return (0);
    data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "Fract-ol");
    if (!data->win)
        return (0);
    data->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
    if (!data->img)
        return (0);
    return 1;
}

t_data *init_mandelbrot(void)
{
    t_data *data;

    data = (t_data *)malloc(sizeof (t_data));
    if (!data)
        return (NULL);
    if (!init_points(data))
        return (NULL);
    if (!init_window_and_mlx(data))
        return (NULL);
    return (data);
}
