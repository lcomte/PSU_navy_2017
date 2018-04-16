/*
** EPITECH PROJECT, 2018
** my
** File description:
** getnbr
*/

#include "navy.h"

int my_get_nbr(char *str)
{
	int x = 0;
	int nbr = 0;

	while (str[x] != '\0') {
		if (str[x] < 48 || str[x] > 57) {
			return (84);
		}
		nbr = ((str[x] - 48) + nbr * 10);
		x = x + 1;
	}
	return (nbr);
}

int no_boat(char ***map)
{
	int y = 2;
	int x = 2;

	for(; y <= 9; y++) {
		for (; x <= 16; x = x + 2) {
			if ((*map)[y][x] == '2' || (*map)[y][x] == '3'
				|| (*map)[y][x] == '4' || (*map)[y][x] == '5') {
				return (1);
			}
		}
		x = 2;
	}
	return (0);
}

int no_eboat(char ***map)
{
	int y = 2;
	int x = 2;
	int count = 0;

	for(; y <= 9; y++) {
		for (; x <= 16; x = x + 2) {
			if ((*map)[y][x] == 'x') {
				count++;
			}
		}
		x = 2;
	}
	if (count == 14)
		return (1);
	return (0);
}
