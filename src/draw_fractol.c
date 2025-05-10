#include "fractol.h"

#define TEMP 2

// z(n+1) = z^2 + c;
static bool calculate_point(double *c) //will not be bool in future
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
        if (sqrt(z[X] * z[X] + z[Y] * z[Y]) >= 2)
            break ;
    }
    if (count == ITERATIONS) // NOT PART OF SET
        return (false);
    return (true);
}


void calculate_fractol()
{

}