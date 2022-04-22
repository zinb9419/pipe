/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziloughm <ziloughm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 17:53:43 by ziloughm          #+#    #+#             */
/*   Updated: 2022/04/16 15:28:08 by ziloughm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

size_t	ft_strlcat(void *dest, const void *src, size_t n)
{
	size_t	i;
	size_t	j;
	size_t	ld;
	char	*d;
	char	*s;

	s = (char *)src;
	d = (char *)dest;
	i = ft_strlen(d);
	j = 0;
	ld = ft_strlen(d);
	if (n <= 0 || (!dest && !src))
		return (ft_strlen(s));
	while (i < n - 1 && s[j])
	{
		d[i] = s[j];
		i++;
		j++;
	}
	d[i] = '\0';
	if (ld > n)
		return (n + ft_strlen(s));
	else
		return (ft_strlen(s) + ld);
	return (i);
}
