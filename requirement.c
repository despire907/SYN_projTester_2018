/*
** EPITECH PROJECT, 2018
** task
** File description:
** task
*/

#include <stddef.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <stdio.h>
#include <string.h>

void my_ps_synthesis(void)
{
    pid_t pid;
    int ex = 0;
    int status;
    char *str[2];
    str[0] = "ps";
    str[1] = NULL;

    if ((pid = fork()) == -1) {
        perror(NULL);
        exit (84);
    } else if (pid == 0) {
        ex = execve("/usr/bin/ps", str, NULL);
        if (ex == -1)
            exit (2);
    } else
        waitpid(pid, &status, 0);
}