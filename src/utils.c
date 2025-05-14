/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sneshev <sneshev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 14:32:27 by sneshev           #+#    #+#             */
/*   Updated: 2025/05/14 15:44:07 by sneshev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	adjust_fractal_bounds(t_data *data)
{
	double	aspect_ratio;
	double	range[2];
	double	center[2];

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

void	free_data(t_data *data)
{
	if (data->img_info)
		free(data->img_info);
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

int	draw_fractol(t_data *data)
{
	if (data->type == MANDELBROT)
		return (draw_mandelbrot(data));
	if (data->type == JULIA)
		return (draw_julia(data));
	return (-1);

}

t_data	*explanational_message(void)
{
	printf("write the explanational message haha\n");
	printf("to run: ./fracol ..");
	return (NULL);
}

static double	atod_fractional(char *str)
{
	double	fraction;
	double	divisor;

	fraction = 0.0;
	divisor = 10.0;
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

double	atod(char *str)
{
	double	nb;
	int		sign;

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
			return (0.0);
		}
		str++;
	}
	return (sign * (nb + atod_fractional(str)));
}
