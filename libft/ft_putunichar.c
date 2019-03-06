/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunichar.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/16 19:05:11 by julee             #+#    #+#             */
/*   Updated: 2018/09/16 19:10:42 by julee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		byte_calculator(int n)
{
	int i;

	i = 0;
	while (n)
	{
		n /= 64;
		i++;
	}
	return (i);
}

static int		byte_header(int byte)
{
	int		res;
	int		header;
	int		i;

	i = 0;
	res = 0;
	header = 128;
	while (i < byte)
	{
		res += header;
		header /= 2;
		i++;
	}
	return (res);
}

void			ft_putunichar(int n)
{
	int				byte;
	unsigned char	*str;
	int				i;

	if (ft_isprint(n))
	{
		ft_putchar(n);
		return ;
	}
	byte = byte_calculator(n);
	str = (unsigned char *)malloc(sizeof(unsigned char) * (byte + 1));
	str[byte] = '\0';
	i = byte - 1;
	while (n)
	{
		str[i--] = n % 64;
		n /= 64;
	}
	i = 1;
	while (i < byte)
		str[i++] += 128;
	str[0] += byte_header(byte);
	write(1, str, byte);
	free(str);
}
