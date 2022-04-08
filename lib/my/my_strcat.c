/*
** EPITECH PROJECT, 2021
** my_strcat
** File description:
** my_strcat
*/

char *my_strcat(char *dest , char const *src)
{
    int a = 0;
    int b = 0;

    for (a = 0; dest[a] != '\0'; a = a + 1) {
    }
    for (b = 0; src[b] != '\0' ; b = b + 1) {
        dest[a + b] = src [b];
    }
    dest[a + b] = '\0';
    return (dest);
}
