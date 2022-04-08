/*
** EPITECH PROJECT, 2021
** my_compute_power_rec
** File description:
** my_compute_power_rec
*/

int my_putchar(char c);

int my_compute_power_rec(int nb , int p)
{
    if (p == 0) {
        return (1);
    }
    if (p < 0) {
        return (0);
    }
    int var = nb  * my_compute_power_rec(nb, p - 1);
    return (var);
}
