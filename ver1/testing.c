#include "get_next_line.h"
#include <stdio.h>

int main()
{
    t_list *new_node = ft_lstnew("hello");
    ft_lstadd_back(&new_node,ft_lstnew("there"));
    
    int i = lenTillNewline(new_node);
    char *s3 = malloc(i + 1);
    copy_str(new_node,s3);
    printf("%d\n",i);
    printf("%s\n",s3);
}

// int main()
// {   
//     char buffer[BUFFER_SIZE];
//     int fd = open("example.txt", O_RDONLY);
//     static char *permaHolder;
//     char *tempHolder;
//     char *handler;
//     ssize_t bytesRead;

//     while(!found_newline(tempHolder))
//     {
//         tempHolder = malloc(BUFFER_SIZE + 1);
//         if(!tempHolder)
//             return (0);
//         bytesRead = read(fd, tempHolder, BUFFER_SIZE);
//         if(!bytesRead)
//         {
//             free(tempHolder);
//             return (0);
//         }
//         tempHolder[bytesRead] = '\0';
//         permaHolder = ft_strjoin(buffer,tempHolder);
//     }

//     printf("%s\n",tempHolder);
//     // while((bytesRead = read(fd, buffer, 1024)) > 0)
//     // {   
//     //     printf("%s",buffer);
//     // }
    

    

// }