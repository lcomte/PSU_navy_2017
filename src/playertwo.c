/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** main
*/

#include "navy.h"

int player_two(char **av, int pid_e)
{
	char **pmap = create_fmap(av[2]);
	char **emap = base_map();
	int c = 0;

	if (emap == NULL || pmap == NULL)
		return (84);
	player_connexion(pid_e);
	my_putstr("my positions:\n");
	my_put_tab(pmap, 9);
	my_putstr("\nenemy's positions:\n");
	my_put_tab(emap, 9);
	while (c != 3) {
		c = waiting(&pmap, 0, 0, pid_e);
		if (no_boat(&pmap) == 0)
			break;
		my_putstr("\nattack: ");
		c = game_loop_player1(pid_e, &emap);
		if (no_eboat(&emap) == 1 || c == 84)
			break;
		my_putstr("my positions:\n");
		my_put_tab(pmap, 9);
		my_putstr("\nenemy's positions:\n");
		my_put_tab(emap, 9);
	}
	if (c == 0 || c == 1) {
		finish(c, pmap, emap);
	}
	return (c);
}

char *create_line(char *map, int nb)
{
	int x = 3;

	map[0] = nb;
	map[1] = 124;
	map[2] = '.';
	while (x <= 16) {
		map[x] = ' ';
		x++;
		map[x] = '.';
		x++;
	}
	return (map);
}