/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziloughm <ziloughm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 00:25:52 by ziloughm          #+#    #+#             */
/*   Updated: 2022/04/27 00:30:07 by ziloughm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	int	p1;
	int	p2;

	p1 = fork();
	if (p1 == 0)
		printf("child1\n");
	p2 = fork();
	if (p2 == 0)
		printf("child2\n");
	printf("processs\n");
}
