/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziloughm <ziloughm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 23:37:43 by ziloughm          #+#    #+#             */
/*   Updated: 2022/04/30 02:51:45 by ziloughm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_error(char *msg, int i)
{
	ft_putstr_fd("pipex > ", 2);
	if (i)
		perror(msg);
	else
		ft_putstr_fd(msg, 2);
	exit(EXIT_FAILURE);
}

char	**ft_getpaths(char **env)
{
	int		i;
	char	**paths;
	char	*str;

	i = 0;
	paths = NULL;
	while (env[i])
	{
		if (!ft_strncmp(env[i], "PATH=", 5))
			paths = ft_split(env[i], ':');
		i++;
	}
	if (!paths)
		return (NULL);
	i = 0;
	while (paths[i])
	{
		str = paths[i];
		if (i == 0)
			paths[0] = ft_substr(paths[0], 5, ft_strlen(paths[0]));
		paths[i] = ft_strjoin(str, "/");
		free(str);
		i++;
	}
	return (paths);
}

void	ft_freemem(char **t)
{
	int	i;

	i = 0;
	while (t[i])
	{
		free(t[i]);
		i++;
	}
	free(t);
}

void	ft_exec_pros1(int fd, int *end, char **av, char **env)
{
	if (fd < 0)
		ft_error(ft_strjoin(av[1], ": No such file or directory\n"), 0);
	if (dup2(fd, STDIN_FILENO) < 0)
		ft_error("DUP2 child 1 INPUT", 1);
	if (dup2(end[1], STDOUT_FILENO) < 0)
		ft_error("DUP2 child 1 OUTPUT", 1);
	close(end[0]);
	close(end[1]);
	close(fd);
	ft_execve(av[2], env);
}

void	ft_exec_pros2(int fd, int *end, char **av, char **env)
{
	if (fd < 0)
		ft_error(ft_strjoin(av[4], ": No such file or directory\n"), 0);
	if (dup2(end[0], STDIN_FILENO) < 0)
		ft_error("DUP2 child 2 INPUT", 1);
	if (dup2(fd, STDOUT_FILENO) < 0)
		ft_error("DUP2 child 2 OUTPUT", 1);
	close(end[1]);
	close(end[0]);
	close(fd);
	ft_execve(av[3], env);
}
