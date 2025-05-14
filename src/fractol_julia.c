#include "fractol.h"

t_data *init_julia(char *c_real, char *c_imag)
{
	t_data *data;

	data = (t_data *)malloc(sizeof(t_data));
	if (!data)
		return (NULL);
	data->type = JULIA;
	data->color_set = 1;
	data->z[X] = 0.0;
	data->z[Y] = 0.0;
    if(c_real == NULL || c_imag == NULL)
    {
        data->c[X] = 1.23;
		data->c[Y] = -1.22;
    }
	else
	{
		data->c[X] = atod(c_real);
		data->c[Y] = atod(c_imag);
	}
	adjust_fractal_bounds(data);
	return (data);
}