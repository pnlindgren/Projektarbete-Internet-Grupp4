#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#define FILE_NAME "/home/me/pid/startdem.pid"

int main(int argc, char *argv[])
{
    FILE *fp = fopen(FILE_NAME, "r");
    if(fp != NULL)
    {
        perror("Server allready running.\n");
        fclose(fp);
	exit(1);
    }

    if(argc == 1)
    {
        execlp("/bin/sh", "/sh", "-c", "./server", NULL);
        perror("start: execlp()\n");
        exit(1);
    } else
    {
        printf("Too many arguments.\n");
    }
    return 0;
}

