/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziloughm <ziloughm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 16:11:16 by ziloughm          #+#    #+#             */
/*   Updated: 2022/04/19 15:13:48 by ziloughm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*p;

	if (!s2 || !s1)
		return (0);
	i = ft_strlen(s1) + ft_strlen(s2) + 1;
	p = (char *)malloc(i * sizeof(char));
	if (!p)
		return (NULL);
	*p = 0;
	j = ft_strlcat(p, s1, i);
	j = ft_strlcat(p, s2, i);
	return (p);
}
