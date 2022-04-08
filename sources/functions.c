/*
** EPITECH PROJECT, 2021
** function
** File description:
** function
*/

#include "../include/my.h"
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/types.h>
#include "../include/bsq.h"

int **mem_alloc_2d_array_int(sqr_find_t *structure)
{
    int **mem_array;
    int i = 0;

    mem_array = malloc(sizeof(int *) * structure->rows + 1);
    for (i = 0; i < structure->rows; i++)
        mem_array[i] = malloc(sizeof(int) * structure->cols + 1);
    return mem_array;
}

int **load_2d_arr_from_int(char const *filepath, sqr_find_t *structure)
{
    char *buffer = load_file_in_mem(filepath);
    int **array = mem_alloc_2d_array_int(structure);
    int i;
    int a;
    int count;

    for (count = 0; buffer[count] != '\n'; count++);
    count = count + 1;
    for (i = 0; i < structure->rows; i++) {
        for (a = 0; a < structure->cols; a++) {
            if (buffer[count] == '.')
                array[i][a] = 1;
            else if (buffer[count] == 'o')
                array[i][a] = 0;
            count = count + 1;
        }
        count++;
    }
    return array;
}

int verif(int a, int b, int c)
{
    if (b <= a && b <= c)
        return b;
    else if (c <= a && c <= b)
        return c;
    else
        return a;
    return 0;
}

int pos_a_b(int x, int y, int **tableau)
{
    int a = 0;

    if (x != 0 || y != 0)
        a = verif(tableau[y][x - 1], tableau[y - 1][x - 1], tableau[y - 1][x]);
    return a;
}

int **find_biggest_square(sqr_find_t *structure, int **array)
{
    int a = 0;
    int b = 0;

    for (a = 1; a != structure->rows; a++) {
        for (b = 1; b != structure->cols; b++) {
            if (array[a][b] != 0)
                array[a][b] += pos_a_b(b, a, array);
        }
    }
    return (array);
}
