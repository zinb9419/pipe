/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziloughm <ziloughm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 13:11:45 by ziloughm          #+#    #+#             */
/*   Updated: 2022/04/16 15:23:42 by ziloughm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*p;

	i = 0;
	if (!s)
		return (NULL);
	if (len > (ft_strlen(s) - start))
		len = ft_strlen(s) - start;
	if (start >= ft_strlen(s))
		len = 0;
	p = (char *)malloc((len +1) * sizeof(char));
	if (!p)
		return (NULL);
	*p = 0;
	while (i < len && s[start] != '\0')
	{
		p[i] = s[start];
		i++;
		start++;
	}
	p[i] = '\0';
	return (p);
}
