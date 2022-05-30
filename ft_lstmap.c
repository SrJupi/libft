/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsulzbac <lsulzbac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 15:43:08 by lsulzbac          #+#    #+#             */
/*   Updated: 2022/05/30 18:29:04 by lsulzbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*prev;

	new_list = NULL;
	prev = NULL;
	if (lst != NULL)
	{
		prev = (t_list *) malloc (sizeof(t_list));
		if (prev == NULL)
			return (NULL);
		prev->next = NULL;
		prev->content = (*f)(lst->content);
		new_list = prev;
		lst = lst->next;
		while (lst)
		{
			prev->next = (t_list *) malloc (sizeof(t_list));
			//erro allocacao com ft_lstnew - rever
			if (prev->next == NULL)
			{
				ft_lstclear(&new_list, (*del));
				return (NULL);
			}
			prev->next->next = NULL;
			prev->next->content = (*f)(lst->content);
			prev = prev->next;
			lst = lst->next;
		}
	}
	return (new_list);
}
