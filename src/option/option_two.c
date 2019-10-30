/*
** EPITECH PROJECT, 2018
** task
** File description:
** task
*/

#include "projtester.h"

int check_access(char *d_path)
{
    int check = 0;

    if ((check = access(d_path, F_OK)) == 0) {
        if ((check = access(d_path, X_OK)) != -1)
            return 1;
        return 0;
    }
    return 0;
}

char *new_path(char *str, char *path)
{
    char *d_path = malloc(sizeof(char) * (strlen(path) + strlen(str)) + 2);
    sprintf(d_path, "%s/%s", path, str);
    return d_path;
}

char *get_good_path(char *str)
{
    char *bad_path = getenv("PATH");
    char *path = strdup(bad_path);
    char *send_path = NULL;
    int count = 0;
    char *d_path = NULL;
    int i = 0;

    while (path[i] != '\0') {
        if (path[i] == ':' || path[i + 1] == '\0') {
            send_path = strndup(&path[i - (count - 1)], count - 1);
            d_path = new_path(str, send_path);
            if (check_access(d_path) == 1)
                return d_path;
            free(d_path);
            count = 0;
        }
        i++;
        count++;
    }
    free(path);
    return NULL;
}

char *get_path_cwd(char *str)
{
    char *path = getcwd(NULL, 0);
    char *d_path = malloc(sizeof(char) * (strlen(path) + strlen(str)) + 2);

    sprintf(d_path, "%s/%s", path, str);
    if (check_access(d_path) == 1) {
        free(path);
        return d_path;
    }
    free(d_path);
    free(path);
    return NULL;
}

char *second_option(char *ptr)
{
    char *path = get_good_path(ptr);
    char *path_cwd = get_path_cwd(ptr);

    if (path == NULL && path_cwd == NULL) {
        free(path);
        free(path_cwd);
        return NULL;
    } else if (path != NULL) {
        free(path_cwd);
        return path;
    } else {
        free(path);
        return path_cwd;
    }
}