/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recog_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 14:58:16 by julee             #+#    #+#             */
/*   Updated: 2019/03/03 17:14:29 by julee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	width_check(t_mlx_struct *mlx, char *line)
{
	if (line == NULL)
		return ;
	while (*line)
	{
		while (*line == ' ')
			line++;
		if (*line)
			mlx->map_width++;
		while (*line && *line != ' ')
			line++;
	}
}

void	map_allocation(t_mlx_struct *mlx)
{
	int		i;

	mlx->z = (int **)malloc(sizeof(int *) * mlx->map_height);
	i = 0;
	while (i < mlx->map_height)
		mlx->z[i++] = (int *)malloc(sizeof(int) * mlx->map_width);
}

int		extract_int(char **line)
{
	int		sign;
	int		num;

	sign = 1;
	num = 0;
	while (**line == ' ')
		(*line)++;
	if (**line == '-')
		sign = -1;
	if (**line == '-' || **line == '+')
		(*line)++;
	while (**line && ('0' <= **line && **line <= '9'))
	{
		num = num * 10 + **line - '0';
		(*line)++;
	}
	if (**line == ',')
		while (**line && (**line != ' '))
			(*line)++;
	return (sign * num);
}

void	store_z(char *map, t_mlx_struct *mlx)
{
	int		fd;
	int		i;
	int		j;
	char	*line;

	if ((fd = open(map, O_RDONLY)) == -1)
		return ;
	map_allocation(mlx);
	i = 0;
	while (get_next_line(fd, &line) > 0)
	{
		j = -1;
		while (++j < mlx->map_width)
			mlx->z[i][j] = extract_int(&line);
		i++;
	}
}

int		check_mapsize(char *map, t_mlx_struct *mlx)
{
	int		fd;
	char	*line;

	if ((fd = open(map, O_RDONLY)) == -1)
	{
		ft_putendl(strerror(errno));
		return (0);
	}
	mlx->map_height = 0;
	mlx->map_width = 0;
	while (get_next_line(fd, &line))
	{
		if (mlx->map_width == 0)
			width_check(mlx, line);
		mlx->map_height++;
	}
	close(fd);
	return (1);
}
