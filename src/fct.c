/*
** EPITECH PROJECT, 2018
** fct
** File description:
** touch
*/

#include "navy.h"

void branch(int sig)
{
	if (sig == SIGUSR1) {
		touch(1);
		end_while(1);
	}
	if (sig == SIGUSR2) {
		touch(2);
		end_while(1);
	}
}

void touch_or_not(int z, int pid_e)
{
	if (z == 1)
		kill(pid_e, SIGUSR2);
	if (z == 0)
		kill(pid_e, SIGUSR1);
}

int touch(int touch)
{
	static int i = 3;

	if (touch == 1) {
		i = 0;
	}
	if (touch == 2) {
		i = 1;
	}
	if (touch == 3) {
		return (i);
	}
	return (0);
}

void finish(int c, char **pmap, char **emap)
{
	my_putstr("\nmy positions:\n");
	my_put_tab(pmap, 9);
	my_putstr("\nenemy's positions:\n");
	my_put_tab(emap, 9);
	if (c == 0)
		my_putstr("\nI won\n");
	if (c == 1)
		my_putstr("\nEnemy won\n");
}