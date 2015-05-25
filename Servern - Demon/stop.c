#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>

#define FILE_NAME "/home/carlos/pid/startdem.pid"

//Tar fram pid nummret, avslutar process med pidnummret och tar bort filen så att
int main()
{
    FILE *fp = fopen(FILE_NAME, "r");
    if(fp == NULL)
    {
        printf("Server not running.\n");
        return 0;
    }
    pid_t killpid;
    int status;
    fscanf(fp, "%d", &killpid);
    fclose(fp);
    printf("Pid = %d\n", killpid);
    kill(killpid, 15);
    printf("kill done.\n");
    remove(FILE_NAME);
    printf("file removed.\n");
    return 0;
}

