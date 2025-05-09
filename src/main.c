#include "fractol.h"

int main(int argc, char *argv[])
{
    t_data *data;

    data = init_data(argc, argv);
    if (!data)
        return (printf("invalid data"), 1);
}