/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmedeiro <mmedeiro@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 12:28:44 by mmedeiro          #+#    #+#             */
/*   Updated: 2022/05/30 12:34:27 by mmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*pointer;

	new = ft_lstnew((*f)(lst->content));
	if (!new)
		return (new);
	pointer = new;
	lst = lst->next;
	while (lst != NULL)
	{
		new->next = ft_lstnew((*f)(lst->content));
		if (!new->next)
		{
			ft_lstclear (&pointer, del);
			return (NULL);
		}
		new = new->next;
		lst = lst->next;
	}
	return (pointer);
}
