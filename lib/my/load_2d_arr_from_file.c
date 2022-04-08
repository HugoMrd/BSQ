/*
** EPITECH PROJECT, 2021
** fdfd
** File description:
** dffdf
*/

#include "my.h"
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/types.h>

char **load_2d_arr_from_file(char const *filepath, int nb_rows ,int nb_cols)
{
    char *buffer = load_file_in_mem(filepath);
    char **array = mem_alloc_2d_array(nb_rows, nb_cols);
    int i;
    int a;
    int count;

    for (count = 0; buffer[count] != '\n'; count++);
    count = count + 1;
    for (i = 0; i < nb_rows; i++) {
        for (a = 0; a < nb_cols; a++){
            array[i][a] = buffer[count];
            count++;
        }
        my_putstr(array[i]);
        my_putchar('\n');
        count++;
    }
}
