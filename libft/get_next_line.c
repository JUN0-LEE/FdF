/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 18:24:54 by julee             #+#    #+#             */
/*   Updated: 2018/09/24 18:52:42 by julee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			get_next_line(int fd, char **line)
{
	static char	*str[65535];
	char		buf[BUFF_SIZE + 1];
	char		*ptr;
	int			len;

	if (!line || read(fd, buf, 0) < 0)
		return (-1);
	str[fd] = str[fd] ? str[fd] : ft_strnew(0);
	while (!ft_strrchr(str[fd], '\n') && (len = read(fd, buf, BUFF_SIZE)))
	{
		buf[len] = '\0';
		ptr = str[fd];
		str[fd] = ft_strjoin(ptr, buf);
		ft_strdel(&ptr);
	}
	if (!str[fd] || !*str[fd])
		return (0 && (*line = ft_strnew(0)));
	*line = str[fd];
	ptr = ft_strchr(str[fd], '\n');
	str[fd] = (ptr) ? ft_strdup(ptr + 1) : NULL;
	if (ptr)
		*ptr = '\0';
	return (1);
}
