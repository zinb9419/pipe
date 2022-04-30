/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziloughm <ziloughm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 13:27:17 by ziloughm          #+#    #+#             */
/*   Updated: 2022/04/30 02:14:00 by ziloughm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	ft_len_av(char **av)
{
	int	i;

	i = 0;
	while (av[i])
		i++;
	return (i);
}

static void	ft_chek_cmd_path(char **cmd, char **paths, char *str)
{
	if (!paths || !ft_len_av(paths))
		ft_error(ft_strjoin(str, ": No such file or directory\n"), 0);
	if (!cmd || !ft_len_av(cmd))
		ft_error(ft_strjoin(str, ": command not found\n"), 0);
}

static void	ft_exe_cmd(char	*c, char **cmd, char **env)
{
	int	i;

	i = execve(c, cmd, env);
	if (i == -1)
		ft_error(" ", 1);
}

void	ft_execve(char *av, char **env)
{
	char	**paths;
	char	**cmd;
	char	*c;
	int		j;

	paths = ft_getpaths(env);
	cmd = ft_split(av, ' ');
	j = 0;
	ft_chek_cmd_path(cmd, paths, av);
	if (!access(cmd[0], F_OK | X_OK))
		ft_exe_cmd(cmd[0], cmd, env);
	while (paths[j])
	{
		c = ft_strjoin(paths[j], cmd[0]);
		if (!access(c, F_OK | X_OK))
			ft_exe_cmd(c, cmd, env);
		j++;
	}
	c = ft_strjoin("", cmd[0]);
	ft_freemem(paths);
	ft_freemem(cmd);
	if (!ft_strrchr(c, '/'))
		ft_error(ft_strjoin(c, ": command not found\n"), 0);
	ft_error(c, 1);
}
