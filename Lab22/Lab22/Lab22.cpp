#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
    pid_t child;
    int fd;
    char* args[] = {
        "ps",
        NULL
    };

    fd = open("out.txt", O_WRONLY | O_CREAT | O_TRUNC);
    if (fd == -1)
    {
        perror("open()");
        exit(EXIT_FAILURE);
    }
    if (dup2(fd, STDOUT_FILENO) == -1)
    {
        perror("dup2()");
        exit(EXIT_FAILURE);
    }

    child = fork();
    if (child == -1)
    {
        perror("fork()");
        exit(EXIT_FAILURE);
    }
    if (child == 0)
    {
        sleep(1);
        execvp("ps", args);
    }
    wait(NULL);
    execvp("ps", args);
    return 0;
}