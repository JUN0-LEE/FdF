/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 21:12:04 by julee             #+#    #+#             */
/*   Updated: 2019/03/03 17:06:14 by julee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	rotate_coordinate(t_mlx_struct *mlx, int *x, int *y, int z)
{
	int		px;
	int		py;

	px = *x;
	py = *y;
	*x = (px - py) * cos(0.46373398) - 1300;
	*y = -z * (mlx->n) + (px + py) * sin(0.46373398) + 400;
	if (*y < 0)
		*y = 0;
	else if (*y > 2600)
		*y = 2600;
}

int		refresh_window(void *ptr)
{
	t_mlx_struct	*mlx;

	mlx = (t_mlx_struct *)ptr;
	if (mlx->img_ptr != NULL)
		mlx_destroy_image(mlx->mlx_ptr, mlx->img_ptr);
	mlx->img_ptr = mlx_new_image(mlx->mlx_ptr, 2600, 2600);
	place_line(mlx);
	return (0);
}

void	make_img(char *map)
{
	t_mlx_struct	mlx;

	ft_memset(&mlx, 0, sizeof(t_mlx_struct));
	if (check_mapsize(map, &mlx) == 0)
		return ;
	store_z(map, &mlx);
	mlx.mlx_ptr = mlx_init();
	mlx.win_ptr = mlx_new_window(mlx.mlx_ptr, 2600, 2600, "NEW WINDOW");
	mlx.img_ptr = mlx_new_image(mlx.mlx_ptr, 2600, 2600);
	place_line(&mlx);
	mlx.n = 5;
	mlx_hook(mlx.win_ptr, 2, 0, &key_press, &mlx);
	mlx_hook(mlx.win_ptr, 17, 0, close_window, (void *)0);
	mlx_loop_hook(mlx.mlx_ptr, &refresh_window, &mlx);
	mlx_loop(mlx.mlx_ptr);
}

int		main(int argc, char **argv)
{
	if (argc == 2)
		make_img(argv[1]);
	else
		ft_putstr("usage : ./fdf map.fdf\n");
}
