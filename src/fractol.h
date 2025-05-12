#ifndef FRACTOL_H
# define FRACTOL_H

# include "../minilibx/mlx.h"
# include "../minilibx/mlx_int.h"
# include "../libft/libft.h"
# include <stdbool.h>
# include <math.h>



# define MANDELBROT 0
# define JULIA 1

# define X 0
# define Y 1

# define ITERATIONS 500
# define HEIGHT 500
# define WIDTH 500


typedef struct s_data
{
    void   *mlx;
    void   *win;
    void   *img;

    int            type;
    double         *z;
    double         *c;
}   t_data;


// initialize
t_data *init_fract_and_mlx_data(int argc, char *argv[]);
t_data *init_mandelbrot(void);
t_data *init_julia(char *c_real, char *c_imag);

// utils
void free_data(t_data *data);
double atod(char *str);

//helpers
void print_coordinates(t_data *data);






#endif