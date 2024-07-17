#ifndef GET_NEXT_LINE
# define GET_NEXT_LINE


# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <fcntl.h>

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
void    ft_lstadd_back(t_list **lst, t_list *new);
void    ft_append(t_list **list,char *buf);
t_list	*ft_lstnew(void *content);
char	*ft_strjoin(char const *s1, char const *s2);
int     lenTillNewline(t_list *list);
int     found_newline(t_list *list);
void    copy_str(t_list *list, char *str);
void	ft_lstclear(t_list **lst, void (*del)(void*));
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void    my_del(void *content);
void    clean_node(t_list **list);
void    dealloc(t_list **lst, t_list *clean_node, char *buf);
#endif