/*
** EPITECH PROJECT, 2018
** task
** File description:
** task
*/

#include "projtester.h"

void display_first_part(int count, struct dirent *dir)
{
    int i = 0;

    while (i < count) {
        printf("-----");
        i++;
    }
    printf("%s\n", dir->d_name);
}

void free_dir(struct dirent **dir, int n)
{
    int i = 0;

    while (i != n)
        free(dir[i++]);
    free(dir);
}

void option_one(char *path, int count)
{
    struct dirent **dir;
    char *d_path;
    int n = scandir(path, &dir, 0, alphasort);
    int j = 0;

    while (j != n) {
        if (dir[j]-> d_type != DT_DIR)
            display_first_part(count, dir[j]);
        else if (dir[j]-> d_type == DT_DIR &&
        strncmp(dir[j]->d_name, ".", 1)) {
            display_first_part(count, dir[j]);
            d_path = malloc(sizeof(char) *
            (strlen(path) + strlen(dir[j]->d_name)) + 2);
            sprintf(d_path, "%s/%s", path, dir[j]->d_name);
            option_one(d_path, count + 1);
            free(d_path);
        }
        j++;
    }
    free_dir(dir, n);
}

void check_option_one(char **av)
{
    char **tab = my_str_to_word_array_synthesis(av[1]);
    int i = my_tablen(tab);

    printf("%s\n", tab[i]);
    option_one(av[1], 1);
    free_tab(tab);
}