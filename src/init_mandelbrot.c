#include "fractol.h"

static t_data *init_points(t_data *data)
{
    data->z = (double *)malloc(2 * sizeof(int));    
    if (!data->z)
        return (free(data), NULL);    
    data->c = (double *)malloc(2 * sizeof(int));    
    if (!data->c)
        return (free(data->z), free(data), NULL);    

    data->z[X] = 0.0;
    data->z[Y] = 0.0;

    return (data);
}

t_data *init_mandelbrot(void)
{
    t_data *data;

    data = (t_data *)malloc(sizeof (t_data));
    if (!data)
        return (NULL);
    if (!init_points(data))
        return (NULL);


    return (data);
}
