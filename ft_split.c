/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsulzbac <lsulzbac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 18:19:08 by lsulzbac          #+#    #+#             */
/*   Updated: 2022/05/18 18:47:46 by lsulzbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static size_t	count_words(char const *s, char c)
{
	size_t	i;
	size_t	words;

	i = 0;
	words = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
		{
			words++;
			while (s[i] == c)
				i++;
		}
		i++;
	}
	words++;
	return (words);
}

void	set_words(char **r, char const *s, size_t size, char c)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	j = 0;
	k = 0;
	while (i < size - 1)
	{
		k = j;
		while(s[j] != c && s[j] != '\0')
		{
			j++;
		}
		r[i] = ft_substr(s, k, j - k);
		while (s[j] == c)
			j++;
		i++;
	}
	r[i] = NULL;
}

char	**ft_split(char const *s, char c)
{
	char	**r;
	char	*trim;
	char	*test;
	size_t	words;

	test = (char *) malloc (2);
	if (test == NULL)
	{
		return (NULL);
	}
	test[0] = c;
	test[1] = '\0';
	trim = ft_strtrim(s, test);
	free(test);
	if (ft_strlen(trim) == 0)
	{
		r = (char **) malloc (sizeof(char *));
		words = 0;
	}
	else
	{
		words = count_words(trim, c);
		r = (char **) malloc (sizeof(char *) * (words + 1));
	}
	if (r != NULL)
	{
		set_words(r, trim, words + 1, c);
	}
/*	ft_putstr_fd((char *)s, 1);
	ft_putchar_fd('\n', 1);
	ft_putstr_fd(trim, 1);
	ft_putchar_fd('\n', 1);
	ft_putnbr_fd(words, 1);
	ft_putchar_fd('\n', 1);
	size_t i = 0;
	char print;
	while (i <= words)
	{
		print = i + '0';
		ft_putchar_fd(print, 1);
		ft_putstr_fd(" - ", 1);
		if (r[i] == NULL )
			ft_putstr_fd("vazio", 1);
		else
			ft_putstr_fd(r[i], 1);
		ft_putchar_fd('\n', 1);
		i++;
	}
*/
	free(trim);
	return (r);
}

/*int	main(int argc, char **argv)
{
	int	i = 1;

	if (argc < 2)
		ft_split(" this is a test string    ", ' ');
	else
		while (i < argc)
		{
			ft_split(argv[i], argv[i + 1][0]);
			ft_putchar_fd('\n', 1);
			ft_putstr_fd("--------**---------", 1);
			ft_putchar_fd('\n', 1);
			i += 2;
		}
}*/
