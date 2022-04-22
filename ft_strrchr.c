/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziloughm <ziloughm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 20:29:13 by ziloughm          #+#    #+#             */
/*   Updated: 2022/04/20 12:34:35 by ziloughm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_strrchr(const char *str, int c)
{
	int		i;
	char	*p;

	p = (char *)str;
	c = (char)c;
	i = ft_strlen(p);
	while (i >= 0)
	{
		if (p[i] == c)
			return (p + i);
		i--;
	}
	return (0);
}
