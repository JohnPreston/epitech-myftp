/*
** ls.c for ls in /home/mille_j//my_ftp/src_client
**
** Made by john mille
** Login   <John@epitech.net>
**
** Started on  Tue Mar 29 13:32:53 2011 john mille
** Last update Sun Apr  3 20:01:06 2011 john mille
*/

#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <stdlib.h>
#include <dirent.h>
#include <stdio.h>
#include "ftp.h"
#include "tools.h"
#include "my.h"

void			ls_server(t_ftp *ftp, SOCKET to)
{
  pid_t			ls;
  int			status;

  if ((ls = fork()) == 0)
    {
      dup2(to, 1);
      execve("/bin/ls", ftp->v->argv, ftp->v->env);
      exit(EXIT_SUCCESS);
    }
  else
    waitpid(ls, &status, 0);
}

void			ls_client(t_ftp *ftp,
				  __attribute__((unused))SOCKET to)
{
  pid_t			ls;
  int			status;

  if ((ls = fork()) == 0)
    {
      execve("/bin/ls", ftp->v->argv, ftp->v->env);
      exit(EXIT_SUCCESS);
    }
  else
    waitpid(ls, &status, 0);
}
