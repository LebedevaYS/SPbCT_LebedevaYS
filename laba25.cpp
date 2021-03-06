#include <stdio.h>
#include <signal.h>
#include <wait.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>

int f_in, fd, ppid, pid, N, M, count = 0;

void wakeup()                         //
{
    signal(SIGALRM, wakeup);
    printf("Wake up!\n");
}

void sleeptime(int timeout)
{
    signal(SIGALRM, wakeup);
    alarm(timeout);
    pause();
}

void sigper(int n)
{
    signal(SIGUSR1, sigper);
   