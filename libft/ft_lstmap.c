/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/19 20:01:05 by julee             #+#    #+#             */
/*   Updated: 2018/08/16 19:49:31 by julee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *new;
	t_list *first;

	if (!lst || !f)
		return (NULL);
	new = f(lst);
	first = new;
	while (lst->next)
	{
		new->next = f(lst->next);
		new = new->next;
		lst = lst->next;
	}
	return (first);
}
