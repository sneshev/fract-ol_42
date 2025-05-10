#include "fractol.h"

double fractional(char *str)
{
    double fraction = 0.0;
    double divisor = 10.0;

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

double atod(char *str)
{
    double nb;
    int sign;

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
            return 0.0;
        }
        str++;
    }
    return sign * (nb + fractional(str));
}
