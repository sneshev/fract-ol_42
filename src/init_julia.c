#include "fractol.h"

static t_data *init_points(t_data *data, char *c_real, char *c_imag)
{
    data->z = (double *)malloc(2 * sizeof(int));    
    if (!data->z)
        return (free(data), NULL);    
    data->c = (double *)malloc(2 * sizeof(int));    
    if (!data->c)
        return (free(data->z), free(data), NULL);    

    data->z[X] = 0.0;
    data->z[Y] = 0.0;
    data->c[X] = 1.337;
    if (c_real)
        data->c[X] = atod(c_real);
    data->c[Y] = -0.42;
    if (c_imag)
        data->c[Y] = atod(c_imag);

    return (data);
}

t_data *init_julia(char *c_real, char *c_imag)
{
    t_data *data;

    data = (t_data *)malloc(sizeof (t_data));
    if (!data)
        return (NULL);
    if (!init_points(data, c_real, c_imag))
        return (NULL);

    return (data);
}