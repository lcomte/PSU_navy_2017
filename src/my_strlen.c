/*
** EPITECH PROJECT, 2017
** azertyu
** File description:
** ae
*/

#include "navy.h"

int my_strlen(char *str)
{
	int x = 0;
	while (str[x] != '\0') {
		x = x + 1;
	}
	return (x);
}
