/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziloughm <ziloughm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 18:00:09 by ziloughm          #+#    #+#             */
/*   Updated: 2022/04/29 18:19:38 by ziloughm         ###   ########.fr       */
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
	int	fdo;
	int	pid;
	int	fdi;

	i = 2;
	fdi = fds[0];
	while (i < ac - 1)
	{
		pipe(end);
		printf("cmd %s n%d\n", av[i], i - 1);
		pid = fork();
		if (pid == -1)
			exit(EXIT_FAILURE);
		if (pid == 0)
		{
			dup2(fdi, STDIN_FILENO);
			dup2(end[1], STDOUT_FILENO);
			close(fdi);
			close(end[1]);
			execlp(strtok(av[i], " "), av[i], (char *) NULL);
		}
		close (end[1]);
		close (fdi);
		fdi = end[0];
		waitpid(0, NULL, 0);
		++i;
	}
	printf("cmd %s n%d\n", av[i], i - 1);
	dup2(fdi, STDIN_FILENO);
	dup2(fds[1], STDOUT_FILENO);
	execlp(strtok(av[i], " "), av[i], (char *) NULL);
 }

int	main(int ac, char **av, char **env)
{
	int	fds[2];

	fds[0] = open(av[1], O_RDONLY);
	fds[1] = open(av[ac - 1], O_CREAT | O_RDWR | O_TRUNC, 0644);
	pipex(ac - 1, av, fds);
	return (0);
}
