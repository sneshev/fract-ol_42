#include "fractol.h"

#define TEMP 2

// z(n+1) = z^2 + c;
static int calculate_point(double *c) 
{
    double z[3];
    int count;

    count = 0;
    z[X] = 0;
    z[Y] = 0;
    while (count++ < ITERATIONS)
    {
        z[TEMP] = z[X] * z[X] - z[Y] * z[Y] + c[X];
        z[Y] = 2 * z[X] * z[Y] + c[Y];
        z[X] = z[TEMP];
        if (z[X] * z[X] + z[Y] * z[Y] >= 4)
            return (count);
    }
    return (count);
}


void calculate_fractol()
{

}