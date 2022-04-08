/*
** EPITECH PROJECT, 2021
** my_strdup
** File description:
** my_strdup
*/

#include <stdlib.h>

int my_strlen(char const *str);

char *my_strdup(char const *src)
{
    char *destination;
    int first_string = 0;

    destination = malloc(sizeof(char) * (my_strlen(src) + 1));
    while (src[first_string] != '\0') {
        destination[first_string] = src[first_string];
        first_string = first_string + 1;
    }
    destination[first_string] = '\0';
    return (destination);
}
