#include "fractol.h"

int main(int argc, char *argv[])
{
    // int argc = 4;
    // char *argv[argc];
    // argv[0] = "./fractol";
    // argv[1] = "julia";
    // argv[2] = "1.3";
    // argv[3] = "-2";

    t_data *data;

    data = init_data(argc, argv);
    if (!data)
        return (printf("invalid data\n"), 1);
}