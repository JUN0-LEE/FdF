/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/11 22:45:04 by julee             #+#    #+#             */
/*   Updated: 2018/08/09 13:39:34 by julee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*str;

	str = (char *)s;
	i = 0;
	if ((char)c == '\0')
	{
		while (str[i])
			i++;
		return (&str[i]);
	}
	while (str[i] && ((char)c != str[i]))
		i++;
	if (str[i] == '\0')
		return (NULL);
	else
		return (&str[i]);
}
