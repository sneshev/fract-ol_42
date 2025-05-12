#include "fractol.h"


bool is_num(char c)
{
    if (c  < '0')
        return (false);
    if (c > '9')
        return (false);
    return (true);
}

bool is_valid_input(char *str)
{
    int i;

    if (*str == '-')
        str++;
    if (*str == '0' || *str == '1')
    {
        str++;
        if (*str == '.')
        {
            str++;
            i = 0;
            while (str[i] && is_num(str[i]) && i < 16)
                i++;
            if (!str[i])
                return (true);
        }
    }
    else if (*str == '2')
    {
        str++;
        if (*str == '\0'
            || *str == '.' && *(str + 1) == '0' && !(*(str + 2)))
            return (true);
    }
    return (false);
}

int init_window_and_mlx(t_data *data)
{
    data->mlx = (void *)mlx_init();
    if (!data->mlx)
        return (0);
    data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "Fract-ol");
    if (!data->win)
        return (0);
    data->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
    if (!data->img)
        return (0);
    return 1;
}

t_data *init_fract(int argc, char *argv[])
{
    if (argc == 2)
    {
        if (ft_strncmp(argv[1], "julia", 6) == 0)
            return(init_julia(NULL, NULL));
        else if (ft_strncmp(argv[1], "mandelbrot", 12) == 0)
            return (init_mandelbrot());
    }
    else if (argc == 4 && is_valid_input(argv[2]) && is_valid_input(argv[3]))
    {
        if (ft_strncmp(argv[1], "julia", 6) == 0)
            return(init_julia(argv[2], argv[3]));
    }
    return (printf("to run: ./fractol *set* \n"), NULL);
}
