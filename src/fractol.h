#ifndef FRACTOL_H
# define FRACTOL_H

// # include "../minilibx/mlx.h"
# include "../libft/libft.h"
#include <stdbool.h>



# define MANDELBROT 0
# define JULIA 1

# define X 0
# define Y 1


typedef struct data
{
    // mlx_t   *mlx;
    double         *z;
    double         *c;
}   t_data;


// initialize
t_data *init_data(int argc, char *argv[]);
t_data *init_mandelbrot(void);
t_data *init_julia(char *c_real, char *c_imag);

// utils
void free_data(t_data *data);
double atod(char *str);

//helpers
void print_coordinates(t_data *data);






#endif