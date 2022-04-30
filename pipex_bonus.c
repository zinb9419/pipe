/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziloughm <ziloughm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 18:54:15 by ziloughm          #+#    #+#             */
/*   Updated: 2022/04/30 11:54:32 by ziloughm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	pipex_bonus(int *fds, char **av, char **env, int ac)
{
	int	end[2];
	int	i;
	int	pid;
	int	fdi;

	if (fds[0] < 0)
		ft_error(ft_strjoin(av[1], ": No such file or directory\n"), 0);i = 2;
	fdi = fds[0];
	i = 2;
	while (i < ac - 1)
	{
		if (pipe(end) != 0)
			ft_error("Pipe", 1);
		pid = fork();
		if (pid == -1)
			exit(EXIT_FAILURE);
		if (pid == 0)
		{
			dup2(fdi, STDIN_FILENO);
			dup2(end[1], STDOUT_FILENO);
			close(fdi);
			close(end[1]);
			ft_execve(av[i], env);
		}
		close (end[1]);
		close (fdi);
		fdi = end[0];
		waitpid(0, NULL, 0);
		++i;
	}
	if (fds[1] < 0)
		ft_error(ft_strjoin(av[ac], ": No such file or directory\n"), 0);
	dup2(fdi, STDIN_FILENO);
	dup2(fds[1], STDOUT_FILENO);
	ft_execve(av[i], env);
}

int	main(int ac, char **av, char **env)
{
	int		fds[2];

	if (ac < 5)
		exit(EXIT_FAILURE);
	fds[0] = open(av[1], O_RDONLY);
	fds[1] = open(av[ac - 1], O_CREAT | O_RDWR | O_TRUNC, 0644);
	pipex_bonus(fds, av, env, ac - 1);
	return (0);
}
