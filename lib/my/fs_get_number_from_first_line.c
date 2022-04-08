/*
** EPITECH PROJECT, 2021
** frfr
** File description:
** frrf
*/

#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/types.h>
#include "../../include/my.h"

int fs_get_number_from_first_line(char const *filepath)
{
    int size = 300;
    int i;
    int handle;
    char *buffer;

    buffer = malloc(sizeof(char) * size);
    handle = open(filepath, O_RDONLY);
    read(handle, buffer, size);
    if (my_getnbr(buffer) < 0) {
        return (-1);
    } else {
        return (my_getnbr(buffer));
    }
}
