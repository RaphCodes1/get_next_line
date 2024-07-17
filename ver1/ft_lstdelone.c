/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcreer <rcreer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 16:01:14 by rcreer            #+#    #+#             */
/*   Updated: 2024/07/01 15:33:27 by rcreer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!del || !lst)
		return ;
	if (lst)
	{
		(*del)(lst->content);
		free(lst);
	}
}

void my_del(void *content)
{
	free(content);
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
// 	ft_lstdelone(s1,&my_del);

// 	ft_lstadd_back(&s1,ft_lstnew("orange"));
// 	while(s1)
// 	{
// 		printf("\n%s\n",(char *)s1->content);
// 		s1 = s1->next;
// 	}
// }
