/*
** EPITECH PROJECT, 2018
** task
** File description:
** task
*/

#include "projtester.h"

int fork_and_exec(char *path, char *ptr, char *arg)
{
    char *good_path = second_option(ptr);
    char *new = malloc(sizeof(char) * (strlen(path) + strlen(ptr) + 2));
    char **tab = NULL;
    pid_t pid;
    int status;

    if (new == NULL)
        return (84);
    sprintf(new, "%s/%s", ptr, arg);
    tab = my_str_to_word_array_synthesis(new);
    free(new);
    pid = fork();
    if (pid == 0)
        execve(good_path, tab, NULL);
    else
        wait(&status);
    free_tab(tab);
    free(good_path);
    return 0;
}

int nb_charac(char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (str[i + 5] == '\0' && strcmp(&str[i], ".tdf"))
            return i + 1;
        i++;
    }
    return -1;
}

int display_all(char *path, char *ptr)
{
    FILE *stream = open_file(path);
    char *arg = get_line(stream);
    char **tab = my_str_to_word_array_synthesis(path);
    char *str = NULL;
    int i = 1;
    if (arg == NULL)
        return 84;
    while (tab[i] != NULL) {
        if (tab[i + 1] == NULL) {
            str = strndup(tab[i], nb_charac(tab[i]));
            printf("%s: ", str);
            fflush(stdout);
            fork_and_exec(path, ptr, arg);
            free(str);
        } else
            printf("[%s] ", tab[i]);
        i++;
    } fclose(stream);
    free_tab(tab);
    return 0;
}

int option_three(char *path, char *ptr)
{
    struct dirent **dir;
    char *d_path;
    int n = scandir(path, &dir, 0, alphasort);
    int j = 0;

    if (n < 0)
        return 84;
    while (j != n) {
        d_path = malloc(sizeof(char) *
        (strlen(path) + strlen(dir[j]->d_name)) + 2);
        sprintf(d_path, "%s/%s", path, dir[j]->d_name);
        if (dir[j]->d_type != DT_DIR)
            display_all(d_path, ptr);
        else if (dir[j]->d_type == DT_DIR && strncmp(dir[j]->d_name, ".", 1))
            option_three(d_path, ptr);
        free(d_path);
        j++;
    }
    free_dir(dir, n);
    return 0;
}

int check_three_option(char **av)
{
    if (get_good_path(av[2]) == NULL && get_path_cwd(av[2]) == NULL)
        return 84;
    if (option_three(av[1], av[2]) == 84)
        return 84;
    return 0;
}