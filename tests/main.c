/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziloughm <ziloughm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 23:12:29 by ziloughm          #+#    #+#             */
/*   Updated: 2022/04/19 17:47:34 by ziloughm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <fcntl.h>

int	main(int ac, char **av, char **ev)
{
	int	i;

	// i = access("file", R_OK);
	//printf("%d %d %d %d\n", access("file", F_OK), access("file", R_OK), access("file", W_OK), access("file", X_OK));
	// perror("");

	// pid_t c_pid = fork();
    // if (c_pid == -1) {
    //     perror("fork");
    //     exit(EXIT_FAILURE);
    // }

    // if (c_pid == 0) {
    //     printf("printed from child process - %d\n", getpid());
    //     exit(EXIT_SUCCESS);
    // } else {
    //     printf("printed from parent process - %d\n", getpid());
    //     wait(NULL);
    // }

    //EXECVE TESTS
    (void) ac;
    (void) av;
    int t = 0;
    
    // while (ev[t])
    // {
    //     printf("mot : %s \n", ev[t]);
    //     t++;
    // }
    char *argv[] = {"cal", "-rggg", NULL};
    int r ;
    
    r = open("file", O_RDWR, 0644);
    printf("%d\n", r);
    i = dup2(r, 1);
    i = execve("/usr/bin/cal", argv, ev);
    if(i == -1)
        perror("Execve");
     exit(EXIT_SUCCESS);
}

