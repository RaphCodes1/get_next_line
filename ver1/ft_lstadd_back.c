/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcreer <rcreer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 15:55:39 by rcreer            #+#    #+#             */
/*   Updated: 2024/06/25 15:56:44 by rcreer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	if (*lst)
		ft_lstlast(*lst)->next = new;
	else
		*lst = new;
}

// int main()
// {
// 	t_list *s1 = ft_lstnew("Hello there");
// 	ft_lstadd_back(&s1,ft_lstnew("Raph"));

// 	while(s1)
// 	{
// 		printf("%s ",(char *)s1->content);
// 		s1 = s1->next;
// 	}
	
// }
