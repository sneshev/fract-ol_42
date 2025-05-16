/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sneshev <sneshev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 14:09:59 by sneshev           #+#    #+#             */
/*   Updated: 2025/05/14 18:45:03 by sneshev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdint.h>
#include <math.h>

#define BASIC 0
#define TROPICAL 1

#define RED 0xFF0000
#define BLACK 0x000000
#define WHITE 0x00FFFFFF
#define GREEN 0x0000FF00

int	colors_tropical(int iterations, int max_iterations)
{
	if (iterations == max_iterations)
		return (0x000000);
	if (iterations < 6)
		return (RED + iterations * 99);

	return (RED + iterations * 50);
}

int	colors_test(int iterations, int max_iterations)
{
	if (iterations < 6)
		return (BLACK);
	if (iterations == max_iterations)
		return (0x000000);
	return (GREEN + iterations * 50);
}

int	colors_basic(int iterations, int max_iterations)
{
	if (iterations == max_iterations)
		return (BLACK);
	return (WHITE);
}

// uint32_t bro_color(int i)
// {
//     // Frequency for color changes
//     double frequency = 0.30;

//     // Phase shifts for R, G, B
//     double phase_r = 0.0;
//     double phase_g = 2.0 * M_PI / 0.2;
//     double phase_b = 4.0 * M_PI / 2.2;

//     // Calculate the RGB values using sine waves
//     uint8_t r = (uint8_t)(127.5 * (1.0 + sin(frequency * i + phase_r)));
//     uint8_t g = (uint8_t)(127.5 * (1.0 + sin(frequency * i + phase_g)));
//     uint8_t b = (uint8_t)(127.5 * (1.0 + sin(frequency * i + phase_b)));

//     // Pack the RGB values into a 32-bit integer (ARGB format)
//     uint32_t color = ((uint32_t)r << 24) | ((uint
//32_t)g << 16) | ((uint32_t)b << 8) | 0xFF;

//     return color;
// }

int	find_colors(int iterations, t_data *data)
{
	int max_iterations = data->max_iterations;
	int color_set = data->color_set;
	if (color_set == BASIC)
		return (colors_basic(iterations, max_iterations));
	if (color_set == TROPICAL)
		return (colors_tropical(iterations, max_iterations));
	return (colors_test(iterations, max_iterations));
}
