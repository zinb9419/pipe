/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziloughm <ziloughm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 16:24:09 by ziloughm          #+#    #+#             */
/*   Updated: 2022/04/20 22:50:33 by ziloughm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/wait.h>
# include <fcntl.h>

void	ft_freemem(char **t);
int		ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_error(char *msg, int i);
void	*ft_calloc(size_t n, size_t s);
char	**ft_getpaths(char **env);
int		ft_strncmp(const char *str1, const char *str2, size_t n);
char	**ft_split(char const *s, char c);
size_t	ft_strlen(const char *str);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t	ft_strlcat(void *dest, const void *src, size_t n);
char	*ft_strrchr(const char *str, int c);
void	ft_execve(char **av, char **env, int i);
void	ft_exec_pros1(int fd, int *end, char **av, char **env);
void	ft_exec_pros2(int fd, int *end, char **av, char **env);
void	pipex(int *fds, char **av, char **env);
void	pipex_bonus(int *fds, char **av, char **env, int ac);

// void	pipex(int *fds, char **av, char **env, int ac);

#	endif