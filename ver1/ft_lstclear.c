/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcreer <rcreer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 15:59:58 by rcreer            #+#    #+#             */
/*   Updated: 2024/06/25 16:01:08 by rcreer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*node;

	node = *lst;
	if (!del || !lst || !*lst)
		return ;
	while (lst && *lst)
	{
		node = node->next;
		ft_lstdelone(*lst, del);
		*lst = node;
	}
}
// int main()
// {
// 	t_list *s1 = ft_lstnew("hello there");
// 	ft_lstadd_back(&s1,ft_lstnew("banana"));

// 	while(s1)
// 	{
// 		printf("%s,",(char *)s1->content);
// 		s1 = s1->next;
// 	}

// 	ft_lstclear(&s1,&my_del2);

// 	while(s1)
// 	{
// 		printf("%s,",(char *)s1->content);
// 		s1 = s1->next;
// 	}
// }
