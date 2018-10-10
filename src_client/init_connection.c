/*
** init_connection.c for init connection in /home/mille_j/c/ftp/src/client
**
** Made by John Preston
** Login   <mille_j@epitech.net>
**
** Started on  Fri Mar 25 14:08:32 2011 John Preston
** Last update Mon Mar 28 22:44:35 2011 john mille
*/

#include <stdlib.h>
#include <stdio.h>
#include "ftp.h"
#include "client.h"
#include "tools.h"
#include "my.h"

int			check_connect(t_client *c)
{
  if (my_xconnect(c->ftp->s_data, (SOCKADDR *)&c->ftp->cin_data,
		  c->ftp->cin_data_size) == 0)
    {
      if (recv_cmd_from_server(c))
	{
	  if (my_strcmp(c->ftp->v->recv_cmd, CON_DATA_OK) == 0)
	    {
	      c->ftp->v->recv_cmd = my_xxfree(c->ftp->v->recv_cmd);
	      c->ftp->connected = 1;
	      return (INIT_SUCCESS);
	    }
	  else if (my_strcmp(c->ftp->v->recv_cmd, CON_DATA_KO) == 0)
	    {
	      c->ftp->connected = 0;
	      my_puterror(CON_DATA_KO);
	      return (INIT_FAILURE);
	    }
	}
    }
  return (INIT_FAILURE);
}

int			check_welcome(t_client *c)
{
  if (recv_cmd_from_server(c))
    {
      if (my_strcmp(c->ftp->v->recv_cmd, WELCOME) == 0)
	{
	  my_putstr(c->ftp->v->recv_cmd);
	  c->ftp->v->recv_cmd = my_xxfree(c->ftp->v->recv_cmd);
	  send_cmd_c_to_s(c, WELCOME_OK);
	  return (check_connect(c));
	}
      else if (my_strcmp(c->ftp->v->recv_cmd, WELCOME))
	{
	  send_cmd_c_to_s(c, WELCOME_KO);
	  return (INIT_FAILURE);
	}
    }
  return (INIT_FAILURE);
}

int			init_connection_client(t_client *c)
{
  if (my_xconnect(c->ftp->s_cmd, (SOCKADDR *)&c->ftp->cin_cmd,
		  c->ftp->cin_cmd_size) == 0)
    {
      if (check_welcome(c) == INIT_SUCCESS)
	{
	  c->ftp->connected = 1;
	  c->ftp->v->recv_cmd = my_xxfree(c->ftp->v->recv_cmd);
	  return (INIT_SUCCESS);
	}
    }
  return (INIT_FAILURE);
}
