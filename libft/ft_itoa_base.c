/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/16 19:13:15 by julee             #+#    #+#             */
/*   Updated: 2018/09/16 19:48:26 by julee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa_base(int n, int base)
{
	int		i;
	int		sign;
	char	s[50];

	i = 49;
	sign = 1;
	s[i--] = '\0';
	if (n < 0)
		sign = -1;
	if (n == 0)
		s[i--] = '0';
	while (n)
	{
		if (sign == 1)
			s[i--] = (n % base < 10) ? n % base + '0' : n % base - 10 + 'a';
		else if (sign == -1)
			s[i--] = (-(n % base) < 10) ?
				-(n % base) + '0' : -(n % base) - 10 + 'a';
		n /= base;
	}
	if (sign == -1)
		s[i--] = '-';
	return (ft_strdup(&s[++i]));
}
