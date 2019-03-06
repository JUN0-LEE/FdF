/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/28 20:17:00 by julee             #+#    #+#             */
/*   Updated: 2018/11/02 17:06:55 by julee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	place_line(t_mlx_struct *mlx)
{
	draw_horizontal(mlx);
	draw_vertical(mlx);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img_ptr, 0, 0);
}

void	draw_vertical(t_mlx_struct *mlx)
{
	t_co	index;
	t_co	prev;
	t_co	curr;

	index.x = -1;
	while (++(index.x) < mlx->map_width)
	{
		index.y = -1;
		while (++(index.y) < mlx->map_height - 1)
		{
			prev.x = (((double)index.x + 1)
					/ ((double)mlx->map_width + 20)) * 1500;
			prev.y = (((double)index.y + 1)
					/ ((double)mlx->map_height + 20)) * 1500;
			rotate_coordinate(mlx, &(prev.x), &(prev.y),
					mlx->z[index.y][index.x]);
			curr.x = (((double)index.x + 1)
					/ ((double)mlx->map_width + 20)) * 1500;
			curr.y = (((double)index.y + 2)
					/ ((double)mlx->map_height + 20)) * 1500;
			rotate_coordinate(mlx, &(curr.x), &(curr.y),
					mlx->z[index.y + 1][index.x]);
			draw_line(mlx, prev, curr, index);
		}
	}
}

void	draw_horizontal(t_mlx_struct *mlx)
{
	t_co	index;
	t_co	prev;
	t_co	curr;

	index.y = -1;
	while (++(index.y) < mlx->map_height)
	{
		index.x = -1;
		while (++(index.x) < mlx->map_width - 1)
		{
			prev.x = (((double)index.x + 1)
					/ ((double)mlx->map_width + 20)) * 1500;
			prev.y = (((double)index.y + 1)
					/ ((double)mlx->map_height + 20)) * 1500;
			rotate_coordinate(mlx, &(prev.x), &(prev.y),
					mlx->z[index.y][index.x]);
			curr.x = (((double)index.x + 2)
					/ ((double)mlx->map_width + 20)) * 1500;
			curr.y = (((double)index.y + 1)
					/ ((double)mlx->map_height + 20)) * 1500;
			rotate_coordinate(mlx, &(curr.x), &(curr.y),
					mlx->z[index.y][index.x + 1]);
			draw_line(mlx, prev, curr, index);
		}
	}
}

void	draw_dot_basic(t_mlx_struct *mlx, int x, int y, int color)
{
	int	i;

	i = 0;
	mlx->img_addr = mlx_get_data_addr(mlx->img_ptr,
			&(mlx->bpp), &(mlx->size_line), &(mlx->endian));
	mlx->color = mlx_get_color_value(mlx->mlx_ptr, color);
	while (i < mlx->bpp / 8)
	{
		*(mlx->img_addr + (mlx->size_line * y
					+ (mlx->bpp * x) / 8) + i) = mlx->color >> (8 * i) & 0xFF;
		i++;
	}
}

void	draw_line(t_mlx_struct *mlx, t_co prev, t_co curr, t_co index)
{
	t_line_elem	e;

	(void)index;
	e.dx = (curr.x - prev.x > 0) ? curr.x - prev.x : prev.x - curr.x;
	e.dy = (curr.y - prev.y > 0) ? curr.y - prev.y : prev.y - curr.y;
	e.sx = prev.x < curr.x ? 1 : -1;
	e.sy = prev.y < curr.y ? 1 : -1;
	e.err = (e.dx > e.dy ? e.dx : -e.dy) / 2;
	while (1)
	{
		draw_dot_basic(mlx, prev.x, prev.y, 0x00FFFF);
		if (prev.x == curr.x && prev.y == curr.y)
			break ;
		e.e2 = e.err;
		if (e.e2 > -e.dx)
		{
			e.err -= e.dy;
			prev.x += e.sx;
		}
		if (e.e2 < e.dy)
		{
			e.err += e.dx;
			prev.y += e.sy;
		}
	}
}
