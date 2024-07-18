#include "get_next_line.h"
#include <stdio.h>

t_list *get_theLast(t_list *list)
{
    if(!list)
        return (NULL);
    while(list->next)
        list = list->next;
    return (list);
}
int findingNewLine(t_list *list)
{
    int i;
    while(list)
    {
        i = 0;
        while(list->content[i] && i < BUFFER_SIZE)
        {   
            if(list->content[i] == '\n')
                return (1);
            i++;
        }
        list = list->next;
    }
    return (0);
}
int lenTillTheNEWLINE(t_list *list)
{
    int i;
    int len;

    len = 0;
    while(list)
    {
        i = 0;
        while(list->content[i])
        {   
            if(list->content[i] == '\n')
            {
                len++;
                return(len);
            }
            i++;
            len++;
        }
        list = list->next;
    }
    return(len);
}

void resetAfterNextLine(t_list **list,t_list *clean_node,char *buf)
{
    int i;
    t_list *tmp;

    i = 0;
    if(list == NULL)
        return ;
    while(*list)
    {
        tmp = (*list)->next;
        free((*list)->content);
        free(*list);
        *list = tmp;
    }
    *list = NULL;
    if(clean_node->content[0])
        *list = clean_node;
    else
    {
        free(buf);
        free(clean_node);
    }

}
void polish_node(t_list **list)
{
    t_list *last_node;
    t_list *clean_node;
    int i;
    int len;
    char *buf;

    buf = malloc(BUFFER_SIZE + 1);
    clean_node = malloc(sizeof(t_list));
    if(!buf || !clean_node)
        return ;
    last_node = get_theLast(*list);
    i = 0;
    len = 0;
    while(last_node->content[i] && last_node->content[i] != '\n')
        i++;
    while(last_node->content[i])
    {
        i++;
        buf[len++] = last_node->content[i];
    }
    buf[len] = '\0';
    clean_node->content = buf;
    clean_node->next = NULL;
    resetAfterNextLine(list,clean_node,buf);
}
char *getTheLINE (t_list *list)
{   
    char *new_str;
    int strlen;
    int i;
    int len; 

    strlen = lenTillTheNEWLINE(list);
    new_str = malloc(strlen + 1);
    if(!new_str)
        return (NULL);
    len = 0;
    while(list)
    {
        i = 0; 
        while(list->content[i])
        {
            if(list->content[i] == '\n')
            {
                new_str[len++] = '\n';
                new_str[len] = '\0';
                return (new_str);
            }
            new_str[len++] = list->content[i++];
        }
        list = list->next;
    }
    new_str[len] = '\0';
    return(new_str);
}

void ft_append(t_list **list,char *buf)
{
    t_list *new_node;
    t_list *last_node;

    last_node = get_theLast(*list);
    new_node = malloc(sizeof(t_list));
    if(!new_node)
        return ;
    if(!last_node)
        *list = new_node;
    else
        last_node->next = new_node;
    new_node->content = buf;
    new_node->next = NULL;

}
void list_create(t_list **list,int fd)
{
    char *buf;
    int char_read;

    while(!findingNewLine(*list))
    {
        buf = malloc(BUFFER_SIZE + 1);
        if(!buf)
            return ;
        char_read = read(fd,buf,BUFFER_SIZE);
        if(!char_read)
        {
            free(buf);
            return ;
        }
        buf[char_read] = '\0';
        ft_append(list,buf);
    }
}

char *get_next_line(int fd)
{   
   static t_list *list;
   char *next_line;

   if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &next_line, 0) < 0 || BUFFER_SIZE >= INT_MAX)
        return (NULL);
   list_create(&list, fd);
   if(list == NULL)
		return (NULL);
	next_line = getTheLINE(list);
    polish_node(&list);
    return (next_line);
}

int main()
{   

    int fd = open("example.txt", O_RDONLY);
    char *lines;
    int i = 1;
    
    while((lines = get_next_line(fd)))
    {
        printf("%d: %s\n",i++,lines);
    }
    
}