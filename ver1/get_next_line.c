#include "get_next_line.h"

void clean_node(t_list **list)
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
    last_node = ft_lstlast(*list);
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
    dealloc(list,clean_node,buf);
}
char *get_line(t_list *list)
{
    int strlen;
    char *next_str;

    if(list == NULL)
        return (NULL);
    strlen = lenTillNewline(list);
    next_str = malloc(strlen + 1);
    if(!next_str)
        return (NULL);
    copy_str(list,next_str);
    return (next_str);
}
void ft_append(t_list **list,char *buf)
{
    t_list *new_node;
    t_list *last_node;

    last_node = ft_lstlast(*list);
    new_node = malloc(sizeof(t_list));
    if(new_node == NULL)
        return ;
    if(last_node == NULL)
        *list = new_node;
    else
        last_node->next = new_node;
    new_node->content = buf;
    new_node->next = NULL;
}

void list_create(t_list **list, int fd)
{
    int char_read;
    char *buf;

    while(!found_newline(*list))
    {
        buf = malloc(BUFFER_SIZE + 1);
        if(buf == NULL)
            return ;
        char_read = read(fd, buf, BUFFER_SIZE);
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
	next_line = get_line(list);
    clean_node(&list);
    return (next_line);
}


