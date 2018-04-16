/*
** EPITECH PROJECT, 2018
** minish.h
** File description:
** minish
*/

#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#ifndef NAVY_H_
#define NAVY_H_

int already_boat(char ***map, char nb);
void finish(int, char **, char **);
int no_eboat(char ***);
int no_boat(char ***);
int check_coo(char ***, int, int);
int touch(int);
void touch_or_not(int, int);
void branch(int);
void update_map(char ***, int, int, int);
int save_coord(int ltr, int, int);
int game_loop_player2(int, char ***, char ***);
int game_loop_player1(int pid_e, char ***);
int gest_err(char *attack);
int signal_attack(char *attack, int);
int my_get_nbr(char *);
int player_two(char **av, int);
int end_while(int sig);
void message_receive(int);
void redirect(int sig);
int waiting(char ***, int, int, int);
void handler(int sig, siginfo_t *siginfo, void *);
int player_one(char **av, int pid_e);
int my_strlen(char *str);
char **create_fmap(char *av);
char *get_next_line(const int fd);
int host_connexion(void);
void signal_receive(int sig);
void player_connexion(int);
char **base_map(void);
char **first_line(char **map);
char **second_line(char **map);
void my_putchar(char c);
int my_putstr(char *str);
void my_put_tab(char **tab, int height);
char **other_lines(char **map);
char *create_line(char *map, int nb);
char **my_strtotab(char *str);
int tab_len(char **src);
int countchar(char *str, char c);
int my_put_nbr(int nb);
int boat_two(char **coo, char ***map);
int twosamelet(char **coo, char ***map, int i);
int place_boat(char ***map, char *co);
int my_getnbr(char *str);
int boat_two(char **coo, char ***map);
int twosamenb(char **coo, char ***map, int i);
int twosamelet(char **coo, char ***map, int i);
int boat_tree(char **coo, char ***map);
int treesamenb(char **coo, char ***map, int i);
int treesamelet(char **coo, char ***map, int i);
int checktree(char ***map, int line, int fcol, int nb);
int checktreelet1(char ***map, int fline, int fcol, int nb);
int boat_four(char **coo, char ***map);
int foursamenb(char **coo, char ***map, int i);
int foursamelet(char **coo, char ***map, int i);
int checkfournb(char ***map, int line, int fcol, int nb);
int checkfourlet(char ***map, int fline, int col, int nb);
int boat_five(char **coo, char ***map);
int fivesamelet(char **coo, char ***map, int i);
int fivesamenb(char **coo, char ***map, int i);
int checkfive(char ***map, int fline, int col, int nb);
int checkfivenb(char ***map, int line, int fcol, int nb);
char **my_strtotab(char *str);
int check_line(char *line);
int check_letter(char *line);

#endif
