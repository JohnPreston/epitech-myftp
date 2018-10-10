/*
** init_connection.c for init connection in /home/mille_j/c/ftp/src/server
**
** Made by John Preston
** Login   <mille_j@epitech.net>
**
** Started on  Fri Mar 25 14:51:44 2011 John Preston
** Last update Sun Apr  3 00:35:27 2011 john mille
*/

#include <stdlib.h>
#include <stdio.h>
#include "ftp.h"
#include "server.h"
#include "tools.h"
#include "my.h"

int			data_connection(t_server *s)
{
  if ((s->ftp->s_data = (my_xaccept(s->s_data,
				    (SOCKADDR *)&((s)->ftp)->cin_data,
				    &s->ftp->cin_cmd_size))))
    {
      send_cmd_s_to_c(s, CON_DATA_OK);
      return (1);
    }
  send_cmd_s_to_c(s, CON_DATA_KO);
  return (0);
}

int			welcome_msg(t_server *s)
{
  send_cmd_s_to_c(s, WELCOME);
  if (recv_cmd_from_client(s))
    {
      if (my_strcmp(s->ftp->v->recv_cmd, WELCOME_OK) == 0)
	return (1);
      else if (my_strcmp(s->ftp->v->recv_cmd, WELCOME_KO) == 0)
	return (0);
    }
  return (1);
}

int			init_connection_server(t_server *s)
{
  if (welcome_msg(s))
    {
      if (data_connection(s))
	{
	  s->ftp->v->recv_cmd = my_xxfree(s->ftp->v->recv_cmd);
	  return (1);
	}
    }
  s->ftp->v->recv_cmd = my_xxfree(s->ftp->v->recv_cmd);
  return (0);
}
