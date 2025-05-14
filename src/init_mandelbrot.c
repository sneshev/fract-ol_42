#include "fractol.h"
#include "../minilibx/mlx.h"

void adjust_fractal_bounds(t_data *data)
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

static t_data *init_points(t_data *data)
{
    data->type = MANDELBROT;
    // data->c = NULL;
    // data->z = (double *)malloc(2 * sizeof(double));    
    // if (!data->z)
        // return (free(data), NULL);    
    // data->c = (double *)malloc(2 * sizeof(double));    
    // if (!data->c)
    //     return (free(data->z), free(data), NULL);    

    data->z[X] = 0.0; //idk what to initialize
    data->z[Y] = 0.0; //idk what to initialize
    data->c[X] = 0.0; //idk what to initialize
    data->c[Y] = 0.0; //idk what to initialize

    adjust_fractal_bounds(data);

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
