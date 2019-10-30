/*
** EPITECH PROJECT, 2018
** task
** File description:
** task
*/

#ifndef SYN_PROJTESTER_2018_PROJTESTER_H
#define SYN_PROJTESTER_2018_PROJTESTER_H

#include <stddef.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <stdio.h>
#include <string.h>

void check_option_one(char **av);
char **my_str_to_word_array_synthesis(char const *str);
int my_tablen(char **tab);
void free_tab(char **tab);
char *second_option(char *ptr);
char *new_path(char *str, char *path);
char *get_line(FILE *stream);
void free_dir(struct dirent **dir, int n);
FILE *open_file(char const *filepath);
int option_three(char *path, char *ptr);
int check_three_option(char **av);
char *get_path_cwd(char *str);
char *get_good_path(char *str);

#endif //SYN_PROJTESTER_2018_PROJTESTER_H
