#include "fractol.h"
#include "../minilibx/mlx.h"

static t_data *init_points(t_data *data)
{
    data->type = MANDELBROT;
    data->z = NULL;
    // data->c = NULL;
    // data->z = (double *)malloc(2 * sizeof(double));    
    // if (!data->z)
        // return (free(data), NULL);    
    data->c = (double *)malloc(2 * sizeof(double));    
    if (!data->c)
        return (free(data->z), free(data), NULL);    

    // data->z[X] = 0.0; //idk what to initialize
    // data->z[Y] = 0.0; //idk what to initialize
    data->c[X] = 0.0; //idk what to initialize
    data->c[Y] = 0.0; //idk what to initialize

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
