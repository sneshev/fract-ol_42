/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sneshev <sneshev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 14:29:11 by sneshev           #+#    #+#             */
/*   Updated: 2025/05/14 16:30:42 by sneshev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main()
{
	int argc = 2;
	char *argv[argc];
	argv[0] = "./fractol";
	argv[1] = "julia";
	t_data	*data;

	data = init_data(argc, argv);
	if (!data)
		return (printf("invalid data\n"), 1);
	if (!init_minilibx(data))
		return (free(data), 1);
	if (!draw_fractol(data))
		return (free(data), 1);
	mlx_event_handle(data);
	mlx_loop(data->mlx);
}
