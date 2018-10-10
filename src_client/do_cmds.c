/*
** do_cmds.c for do cmds in /home/mille_j//c/My_ftp/src_client
**
** Made by john mille
** Login   <John@epitech.net>
**
** Started on  Sun Apr  3 09:58:08 2011 john mille
** Last update Sun Apr  3 14:13:37 2011 john mille
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "ftp.h"
#include "client.h"
#include "tools.h"
#include "my.h"

static t_functions	gl_f[] = {
  {1, 1, 0, "ls", myLs},
  {2, 1, 0, "cd", myCd},
  {3, 1, 0, "pwd", myPwd},
  {4, 0, 0, "quit", quit},
  {5, 0, 0, "user", user_authen},
  {6, 1, 1, "put", send_file},
  {7, 1, 1, "get", recv_file},
  {0, 0, 0, NULL, NULL},
};

SOCKET			define_to(t_ftp *ftp, SOCKET to)
{
  if (ftp->v->cmd_type == LOCAL)
    to = 1;
  else if (ftp->v->cmd_type == DISTANT)
    to = ftp->s_cmd;
  return (to);
}

int			data_status(t_ftp *ftp)
{
  if (ftp->data == 1)
    {
      if ((my_strcmp(ftp->v->argv[0], "get") == 0) ||
	  my_strcmp("put", ftp->v->argv[0]) == 0)
	return (0);
    }
  return (1);
}

int			do_cmds(t_ftp *ftp)
{
  SOCKET		to;
  int			i;

  to = 0;
  to = define_to(ftp, to);
  i = 0;
  if (data_status(ftp) == 0)
    return (0);
  while (gl_f[i].id && gl_f[i].flag)
    {
      if (my_strcmp(gl_f[i].flag, ftp->v->argv[0]) == 0)
	{
	  if (gl_f[i].auth == ftp->auth)
	    {
	      gl_f[i].func(ftp, to);
	      return (1);
	    }
	  else
	    my_puterror("Need to be logged in.\n");
	}
      i += 1;
    }
  return (0);
}
