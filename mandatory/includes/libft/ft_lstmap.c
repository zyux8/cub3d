/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohaker <ohaker@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 20:26:58 by ohaker            #+#    #+#             */
/*   Updated: 2024/11/23 16:15:52 by ohaker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlst;
	t_list	*node;

	newlst = NULL;
	while (lst)
	{
		node = malloc(sizeof(t_list));
		if (!node)
		{
			ft_lstclear(&newlst, (*del));
			return (NULL);
		}
		node->content = f(lst->content);
		node->next = NULL;
		ft_lstadd_back(&newlst, node);
		lst = lst->next;
	}
	return (newlst);
}
/* Creates a new list with the nodes being the nodes from the old function,
	applied with a function. */