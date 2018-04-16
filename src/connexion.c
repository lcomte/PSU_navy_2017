/*
** EPITECH PROJECT, 2018
** connection
** File description:
** serv
*/

#include "navy.h"

int pid_e = 0;

void handler(int sig, siginfo_t *siginfo, void *ucontext)
{
	int c = siginfo->si_pid;

	(void)sig;
	(void)siginfo;
	(void)ucontext;
	pid_e = c;
	my_putstr("enemy connected\n\n");
}

int host_connexion(void)
{
	int i = getpid();
	struct sigaction act;

	my_putstr("my_pid: ");
	my_put_nbr(i);
	my_putchar('\n');
	my_putstr("waiting for enemy connexion...\n");
	act.sa_sigaction = &handler;
	act.sa_flags = SA_SIGINFO;
	while (pid_e <= 0) {
		sigaction(SIGUSR2, &act, NULL);
	}
	return (pid_e);
}

void signal_receive(int sig)
{
	(void)sig;
	my_putstr("successfully connected\n\n");
}

void player_connexion(int pid_t)
{
	int pid = getpid();
	int i = 1;

	my_putstr("my_pid: ");
	my_put_nbr(pid);
	my_putchar('\n');
	i = kill(pid_t, SIGUSR2);
	if (i == 0) {
		signal_receive(i);
	}
}
