/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 19:59:23 by julee             #+#    #+#             */
/*   Updated: 2018/09/18 21:52:53 by julee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int		ft_word_count(char const *s, char c)
{
	int wd;

	wd = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s == '\0')
			return (wd);
		while (*s && *s != c)
			s++;
		wd++;
	}
	return (wd);
}

char			**ft_strsplit(char const *s, char c)
{
	char		**array;
	int			i;
	int			wd;
	int			ch;

	if (!s || !c)
		return (NULL);
	wd = ft_word_count(s, c);
	if (!(array = (char **)malloc(sizeof(char *) * (wd + 1))))
		return (NULL);
	array[wd--] = NULL;
	i = (int)ft_strlen(s) - 1;
	while (wd >= 0)
	{
		while (s[i] == c && i >= 0)
			i--;
		ch = 0;
		while (s[i] != c && i >= 0)
		{
			i--;
			ch++;
		}
		array[wd--] = ft_strsub(s, i + 1, ch);
	}
	return (array);
}
