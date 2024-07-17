/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcreer <rcreer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 16:41:53 by rcreer            #+#    #+#             */
/*   Updated: 2024/06/25 16:42:46 by rcreer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*node_new;

	node_new = (t_list *)malloc(sizeof(t_list));
	if (node_new == NULL)
		return (NULL);
	node_new->content = content;
	node_new->next = NULL;
	return (node_new);
}
// int main()
// {
// 	t_list *lst = ft_lstnew("hello");
// 	printf("%s\n",(char *)lst->content);
// }