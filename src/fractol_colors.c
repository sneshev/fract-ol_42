#include "fractol.h"

#define BASIC 0
#define TROPICAL 1

#define RED 0xFF0000
#define BLACK 0x000000
#define WHITE 0x00FFFFFF
#define GREEN 0x0000FF00

int colors_tropical(int iterations)
{
    if (++iterations < 6)
        return RED + iterations * 99;
    if (iterations == ITERATIONS)
        return 0x000000;
    return RED + iterations * 50;
}

int colors_test(int iterations)
{
    if (iterations < 6)
        return GREEN + iterations * 99;
    if (iterations == ITERATIONS)
        return 0x000000;
    return GREEN + iterations * 50;
}

int colors_basic(int iterations)
{
	if (iterations == ITERATIONS)
		return (BLACK);
	return (WHITE);
}

int find_colors(int iterations, int color_set)
{
	if (color_set == BASIC)
		return (colors_basic(iterations));
	if (color_set == TROPICAL)
	    return (colors_tropical(iterations));
	if (color_set == 2)
		return (colors_test(iterations));
}