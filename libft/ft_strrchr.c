/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/11 09:53:39 by julee             #+#    #+#             */
/*   Updated: 2018/07/17 19:53:38 by julee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t l;

	l = ft_strlen(s);
	while (l > 0 && (char)c != (char)s[l])
		l--;
	if ((char)s[l] == (char)c)
		return ((char *)&s[l]);
	return (NULL);
}
