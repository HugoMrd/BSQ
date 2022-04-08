/*
** EPITECH PROJECT, 2021
** my_putstr
** File description:
** my_putstr
*/

#include <unistd.h>

void my_putchar(char c);

int my_strlen(char const *str);

int my_putstr(char const *str)
{
    int a = 0;

    a = my_strlen(str);
    write(1, str, a);
}
