/*
** EPITECH PROJECT, 2018
** task
** File description:
** task
*/

#include <stddef.h>
#include <stdlib.h>

int my_tablen(char **tab)
{
    int i = 0;

    while (tab[i] != NULL)
        i++;

    return i - 1;
}

void free_tab(char **tab)
{
    int i = 0;

    while (tab[i] != NULL) {
        free(tab[i]);
        i++;
    }
    free(tab);
}