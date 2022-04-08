/*
** EPITECH PROJECT, 2021
** my_revstr
** File description:
** my_revstr
*/

char *my_revstr(char *str)
{
    char a = 0;
    int b = 0;
    int c = 0;

    while (str[c] != '\0') {
        c++;
    }
    while (b < c) {
        a = str[b];
        str[b] = str[c - 1];
        str[c - 1] = a;
        c = c - 1;
        b++ ;
    }
    return (str);
}
