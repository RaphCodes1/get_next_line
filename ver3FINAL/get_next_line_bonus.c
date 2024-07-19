/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcreer <rcreer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 16:49:38 by rcreer            #+#    #+#             */
/*   Updated: 2024/07/18 18:14:39 by rcreer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	clean_node(t_list **list, int len, int i)
{
	t_list	*last_node;
	t_list	*clean_node;
	char	*buf;

	buf = malloc(BUFFER_SIZE + 1);
	clean_node = malloc(sizeof(t_list));
	if (!buf || !clean_node)
		return ;
	last_node = ft_lstlast(*list);
	while (last_node->content[i] && last_node->content[i] != '\n')
		i++;
	while (last_node->content[i] && last_node->content[i++])
		buf[len++] = last_node->content[i];
	buf[len] = '\0';
	clean_node->content = buf;
	clean_node->next = NULL;
	ft_lstclear(list);
	if (clean_node->content[0])
		*list = clean_node;
	else
	{
		free(buf);
		free(clean_node);
	}
}

char	*get_theline(t_list *list)
{
	int		strlen;
	char	*next_str;

	if (list == NULL)
		return (NULL);
	strlen = lentillnewline(list);
	next_str = malloc(strlen + 1);
	if (!next_str)
		return (NULL);
	copy_str(list, next_str);
	return (next_str);
}

void	ft_appending(t_list **list, char *buf, int fd)
{
	t_list	*new_node;
	t_list	*last_node;

	last_node = ft_lstlast(list[fd]);
	new_node = malloc(sizeof(t_list));
	if (new_node == NULL)
		return ;
	if (last_node == NULL)
		list[fd] = new_node;
	else
		last_node->next = new_node;
	new_node->content = buf;
	new_node->next = NULL;
}

void	list_create(t_list **list, int fd)
{
	int		char_read;
	char	*buf;

	while (!found_newline(list[fd]))
	{
		buf = malloc(BUFFER_SIZE + 1);
		if (buf == NULL)
			return ;
		char_read = read(fd, buf, BUFFER_SIZE);
		if (char_read < 0)
		{
			free(buf);
			free(list);
			return ;
		}
		if (char_read == 0)
		{
			free(buf);
			return ;
		}
		buf[char_read] = '\0';
		ft_appending(list, buf, fd);
	}
}

char	*get_next_line(int fd)
{
	static t_list	*list[1024];
	t_list			*tmp;
	char			*next_line;
	int				loop_through_list;
	int				len_of_nextline;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &next_line, 0) < 0
		|| BUFFER_SIZE >= INT_MAX || fd >= 1024)
	{
		tmp = list[fd];
		ft_lstclear(&tmp);
		list[fd] = tmp;
		free(tmp);
		return (NULL);
	}
	list_create(list, fd);
	if (list[fd] == NULL)
		return (NULL);
	next_line = get_theline(list[fd]);
	if (!next_line)
		return (NULL);
	loop_through_list = 0;
	len_of_nextline = 0;
	clean_node (&list[fd], len_of_nextline, loop_through_list);
	return (next_line);
}
