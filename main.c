/*
** EPITECH PROJECT, 2021
** main
** File description:
** main
*/

#include"include/my.h"
#include <stdlib.h>

int main (int ac, char **av)
{
    if (ac != 2)
        return 84;
    return bsq(av[1]);
}
