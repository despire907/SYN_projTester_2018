/*
** EPITECH PROJECT, 2018
** task
** File description:
** task
*/

#include "projtester.h"

FILE *open_file(char const *filepath)
{
    FILE *stream;

    if (!filepath)
        return NULL;
    stream = fopen(filepath, "r");
    if (!(stream))
        return NULL;
    return (stream);
}

char *get_line(FILE *stream)
{
    __ssize_t check = 0;
    char *buf = NULL;
    size_t buf_size = 0;

    if (!stream)
        return NULL;
    if ((check = getline(&buf, &buf_size, stream)) == 0)
        return NULL;
    if (check == -1) {
        free(buf);
        return NULL;
    } if (!strncmp(buf, "ARGS:", 5))
        return &buf[5];
    else
        return NULL;
}