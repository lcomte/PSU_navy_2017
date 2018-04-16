/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** main
*/

#include "navy.h"

char **my_strtotab(char *str)
{
	char **tab = malloc(sizeof(char *) * (countchar(str, ':') + 2));
	int i = 0;
	int y = 0;
	int x = 0;

	tab[0] = malloc(sizeof(char) * (1 + 1));
	for (; str[i] != '\0'; x++ , i++) {
		if (str[i] == ':') {
			tab[y][x] = '\0';
			y++;
			tab[y] = malloc(sizeof(char) * (2 + 1));
			i++;
			x = 0;
		}
		tab[y][x] = str[i];
	}
	tab[y][x] = '\0';
	tab[y + 1] = NULL;
	return (tab);
}

int countchar(char *str, char c)
{
	int count = 0;
	int i = 0;

	while (str[i] != '\0') {
		if (str[i] == c)
			count++;
		i++;
	}
	return (count);
}

int place_boat(char ***map, char *co)
{
	char **coo = my_strtotab(co);
	int len = my_strlen(co);
	int i = 0;

	if (len != 7 || check_line(co) == 1)
		return (1);
	switch(coo[0][0]) {
	case '2':
		i = boat_two(coo, map);
		break;
	case '3':
		i = boat_tree(coo, map);
		break;
	case '4':
		i = boat_four(coo, map);
		break;
	case '5':
		i = boat_five(coo, map);
		break;
	}
	return (i);
}

int my_getnbr(char *str)
{
	int p = 0;
	int z = 0;
	int nbr = 0;

	while (str[p] != '\0' && (str[p] > '9' ||  str[p] < '0')) {
		p = p + 1;
	}
	while (str[p + z] <= '9' && str[p + z] >= '0') {
		nbr = ((str[p + z] - 48) + nbr * 10);
		z = z + 1;
	}
	if (str[p - 1] == '-') {
		nbr = nbr * -1;
	}
	return (nbr);
}

int check_line(char *line)
{
	int i;

	if (line[0] < '2' || line[0] > '5') {
		return (1);
	} else if (line[1] != ':' || line[4] != ':') {
		return (1);
	} else if (line[3] < '1' || line[3] > '8' || line[6] < '1'
		|| line[6] > '8') {
		return (1);
	}
	i = check_letter(line);
	return (i);
}