/*
** EPITECH PROJECT, 2018
** game
** File description:
** loop
*/

#include "navy.h"

int signal_attack(char *attack, int pid_e)
{
	int lettre = (attack[0] - 64);
	int nombre = (attack[1] - 48);
	int i = 0;

	save_coord(lettre, nombre, 0);
	while (lettre > 0) {
		kill(pid_e, SIGUSR1);
		lettre = lettre - 1;
		usleep(5000);
	}
	kill(pid_e, SIGUSR2);
	usleep(5000);
	while (nombre > 0) {
		kill(pid_e, SIGUSR1);
		usleep(5000);
		nombre = nombre - 1;
	}
	kill(pid_e, SIGUSR2);
	while (i != 1) {
		signal(SIGUSR1, branch);
		signal(SIGUSR2, branch);
		i = end_while(2);
	}
	i = touch(3);
	end_while(3);
	return (i);
}

int gest_err(char *attack)
{
	if (my_strlen(attack) != 2)
		return (0);
	if (attack[0] > 72 || attack[0] < 65)
		return (0);
	if (attack[1] < 49 || attack[1] > 56)
		return (0);
	return (1);
}

int game_loop_player1(int pid_e, char ***emap)
{
	int i = 0;
	char *attack;
	int nbr = 0;
	int ltr = 0;
	int touch = 0;

	while (i == 0) {
		attack = get_next_line(0);
		if (attack == NULL)
			return (84);
		i = gest_err(attack);
		if (i == 0) {
			my_putstr("wrong position\n");
			 my_putstr("attack: ");
		}
	}
	touch = signal_attack(attack, pid_e);
	ltr = save_coord(ltr, nbr, 1);
	nbr = save_coord(ltr, nbr, 2);
	update_map(emap, ltr, nbr, touch);
	return (0);
}
