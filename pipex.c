/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziloughm <ziloughm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 18:54:15 by ziloughm          #+#    #+#             */
/*   Updated: 2022/04/21 23:10:17 by ziloughm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	pipex(int *fds, char **av, char **env)
{
	int	end[2];
	int	proce1;
	int	proce2;
	int	status;

	if (pipe(end) != 0)
		ft_error("Pipe", 1);
	proce1 = fork();
	if (proce1 == -1)
		ft_error("Fork", 1);
	if (proce1 == 0)
		ft_exec_pros1(fds[0], end, av, env);
	proce2 = fork();
	if (proce2 == -1)
		ft_error("Fork", 1);
	if (proce2 == 0)
		ft_exec_pros2(fds[1], end, av, env);
	close(end[0]);
	close(end[1]);
	waitpid(proce1, &status, 0);
	waitpid(proce2, &status, 0);
}

int	main(int ac, char **av, char **env)
{
	int		fds[2];

	if (ac != 5)
		exit(EXIT_FAILURE);
	fds[0] = open(av[1], O_RDONLY);
	fds[1] = open(av[4], O_CREAT | O_RDWR | O_TRUNC, 0644);
	pipex(fds, av, env);
	//system("leaks pipex");
	return (0);
}
