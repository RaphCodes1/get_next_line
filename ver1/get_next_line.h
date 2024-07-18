#ifndef GET_NEXT_LINE
# define GET_NEXT_LINE


# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <fcntl.h>
# include <limits.h>

# ifndef BUFFER_SIZE
#   define BUFFER_SIZE 10
# endif

typedef struct s_list
{
    char		*content;
    struct s_list *next;
}   			t_list;

char    *get_next_line(int fd);
t_list *ft_lstlast(t_list *lst);
void    ft_append(t_list **list,char *buf);
int     lenTillNewline(t_list *list);
int     found_newline(t_list *list);
void    copy_str(t_list *list, char *str);
void    clean_node(t_list **list);
void    dealloc(t_list **lst, t_list *clean_node, char *buf);
char    *get_line(t_list *list);
#endif