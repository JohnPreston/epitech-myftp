/*
** server_tools.c for server tools in /home/mille_j/c/ftp/src/server
**
** Made by John Preston
** Login   <mille_j@epitech.net>
**
** Started on  Fri Mar 25 14:38:17 2011 John Preston
** Last update Sun Apr  3 12:41:23 2011 john mille
*/

#define	_GNU_SOURCE
#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <sys/stat.h>
#include <sys/types.h>
#include "ftp.h"
#include "tools.h"
#include "server.h"
#include "my.h"

int			send_cmd_s_to_c(t_server *s, char *cmd)
{
  int			nb;

  nb = my_xwrite(s->ftp->s_cmd, cmd, my_strlen(cmd));
  if (nb)
    return (1);
  return (0);
}

int			recv_cmd_from_client(t_server *s)
{
  s->ftp->v->recv_cmd = NULL;
  while (!s->ftp->v->recv_cmd)
    {
      if ((s->ftp->v->recv_cmd = get_cmd(s->ftp->s_cmd)))
	return (1);
    }
  return (0);
}

void			send_size(t_ftp *ftp, SOCKET to)
{
  struct stat		st;
  FLAG			ret;
  char			*size;

  ret = stat(ftp->v->argv[1], &st);
  if (!ret)
    {
      ret = asprintf(&size, "%ld", st.st_size);
      ftp->v->file_size = st.st_size;
      my_xwrite(to, size, my_strlen(size));
    }
  size = my_xxfree(size);
}
