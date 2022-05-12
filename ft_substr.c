/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsulzbac <lsulzbac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 19:08:56 by lsulzbac          #+#    #+#             */
/*   Updated: 2022/05/11 20:24:57 by lsulzbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include <stddef.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;

	i = 0;
	if (len == SIZE_MAX)
		sub = (char *) malloc (1000000);
	else
		sub = (char *) malloc (len + 1);
	if (sub != NULL)
	{
		while (i < len && start <= ft_strlen(s))
		{
			sub[i] = s[start];
			i++;
			start++;
		}
		sub [i] = '\0';
	}
	return (sub);
}
