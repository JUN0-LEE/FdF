/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 11:16:18 by julee             #+#    #+#             */
/*   Updated: 2018/08/01 20:42:05 by julee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int sign;
	int digit;

	sign = 1;
	digit = n % 10;
	if (n < 0)
		sign = -1;
	if (digit != n)
	{
		ft_putnbr_fd(n / 10, fd);
		if (sign < 0)
			ft_putchar_fd('0' + digit * sign, fd);
		else
			ft_putchar_fd('0' + digit, fd);
	}
	else
	{
		if (sign < 0)
			ft_putchar_fd('-', fd);
		ft_putchar_fd('0' + digit * sign, fd);
	}
}
