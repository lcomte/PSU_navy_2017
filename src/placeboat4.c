/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** main
*/

#include "navy.h"

int boat_tree(char **coo, char ***map)
{
	int i = 0;

	if (coo[1][0] == coo[2][0]) {
		i = treesamelet(coo, map, i);
	} else if (coo[1][1] == coo[2][1]) {
		i = treesamenb(coo, map, i);
	} else {
		return (1);
	}
	return (i);
}

int treesamenb(char **coo, char ***map, int i)
{
	int line = (coo[1][1] - 48) + 1;
	int fcol = (coo[1][0] - 64) * 2;
	int tcol = (coo[2][0] - 64) * 2;

	if (fcol + 4 == tcol && already_boat(map, '3') == 0) {
		i = checktree(map, line, fcol, 1);
		(*map)[line][fcol] = '3';
		(*map)[line][fcol + 2] = '3';
		(*map)[line][fcol + 4] = '3';
	} else if (fcol - 4 == tcol && already_boat(map, '3') == 0) {
		i = checktree(map, line, fcol, 2);
		(*map)[line][fcol] = '3';
		(*map)[line][fcol - 2] = '3';
		(*map)[line][fcol - 4] = '3';
	} else {
		return (1);
	}
	return (i);
}

int treesamelet(char **coo, char ***map, int i)
{
	int col = (coo[1][0] - 64) * 2;
	int fline = (coo[1][1] - 48) + 1;
	int tline = (coo[2][1] - 48) + 1;

	if (fline + 2 == tline && already_boat(map, '3') == 0) {
		i = checktreelet1(map, fline, col, 1);
		(*map)[fline][col] = '3';
		(*map)[fline + 1][col] = '3';
		(*map)[fline + 2][col] = '3';
	} else if (fline - 2 == tline && already_boat(map, '3') == 0) {
		i = checktreelet1(map, fline, col, 2);
		(*map)[fline][col] = '3';
		(*map)[fline - 1][col] = '3';
		(*map)[fline - 2][col] = '3';
	} else {
		return (1);
	}
	return (i);
}

int checktree(char ***map, int line, int fcol, int nb)
{
	if (nb == 1) {
		if ((*map)[line][fcol] == '.' && (*map)[line][fcol + 2] == '.'
			&& (*map)[line][fcol + 4] == '.') {
			return (0);
		}
	} else if (nb == 2) {
		if ((*map)[line][fcol] == '.' && (*map)[line][fcol - 2] == '.'
			&& (*map)[line][fcol - 4] == '.') {
			return (0);
		}
	}
	return (1);
}

int checktreelet1(char ***map, int fline, int col, int nb)
{
	if (nb == 1) {
		if ((*map)[fline][col] == '.' && (*map)[fline + 1][col] == '.'
			&& (*map)[fline + 2][col] == '.'){
			return (0);
		}
	}
	if (nb == 2) {
		if ((*map)[fline][col] == '.' && (*map)[fline - 1][col] == '.'
			&& (*map)[fline - 2][col] == '.') {
			return (0);
		}
	}
	return (1);
}
