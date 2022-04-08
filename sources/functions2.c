/*
** EPITECH PROJECT, 2021
** functions2
** File description:
** functions2
*/

#include "../include/my.h"
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/types.h>
#include "../include/bsq.h"

sqr_find_t *big_nbr2(sqr_find_t *structure, int **array)
{
    int a;
    int b;

    structure->maximum = 0;
    for (a = structure->rows - 1; a >= 0; a--) {
        for (b = structure->cols - 1; b >= 0; b--) {
            if (array[a][b] >= structure->maximum) {
                structure->rows_biggest = a;
                structure->cols_biggest = b;
                structure->maximum = array[a][b];
            }
        }
    }
    return (structure);
}

char **disp_square(sqr_find_t *structure, char **array)
{
    int x;
    int y;

    x = structure->cols_biggest;
    y = structure->rows_biggest;
    for (int a = 0; a < structure->maximum; a++) {
        for (int b = 0; b < structure->maximum; b++) {
            array[y - a][x - b] = 'x';
        }
    }
    return (array);
}

int my_check_buffer(char *buffer)
{
    int i;

    for (i = 0; buffer[i] != '\n'; i++);
    i = i + 1;
    while (buffer[i] != '\0') {
        if (buffer[i] != '.' && buffer[i] != 'o' && buffer[i] != '\n')
            return (84);
        i++;
    }
    return 0;
}
