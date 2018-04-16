/*
** EPITECH PROJECT, 2018
** waiting
** File description:
** time
*/

#include "navy.h"

int end_while(int i)
{
	static int z = 0;
	if (i == 3) {
		z = 0;
	}
	else if (i == 1) {
		z = z + 1;
	}
	return (z);
}

int save_coord(int ltr, int nbr, int check)
{
	static int lettre = 0;
	static int nombre = 0;

	if (check == 0) {
		lettre = ltr;
		nombre = nbr;
	}
	if (check == 1) {
		return (lettre);
	}
	if (check == 2) {
		return (nombre);
	}
	return (0);
}

void message_receive(int z)
{
	static int lettre = 0;
	static int nbr = 0;
	static int i = 0;

	switch(z) {
	case 1:
		if (i == 0)
			lettre++;
		if (i == 1)
			nbr++;
		break;
	case 2:
		i = i + 1;
		break;
	case 3:
		save_coord(lettre, nbr, 0);
		lettre = 0;
		nbr = 0;
		i = 0;
		break;
	}
}

void redirect(int sig)
{
	if (sig == SIGUSR1) {
		message_receive(1);
	}
	if (sig == SIGUSR2) {
		message_receive(2);
		end_while(1);
	}
}

int waiting(char ***map, int ltr, int nbr, int pid_e)
{
	int i = 0;
	int z = 0;

	my_putstr("\nwaiting for enemy's attack...\n");
	while (i < 2) {
		signal(SIGUSR1, redirect);
		signal(SIGUSR2, redirect);
		i = end_while(0);
	}
	end_while(3);
	message_receive(3);
	ltr = save_coord(ltr, nbr, 1);
	nbr = save_coord(ltr, nbr, 2);
	z = check_coo(map, ltr, nbr);
	update_map(map, ltr, nbr, z);
	touch_or_not(z, pid_e);
	return (1);
}
