/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 22:08:21 by julee             #+#    #+#             */
/*   Updated: 2018/11/04 14:23:45 by julee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "./minilibx_macos/mlx.h"
# include "./libft/libft.h"
# include <stdio.h>
# include <math.h>
# include <string.h>
# include <errno.h>

typedef struct		s_co
{
	int				x;
	int				y;
}					t_co;

typedef struct		s_line_elem
{
	int				dx;
	int				dy;
	int				sx;
	int				sy;
	int				err;
	int				e2;
}					t_line_elem;

typedef struct		s_struct2
{
	void			*mlx_ptr;
	void			*win_ptr;
	void			*img_ptr;
	char			*img_addr;
	int				bpp;
	int				size_line;
	int				endian;
	unsigned int	color;
	int				map_height;
	int				map_width;
	int				**z;
	double			n;
}					t_mlx_struct;

int					key_press(int key, void *ptr);
int					close_window(void *param);

void				draw_line(t_mlx_struct *mlx, t_co prev, t_co curr,
					t_co index);
void				draw_dot_basic(t_mlx_struct *mlx, int x, int y, int color);
void				draw_horizontal(t_mlx_struct *mlx);
void				draw_vertical(t_mlx_struct *mlx);
void				place_line(t_mlx_struct *mlx);

void				rotate_coordinate(t_mlx_struct *mlx, int *x, int *y, int z);
int					refresh_window(void *ptr);
void				make_img(char *map);

int					check_mapsize(char *map, t_mlx_struct *mlx);
void				store_z(char *map, t_mlx_struct *mlx);
int					extract_int(char **line);
void				map_allocation(t_mlx_struct *mlx);
void				width_check(t_mlx_struct *mlx, char *line);

#endif
