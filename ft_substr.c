/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsulzbac <lsulzbac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 19:08:56 by lsulzbac          #+#    #+#             */
/*   Updated: 2022/05/16 13:52:32 by lsulzbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include <stddef.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;
	size_t	max;

	i = 0;
	max = ft_strlen(s);
	if (start >= max)
		sub = (char *) malloc (1);
	else if (start + len >= max)
		sub = (char *) malloc (max - start + 1);
	else
		sub = (char *) malloc (len + 1);
	if (sub != NULL)
	{
		while (i < len && start < max)
		{
			sub[i] = s[start];
			i++;
			start++;
		}
		sub [i] = '\0';
	}
	return (sub);
}
