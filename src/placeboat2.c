/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** main
*/

#include "navy.h"

int boat_five(char **coo, char ***map)
{
	int i = 1;

	if (coo[1][0] == coo[2][0]) {
		i = fivesamelet(coo, map, i);
	} else if (coo[1][1] == coo[2][1]) {
		i = fivesamenb(coo, map, i);
	}
	return (i);
}

int fivesamelet(char **coo, char ***map, int i)
{
	int col = (coo[1][0] - 64) * 2;
	int fline = (coo[1][1] - 48) + 1;
	int lline = (coo[2][1] - 48) + 1;

	if (fline + 4 == lline && already_boat(map, '5') == 0) {
		i = checkfive(map, fline, col, 1);
		(*map)[fline][col] = '5';
		(*map)[fline + 1][col] = '5';
		(*map)[fline + 2][col] = '5';
		(*map)[fline + 3][col] = '5';
		(*map)[lline][col] = '5';
	} else if (fline - 4 == lline && already_boat(map, '5') == 0) {
		i = checkfive(map, fline, col, 2);
		(*map)[fline][col] = '5';
		(*map)[fline - 1][col] = '5';
		(*map)[fline - 2][col] = '5';
		(*map)[fline - 3][col] = '5';
		(*map)[lline][col] = '5';
	}
	return (i);
}

int fivesamenb(char **coo, char ***map, int i)
{
	int line = (coo[1][1] - 48) + 1;
	int fcol = (coo[1][0] - 64) * 2;
	int lcol = (coo[2][0] - 64) * 2;

	if (fcol + 8 == lcol && already_boat(map, '5') == 0) {
		i = checkfivenb(map, line, fcol, 1);
		(*map)[line][fcol] = '5';
		(*map)[line][fcol + 2] = '5';
		(*map)[line][fcol + 4] = '5';
		(*map)[line][fcol + 6] = '5';
		(*map)[line][fcol + 8] = '5';
	} else if (fcol - 8 == lcol && already_boat(map, '5') == 0) {
		i = checkfivenb(map, line, fcol, 2);
		(*map)[line][fcol] = '5';
		(*map)[line][fcol - 2] = '5';
		(*map)[line][fcol - 4] = '5';
		(*map)[line][fcol - 6] = '5';
		(*map)[line][fcol - 8] = '5';
	}
	return (i);
}

int checkfive(char ***map, int fline, int col, int nb)
{
	if (nb == 1) {
		if ((*map)[fline][col] == '.' && (*map)[fline + 1][col] == '.'
			&& (*map)[fline + 2][col] == '.'
			&& (*map)[fline + 3][col] == '.'
			&& (*map)[fline + 4][col] == '.') {
			return (0);
		}
	}
	if (nb == 2) {
		if ((*map)[fline][col] == '.' && (*map)[fline - 1][col] == '.'
			&& (*map)[fline - 2][col] == '.'
			&& (*map)[fline - 3][col] == '.'
			&& (*map)[fline - 4][col] == '.') {
			return (0);
		}
	}
	return (1);
}

int checkfivenb(char ***map, int line, int fcol, int nb)
{
	if (nb == 1) {
		if ((*map)[line][fcol] == '.' && (*map)[line][fcol + 2] == '.'
			&& (*map)[line][fcol + 4] == '.'
			&& (*map)[line][fcol + 6] == '.'
			&& (*map)[line][fcol + 8] == '.') {
			return (0);
		}
	} else if (nb == 2) {
		if ((*map)[line][fcol] == '.' && (*map)[line][fcol - 2] == '.'
			&& (*map)[line][fcol - 4] == '.'
			&& (*map)[line][fcol - 6] == '.'
			&& (*map)[line][fcol - 8] == '.') {
			return (0);
		}
	}
	return (1);
}
