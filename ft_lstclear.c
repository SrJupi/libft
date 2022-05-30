/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsulzbac <lsulzbac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 14:32:37 by lsulzbac          #+#    #+#             */
/*   Updated: 2022/05/30 18:13:27 by lsulzbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp;
	t_list	*erase;

	erase = *lst;
	while (erase != NULL)
	{
		(*del)(erase->content);
		temp = erase->next;
		free(erase);
		erase = temp;
	}
	*lst = NULL;
}
