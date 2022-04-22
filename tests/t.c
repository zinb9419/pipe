/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziloughm <ziloughm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 22:34:16 by ziloughm          #+#    #+#             */
/*   Updated: 2022/04/19 15:17:02 by ziloughm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

size_t	ft_strlcat(void *dest, const void *src, size_t n)
{
	size_t	i;
	size_t	j;
	size_t	ld;
	char	*d;
	char	*s;

	s = (char *)src;
	d = (char *)dest;
	i = strlen(d);
	j = 0;
	ld = strlen(d);
	if (n <= 0 || (!dest && !src))
		return (strlen(s));
	while (i < n - 1 && s[j])
	{
		d[i] = s[j];
		i++;
		j++;
	}
	d[i] = '\0';
	if (ld > n)
		return (n + strlen(s));
	else
		return (strlen(s) + ld);
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*p;

	if (!s2 || !s1)
		return (0);
	i = strlen(s1) + strlen(s2) + 1;
	p = (char *)malloc(i * sizeof(char));
	if (!p)
		return (NULL);
	*p = 0;
	j = ft_strlcat(p, s1, i);
	j = ft_strlcat(p, s2, i);
	return (p);
}

int	main(int ac, char **av)
{
	char	*c;

	(void)ac;
	c = ft_strjoin(av[1], av[2]);
	printf("%s\n", c);
	return (0);
}
