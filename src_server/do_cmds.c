/*
** do_cmds.c for do cmds in /home/mille_j//my_ftp/src_server
**
** Made by john mille
** Login   <John@epitech.net>
**
** Started on  Tue Mar 29 21:48:06 2011 john mille
** Last update Sun Apr  3 20:44:20 2011 john mille
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "ftp.h"
#include "tools.h"
#include "server.h"
#include "my.h"

static t_functions		gl_func[] = {
  {1, 1, 0, "ls", ls_server},
  {2, 1, 0, "cd", cd_server},
  {3, 1, 0, CLOSE_MSG, quit},
  {4, 1, 0, "pwd", pwd_server},
  {5, 1, 1, "send", recv_file},
  {5, 1, 1, "put", recv_file},
  {6, 1, 0, "get", send_file},
  {7, 0, 0, "user", get_user},
  {0, 0, 0, NULL, NULL},
};

void			pwd_server(t_ftp *ftp, SOCKET to)
{
  char			*pwd;

  pwd = get_pwd(ftp->v);
  my_xwrite(to, pwd, my_strlen(pwd));
  pwd = my_xxfree(pwd);
}

void			cd_server(t_ftp *ftp, SOCKET to)
{
  FLAG			cd;
  char			*answer;

  cd = my_cd(ftp->v);
  answer = get_pwd(ftp->v);
  my_xwrite(to, answer, my_strlen(answer));
  answer = my_xxfree(answer);
}

void			do_cmds(t_ftp *ftp)
{
  int			i;

  i = 0;
  while (gl_func[i].id && gl_func[i].flag)
    {
      if (my_strcmp(gl_func[i].flag, ftp->v->argv[0]) == 0)
	{
	  gl_func[i].func(ftp, ftp->s_cmd);
	  break;
	}
      i += 1;
    }
}
