#include "get_next_line.h"
#include <errno.h>
char *get_next_line(int fd)
{   
    char buffer[256];
    int toRead;

    while((toRead = read(fd,buffer,5)))
    {   
        buffer[toRead] = '\0';
        printf("buffer -> %s\n",buffer);
    }
    return ("works");
}

int main()
{
    int fd = open("bruh.txt", O_RDONLY);
    char buffer[256];
    if(fd == -1)
        perror("error opening file");
    get_next_line(fd);

    // int i = read(fd,buffer,10);
    // printf("%d\n",i);

    return (0);
}