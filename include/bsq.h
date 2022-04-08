/*
** EPITECH PROJECT, 2021
** my_project
** File description:
** my_project
*/

#ifndef FUNCTIONS
    #define FUNCTIONS

typedef struct sqr_find_s {
    int size;
    int rows;
    int cols;
    int rows_biggest;
    int cols_biggest;
    int maximum;
}sqr_find_t;

int my_check_buffer(char *buffer);

char **load_2d_arr_from_file(char const *filepath, sqr_find_t *structure);

int bsq(char const *filepath);

int **mem_alloc_2d_array_int(sqr_find_t *structure);

int **load_2d_arr_from_int(char const *filepath, sqr_find_t *structure);

#endif
