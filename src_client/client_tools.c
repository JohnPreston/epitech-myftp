/*
** client_tools.c for client tools in /home/mille_j/c/ftp/src/client
**
** Made by John Preston
** Login   <mille_j@epitech.net>
**
** Started on  Fri Mar 25 15:19:21 2011 John Preston
** Last update Sun Apr  3 18:32:41 2011 john mille
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "ftp.h"
#include "client.h"
#include "tools.h"
#include "my.h"

int			send_cmd_c_to_s(t_client *c, char *cmd)
{
  int			nb;

  nb = my_xwrite(c->ftp->s_cmd, cmd, my_strlen(cmd));
  if (nb)
    return (1);
  return (0);
}

int			recv_cmd_from_server(t_client *c)
{
  c->ftp->v->recv_cmd = NULL;
  while (!c->ftp->v->recv_cmd)
    {
      if ((c->ftp->v->recv_cmd = get_cmd(c->ftp->s_cmd)))
	return (1);
    }
  return (0);
}

char			*clean_cmd(char *cmd)
{
  char			*new;
  int			i;
  int			j;

  i = 1;
  j = 0;
  new = my_xxmalloc((my_strlen(cmd)) * sizeof(*new));
  while (cmd[i])
    {
      new[j] = cmd[i];
      j += 1;
      i += 1;
    }
  cmd = my_xxfree(cmd);
  return (new);
}
