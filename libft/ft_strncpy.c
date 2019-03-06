/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/11 11:24:50 by julee             #+#    #+#             */
/*   Updated: 2018/08/09 14:24:16 by julee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	char *ptr;

	ptr = dst;
	while (*src && len > 0)
	{
		*dst++ = *src++;
		len--;
	}
	while (len-- > 0)
		*dst++ = '\0';
	return (ptr);
}
