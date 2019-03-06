/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/28 19:53:16 by julee             #+#    #+#             */
/*   Updated: 2018/11/02 17:06:43 by julee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		key_press(int key, void *ptr)
{
	t_mlx_struct	*mlx;

	mlx = (t_mlx_struct *)ptr;
	if (key == 53)
		exit(0);
	if (key == 69 || key == 24)
		mlx->n += 1;
	if (key == 78 || key == 27)
		mlx->n -= 1;
	return (0);
}

int		close_window(void *param)
{
	(void)param;
	exit(0);
	return (0);
}
