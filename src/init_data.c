#include "fractol.h"

t_data *init_julia(char *ala, char *bala)
{
    t_data *data;

    data = (t_data *)malloc(sizeof (t_data));
    if (!data)
        return (NULL);

    return (data);
}

t_data *init_mandelbrot(char *ala, char *bala)
{
    t_data *data;

    data = (t_data *)malloc(sizeof (t_data));
    if (!data)
        return (NULL);

    return (data);

}

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
    if (*str == '-')
        str++;
    if (*str == '0' || *str == '1')
    {
        str++;
        if (*str == '.')
        {
            str++;
            if (is_num(*str) && *(str + 1) == '\0')
                return (true);
            if (is_num(*str) && is_num(*(str + 1)) && *(str + 2) == '\0')
                return (true);
        }
    }
    else if (*str == '2')
    {
        str++;
        if (*str == '\0')
            return (true);
        if (*str == '.' && *(str + 1) == '0' && !(*(str + 2)))
            return (true);
    }
    return (false);
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
    else if (argc == 4 && is_valid_input(argv[2]) && is_valid_input(argv[3]))
    {
        if (ft_strncmp(argv[1], "julia", 6) == 0)
            return(init_julia(argv[2], argv[3]));
        else if (ft_strncmp(argv[1], "mandelbrot", 12) == 0)
            return (init_mandelbrot(argv[2], argv[3]));
    }
    return (printf("to run: ./fractol *set* \n"), NULL);
}
