/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** main
*/

#include "navy.h"

int boat_two(char **coo, char ***map)
{
	int i = 0;

	if (coo[1][0] == coo[2][0]) {
		i = twosamelet(coo, map, i);
	} else if (coo[1][1] == coo[2][1]) {
		i = twosamenb(coo, map, i);
	} else {
		return (1);
	}
	return (i);
}

int twosamenb(char **coo, char ***map, int i)
{
	int line = (coo[1][1] - 48) + 1;
	int fcol = (coo[1][0] - 64) * 2;
	int scol = (coo[2][0] - 64) * 2;

	if (scol + 2 == fcol || fcol + 2 == scol) {
		if ((*map)[line][fcol] == '.' && (*map)[line][scol] == '.'
			&& already_boat(map, '2') == 0) {
			(*map)[line][fcol] = '2';
			(*map)[line][scol] = '2';
		} else {
			return (1);
		}
	} else
		return (1);
	return (i);
}

int twosamelet(char **coo, char ***map, int i)
{
	int col = (coo[1][0] - 64) * 2;
	int fline = (coo[1][1] - 48) + 1;
	int sline = (coo[2][1] - 48) + 1;

	if (fline + 1 == sline) {
		if ((*map)[fline][col] == '.' && (*map)[sline][col] == '.'
			&& already_boat(map, '2') == 0) {
			(*map)[fline][col] = '2';
			(*map)[sline][col] = '2';
		} else {
			return (1);
		}
	} else
		return (1);
	return (i);
}

int check_letter(char *line)
{
	if (line[2] < 65 || line[2] > 72 || line[5] < 65 || line[5] > 72)
		return (1);
	return (0);
}

int already_boat(char ***map, char nb)
{
	int y = 2;
	int x = 2;

	for (; y <= 9; y++) {
		for (; x <= 16; x = x + 2) {
			if ((*map)[y][x] == nb) {
				return (1);
			}
		}
		x = 2;
	}
	return (0);
}