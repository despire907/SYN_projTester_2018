/*
** EPITECH PROJECT, 2018
** task
** File description:
** task
*/

#include "projtester.h"

int check_fonction(char **av)
{
    struct dirent *folder;
    DIR *rep = opendir(av[1]);

    if (rep == NULL)
        return 84;
    if ((folder = readdir(rep)) == NULL)
        return 84;
    else if (folder->d_type == DT_DIR || folder->d_type == DT_REG) {
        check_option_one(av);
    } else
        return 84;
    closedir(rep);
    return 0;
}

int main(int ac, char **av)
{
    if (av[1] == NULL)
        return 84;
    if (ac == 2 && check_fonction(av) == 84)
        return 84;
    if (ac == 3 && av[2] != NULL && check_three_option(av) == 84)
        return 84;
    return 0;
}