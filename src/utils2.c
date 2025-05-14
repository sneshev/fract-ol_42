/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sneshev <sneshev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 17:34:57 by sneshev           #+#    #+#             */
/*   Updated: 2025/05/14 17:34:58 by sneshev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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

t_data	*explanational_message(void)
{
	printf("write the explanational message haha\n");
	printf("to run: ./fracol ..");
	return (NULL);
}
