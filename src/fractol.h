#ifndef FRACTOL_H
# define FRACTOL_H

# include "../minilibx/mlx.h"
# include "../minilibx/mlx_int.h"
# include "../libft/libft.h"
# include <stdbool.h>
# include <math.h>



# define MANDELBROT 0
# define JULIA 1

# define ITERATIONS 500
# define COLOR_SET 0

# define HEIGHT 1000
# define WIDTH 1000

# define ZOOM 0.7
# define MOVE 0.05

# define MIN_REAL -2.0
# define MAX_REAL  1.0
# define MIN_IMAG -1.5
# define MAX_IMAG  1.5

# define X 0
# define Y 1


typedef struct s_img_info
{
    int     bpp;
    int     line_length;
    int     endian;
    char    *addr;
}   t_img_info;


typedef struct s_data
{
    void   *mlx;
    void   *win;
    void   *img;
    t_img_info*img_info;


    int            color_set;
    int            type;
    double         z[2];
    double         c[2];
    double         range_min[2];
    double         range_max[2];
}   t_data;


// initialize
t_data  *init_data(int argc, char *argv[]);
int     init_minilibx(t_data *data);

//fractols
int     draw_fractol(t_data *data);
void    mlx_event_handle(t_data *data);
int     find_colors(int iterations, int color_set);

//mandelbrot
t_data  *init_mandelbrot(void);
int     draw_mandelbrot(t_data *data);

//julia
t_data *init_julia(char *c_real, char *c_imag);


// utils
void adjust_fractal_bounds(t_data *data);
t_data *explanational_message(void);
void    free_data(t_data *data);
double  atod(char *str);

//helpers
void    print_coordinates(t_data *data);
void    print_data(t_data *data);


#endif