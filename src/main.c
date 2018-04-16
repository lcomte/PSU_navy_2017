/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** main
*/

#include "navy.h"

int main(int ac, char **av)
{
	int z = 0;
	int pid_e = 0;
	int c = 0;

	if (ac == 2) {
		c = player_one(av, pid_e);
	} else if (ac == 3) {
		z = my_get_nbr(av[1]);
		if (z == 84) {
			return (84);
		}
		c = player_two(av, z);
	} else {
		return (84);
	}
	return (c);
}

char **base_map(void)
{
	char **map = malloc(sizeof(char *) * 11);
	int y = 0;

	while (y <= 10) {
		map[y] = malloc(sizeof(char) * 18);
		y++;
	}
	map[11] = NULL;
	map = first_line(map);
	map = second_line(map);
	map = other_lines(map);
	return (map);
}

char **first_line(char **map)
{
	int x = 3;
	int letter = 66;

	map[0][0] = ' ';
	map[0][1] = '|';
	map[0][2] = 'A';
	while (letter <= 72) {
		map[0][x] = ' ';
		x++;
		map[0][x] = letter;
		x++;
		letter++;
	}
	map[0][17] = '\0';
	return (map);
}

char **second_line(char **map)
{
	int x = 2;

	map[1][0] = 45;
	map[1][1] = 43;
	while (x <= 16) {
		map[1][x] = 45;
		x++;
	}
	map[1][x] = '\0';
	return (map);
}

char **other_lines(char **map)
{
	int y = 2;
	int nb = 49;

	while (y <= 9) {
		map[y] = create_line(map[y], nb);
		y++;
		nb++;
	}
	return (map);
}