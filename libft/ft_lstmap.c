/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinto <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 11:45:35 by apinto            #+#    #+#             */
/*   Updated: 2021/02/23 06:20:03 by apinto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list *new_node;
	t_list *begg;

	if (!f || !del)
		return (0);
	begg = 0;
	while (lst)
	{
		new_node = ft_lstnew(f(lst->content));
		if (!(new_node))
		{
			ft_lstclear(&begg, del);
			return (0);
		}
		ft_lstadd_back(&begg, new_node);
		lst = lst->next;
	}
	return (begg);
}
