/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/11 12:36:05 by julee             #+#    #+#             */
/*   Updated: 2018/08/09 14:22:36 by julee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t dstsize)
{
	size_t i;
	size_t j;

	i = 0;
	if (dstsize == 0)
		return (ft_strlen(src));
	while (dest[i] && i < dstsize)
		i++;
	j = i;
	while (src[i - j] && i < dstsize - 1)
	{
		dest[i] = src[i - j];
		i++;
	}
	if (j < dstsize)
		dest[i] = '\0';
	return (j + ft_strlen(src));
}
