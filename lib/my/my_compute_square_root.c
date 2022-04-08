/*
** EPITECH PROJECT, 2021
** my_compute_square_root
** File description:
** my_compute_square_root
*/

int my_putchar(char c);

int my_compute_square_root(int nb)
{
    int ab = 0;
    while (ab * ab < nb) {
        ab = ab + 1;
    }
    if (ab * ab == nb)
        return (ab);
    else {
        return (0);
    }
}
