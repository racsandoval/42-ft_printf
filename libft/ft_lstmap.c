/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsandova <rsandova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 17:40:19 by rsandova          #+#    #+#             */
/*   Updated: 2020/01/23 19:29:03 by rsandova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*resp;
	t_list	*elem;

	if (!lst || !f || !del)
		return (NULL);
	resp = NULL;
	while (lst)
	{
		elem = ft_lstnew(f(lst->content));
		if (!elem)
		{
			ft_lstclear(&resp, del);
			return (NULL);
		}
		ft_lstadd_back(&resp, elem);
		lst = lst->next;
	}
	return (resp);
}
