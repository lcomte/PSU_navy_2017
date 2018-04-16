/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** main
*/

#include "navy.h"

int player_one(char **av, int pid_e)
{
	char **pmap = create_fmap(av[1]);
	char **emap = base_map();
	int c = 0;

	if (emap == NULL || pmap == NULL)
		return (84);
	pid_e = host_connexion();
	my_putstr("my_positions:\n");
	my_put_tab(pmap, 9);
	my_putstr("\nenemy's positions:\n");
	my_put_tab(emap, 9);
	while (c != 3) {
		my_putstr("\nattack: ");
		c = game_loop_player1(pid_e, &emap);
		if (no_eboat(&emap) == 1 || c == 84)
			break;
		c = waiting(&pmap, 0, 0, pid_e);
		if (no_boat(&pmap) == 0)
			break;
		my_putstr("my positions:\n");
		my_put_tab(pmap, 9);
		my_putstr("\nenemy's positions:\n");
		my_put_tab(emap, 9);
	}
	if (c == 0 || c == 1)
		finish(c, pmap, emap);
	return (c);
}

char **create_fmap(char *av)
{
	int fd = open(av, O_RDONLY);
	char *line;
	char **map = base_map();
	int i = 1;
	int check;

	if (fd < 0)
		return (NULL);
	for (; i <= 4; i++) {
		line = get_next_line(fd);
		if (line == NULL)
			return (NULL);
		check = place_boat(&map, line);
		if (check == 1) {
			return (NULL);
		}
	}
	return (map);
}

int check_coo(char ***pmap, int let, int nb)
{
	int line = nb + 1;
	int col = let * 2;

	if ((*pmap)[line][col] == '2' || (*pmap)[line][col] == '3' ||
		(*pmap)[line][col] == '4' || (*pmap)[line][col] == '5') {
		return (1);
	}
	return (0);
}

void update_map(char ***map, int let, int nb, int res)
{
	int line = nb + 1;
	int col = let * 2;

	if (res == 1) {
		(*map)[line][col] = 'x';
		my_putchar(let + 64);
		my_putchar(nb + 48);
		my_putstr(": hit\n");
	}
	if (res == 0) {
		if ((*map)[line][col] != 'x')
			(*map)[line][col] = 'o';
		my_putchar(let + 64);
		my_putchar(nb + 48);
		my_putstr(": missed\n");
	}
}