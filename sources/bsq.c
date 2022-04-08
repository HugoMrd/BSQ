/*
** EPITECH PROJECT, 2021
** bsq
** File description:
** bsq
*/

#include "../include/my.h"
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/types.h>
#include "../include/bsq.h"

char *load_file_in_mem(char const *filepath)
{
    int a;
    int size;
    char *buffer;
    struct stat buff;

    stat(filepath, &buff);
    size = buff.st_size;
    buffer = malloc(sizeof(char) * (size + 1));
    buffer[size] = '\0';
    a = open(filepath, O_RDONLY);
    if (a == -1)
        return NULL;
    read(a, buffer, size);
    close(a);
    return buffer;
}

char **load_2d_arr_from_file(char const *filepath, sqr_find_t *structure)
{
    char *buffer = load_file_in_mem(filepath);
    char **array = mem_alloc_2d_array(structure);
    int i = 0;
    int a = 0;
    int count = 0;

    for (count = 0; buffer[count] != '\n'; count++);
    count = count + 1;
    if (buffer[count] != 'o' || buffer[count] != '.')
        for (i = 0; i < structure->rows; i++) {
            for (a = 0; a < structure->cols; a++) {
                array[i][a] = buffer[count];
                count++;
            }
            count++;
        }
    return array;
}

void functions_bsq(char const *filepath, sqr_find_t *structure)
{
    char **tableau_char = NULL;
    int **z = NULL;

    tableau_char = load_2d_arr_from_file(filepath, structure);
    z = load_2d_arr_from_int(filepath, structure);
    z = find_biggest_square(structure, z);
    big_nbr2(structure, z);
    tableau_char = disp_square(structure, tableau_char);
    for (int y = 0; y < structure->rows; y++) {
        my_putstr(tableau_char[y]);
        if (structure->rows != 1)
            my_putchar('\n');
    }
}

int bsq(char const *filepath)
{
    sqr_find_t structure;
    char *buffer = load_file_in_mem(filepath);
    int size = 0;
    int count = 0;
    struct stat buff;

    stat(filepath, &buff);
    size = buff.st_size;
    if (size < 1)
        return 84;
    if (buffer == NULL)
        return 84;
    if (my_check_buffer(buffer) == 84)
        return 84;
    structure.rows = fs_get_number_from_first_line(filepath);
    for (count = 0; buffer[count] != '\n'; count++);
    structure.cols = (size - count) / structure.rows;
    structure.cols = structure.cols - 1;
    functions_bsq(filepath, &structure);
    return 0;
}
