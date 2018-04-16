/*
** EPITECH PROJECT, 2017
** lib.c
** File description:
** stock fonction
*/

#include "navy.h"

void my_put_tab(char **tab, int height)
{
	int y = 0;

	while (y <= height) {
		my_putstr(tab[y]);
		my_putchar('\n');
		y++;
	}
}

void my_putchar(char c)
{
	write(1, &c, 1);
}

int my_putstr(char *str)
{
	int n = 0;

	while (str[n] != '\0') {
		my_putchar(str[n]);
		n = n + 1;
	}
	return (0);
}

int my_put_nbr(int nb)
{
	int num;

	if (nb < 0) {
		my_putchar(45);
		nb = nb * (-1);
	}
	if (nb >= 0) {
		if (nb >= 10) {
			num = nb % 10;
			nb = nb - num;
			nb = nb / 10;
			my_put_nbr(nb);
			my_putchar(48 + num);
		} else {
			my_putchar(48 + nb);
		}
	}
	return (0);
}

char *get_next_line(const int fd)
{
	char *res = malloc(sizeof(char) * 1000);
	char buf;
	int i;

	i = read(fd, &buf, 1);
	if (i == 0 || i == -1)
		return (NULL);
	i = 0;
	res[i] = buf;
	i++;
	while (i < 1000 && buf != '\n') {
		read(fd, &buf, 1);
		res[i] = buf;
		i++;
	}
	res[i - 1] = '\0';
	return (res);
}