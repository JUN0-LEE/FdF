/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/11 15:32:14 by julee             #+#    #+#             */
/*   Updated: 2018/09/16 20:57:08 by julee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	int digit;
	int sign;

	sign = 1;
	if (n < 0)
		sign = -1;
	digit = n % 10;
	if (digit != n)
	{
		ft_putnbr(n / 10);
		if (sign < 0)
			ft_putchar('0' + digit * sign);
		else
			ft_putchar('0' + digit);
	}
	else
	{
		if (sign < 0)
			ft_putchar('-');
		ft_putchar('0' + digit * sign);
	}
}
