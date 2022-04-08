/*
** EPITECH PROJECT, 2021
** my_is_prime
** File description:
** my_is_prime
*/

int my_is_prime(int nb)
{
    int b = 0;
    int a;

    for (int a = 1; a <= nb; a = a + 1) {
        if (nb % a == 0)
            b = b + 1;
    }
    if (b == 2)
        return (1);
    else
        return (0);
}
