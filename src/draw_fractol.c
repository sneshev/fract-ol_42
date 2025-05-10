#include "fractol.h"


int calculate_point(double *z, double *c)
{
    double tempZx;
    int count;

    count = 0;
    while (count <= ITERATIONS)
    {
        if (z[X] * z[X] + z[Y] * z[Y] >= 4)
            break ;
    }
}


void calculate_fractol()
{

}