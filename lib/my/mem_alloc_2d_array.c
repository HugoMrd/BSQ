/*
** EPITECH PROJECT, 2021
** frr
** File description:
** frrr
*/

#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/types.h>
#include "../../include/bsq.h"

char **mem_alloc_2d_array(sqr_find_t *structure)
{
    char **mem_rows;

    mem_rows = malloc(sizeof(char*) * structure->rows + 1);
    for (int i = 0; i < structure->rows; i++)
        mem_rows[i] = malloc(sizeof(char) * structure->cols + 1);
    return mem_rows;
}
