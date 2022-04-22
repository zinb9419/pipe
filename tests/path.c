/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziloughm <ziloughm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 18:00:09 by ziloughm          #+#    #+#             */
/*   Updated: 2022/04/22 15:19:39 by ziloughm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

#include <errno.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>

void	pipex(int ac, char **av, int *fds)
{
	int	end[2];
	int	i;
	int	status;
	int	pid;
	int	fd;

	i = 1;
	fd = fds[0];
	while (i < ac)
	{
		pid = fork();
		if (pid == -1)
			exit(EXIT_FAILURE);
		if (pid == 0)
		{
			if (fd < 0)
			{
				printf("bad file descreptor\n");
				exit(EXIT_FAILURE);
			}
			pipe(end);
			dup2(fd, STDIN_FILENO);
			if (i < ac - 1)
				dup2(end[1], STDOUT_FILENO);
			else
				dup2(fds[1], STDOUT_FILENO);
			close(end[0]);
			close(fd);
			fd = end[1];
			execlp(av[i], av[i], (char *) NULL);
		}
		waitpid(0, &status, 0);
		++i;
	}
	close (end[0]);
	close (end[1]);
}

int	main(int ac, char **av, char **env)
{
	int	fds[2];

	fds[0] = open(av[1], O_RDONLY);
	fds[1] = open(av[ac - 1], O_CREAT | O_RDWR | O_TRUNC, 0644);
	pipex(ac - 2, av, fds);
	return (0);
}
