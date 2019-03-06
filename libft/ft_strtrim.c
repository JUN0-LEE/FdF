/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 17:47:42 by julee             #+#    #+#             */
/*   Updated: 2018/09/16 18:40:29 by julee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		i;
	int		j;

	if (s == NULL)
		return (NULL);
	i = 0;
	while (ft_isspace(s[i]))
		i++;
	if (s[i] == '\0')
		return (ft_strnew(0));
	j = (int)ft_strlen(s) - 1;
	while (ft_isspace(s[j]))
		j--;
	return (ft_strsub(s, i, j - i + 1));
}
