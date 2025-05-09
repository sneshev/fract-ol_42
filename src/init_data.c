#include "fractol.h"

t_data *init_julia(char *ala, char *bala)
{
    t_data *data;

    data = (t_data *)malloc(sizeof (t_data));
    if (!data)
        return (NULL);
        
}

t_data *init_mandelbrot(char *ala, char *bala)
{
    t_data *data;

    data = (t_data *)malloc(sizeof (t_data));
    if (!data)
        return (NULL);

}


t_data *init_data(int argc, char *argv[])
{
    if (argc == 2)
    {
        if (ft_strncmp(argv[1], "julia", 6) == 0)
            return(init_julia(NULL, NULL));
        else if (ft_strncmp(argv[1], "mandelbrot", 12) == 0)
            return (init_mandelbrot(NULL, NULL));
    }
    else if (argc == 4)
    {
        if (ft_strncmp(argv[1], "julia", 6) == 0)
            return(init_julia(argv[2], argv[3]));
        else if (ft_strncmp(argv[1], "mandelbrot", 12) == 0)
            return (init_mandelbrot(argv[2], argv[3]));
    }
    return (printf("to run: ./fractol *set* "), NULL);
}
