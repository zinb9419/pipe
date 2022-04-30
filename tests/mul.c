/*
** pipex.c - multipipes support
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

void	loop_pipe(char **cmd)
{
  int	p[2];
  pid_t pid;
  int   fd_in = 0;

  while (cmd != NULL)
    {
      pipe(p);
      if ((pid = fork()) == -1)
        {
          exit(EXIT_FAILURE);
        }
      else if (pid == 0)
        {
          dup2(fd_in, 0); //change the input according to the old one 
          if ((cmd + 1) != NULL)
            dup2(p[1], 1);
          close(p[0]);
          execvp((cmd)[0], cmd);
          exit(EXIT_FAILURE);
        }
      else
        {
          wait(NULL);
          close(p[1]);
          fd_in = p[0]; //save the input for the next command
          cmd++;
        }
    }
}

/*
 * Compute multi-pipeline based
 * on a command list.
 */
int	main(int ac, char **av)
{
	(void) ac;
	loop_pipe(av);
	return (0);
}
