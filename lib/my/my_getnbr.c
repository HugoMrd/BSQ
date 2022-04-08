/*
** EPITECH PROJECT, 2021
** my_getnbr
** File description:
** my_getnbr
*/

int my_getnbr(char const *str)
{
    int i = 0;
    int nombre = 0;

    while ((str[i] -'0' < 0 || str[i] > '9') && str[i] != '\0') {
        i = i + 1;
    }
    while ((str[i] - '0' >= 0 && str[i] <= '9') && str[i] != '\0') {
        nombre = (nombre * 10) + (str[i] - '0');
        i = i + 1;
    }
    if (str[0] == '-') {
        nombre *= -1;
        return (nombre);
    }
    return (nombre);
}
