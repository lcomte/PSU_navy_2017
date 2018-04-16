/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** main
*/

#include "navy.h"

int boat_four(char **coo, char ***map)
{
	int i = 1;

	if (coo[1][0] == coo[2][0]) {
		i = foursamelet(coo, map, i);
	} else if (coo[1][1] == coo[2][1]) {
		i = foursamenb(coo, map, i);
	} else {
		return (1);
	}
	return (i);
}

int foursamenb(char **coo, char ***map, int i)
{
	int line = (coo[1][1] - 48) + 1;
	int fcol = (coo[1][0] - 64) * 2;
	int qcol = (coo[2][0] - 64) * 2;

	if (fcol + 6 == qcol && already_boat(map, '4') == 0) {
		i = checkfournb(map, line, fcol, 1);
		(*map)[line][fcol] = '4';
		(*map)[line][fcol + 2] = '4';
		(*map)[line][fcol + 4] = '4';
		(*map)[line][qcol] = '4';
	} else if (fcol - 6 == qcol && already_boat(map, '4') == 0) {
		i = checkfournb(map, line, fcol, 2);
		(*map)[line][fcol] = '4';
		(*map)[line][fcol - 2] = '4';
		(*map)[line][fcol - 4] = '4';
		(*map)[line][qcol] = '4';
	}
	return (i);
}

int foursamelet(char **coo, char ***map, int i)
{
	int col = (coo[1][0] - 64) * 2;
	int fline = (coo[1][1] - 48) + 1;
	int qline = (coo[2][1] - 48) + 1;

	if (fline + 3 == qline && already_boat(map, '4') == 0) {
		i = checkfourlet(map, fline, col, 1);
		(*map)[fline][col] = '4';
		(*map)[fline + 1][col] = '4';
		(*map)[fline + 2][col] = '4';
		(*map)[fline + 3][col] = '4';
	} else if (fline - 3 == qline && already_boat(map, '4') == 0) {
		i = checkfourlet(map, fline, col, 2);
		(*map)[fline][col] = '4';
		(*map)[fline - 1][col] = '4';
		(*map)[fline - 2][col] = '4';
		(*map)[fline - 3][col] = '4';
	}
	return (i);
}

int checkfournb(char ***map, int line, int fcol, int nb)
{
	if (nb == 1) {
		if ((*map)[line][fcol] == '.' && (*map)[line][fcol + 2] == '.'
			&& (*map)[line][fcol + 4] == '.'
			&& (*map)[line][fcol + 6] == '.') {
			return (0);
		}
	} else if (nb == 2) {
		if ((*map)[line][fcol] == '.' && (*map)[line][fcol - 2] == '.'
			&& (*map)[line][fcol - 4] == '.'
			&& (*map)[line][fcol - 6] == '.') {
			return (0);
		}
	}
	return (1);
}

int checkfourlet(char ***map, int fline, int col, int nb)
{
	if (nb == 1) {
		if ((*map)[fline][col] == '.' && (*map)[fline + 1][col] == '.'
			&& (*map)[fline + 2][col] == '.'
			&& (*map)[fline + 3][col] == '.') {
			return (0);
		}
	} else if (nb == 2) {
		if ((*map)[fline][col] == '.' && (*map)[fline - 1][col] == '.'
			&& (*map)[fline - 2][col] == '.'
			&& (*map)[fline - 3][col] == '.') {
			return (0);
		}
	}
	return (1);
}
