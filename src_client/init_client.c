/*
** init_client.c for init client in /media/data/my_ftp/src_client
**
** Made by john mille
** Login   <John@epitech.net>
**
** Started on  Mon Mar 28 09:34:11 2011 john mille
** Last update Thu Mar 31 23:53:34 2011 john mille
*/

#include <stdlib.h>
#include "ftp.h"
#include "client.h"
#include "tools.h"
#include "my.h"

static int		init_socket_data(t_client *c, char *addr, PORT port)
{
  FLAG			vars;

  c->ftp->p_data = port;
  c->ftp->s_data = my_xsocket(AF_INET, SOCK_STREAM, c->proto->p_proto);
  c->ftp->cin_data.sin_addr.s_addr = inet_addr(addr);
  c->ftp->cin_data.sin_port = htons(c->ftp->p_data);
  c->ftp->cin_data.sin_family = AF_INET;
  c->ftp->opt = 1;
  vars = my_xsetsockopt(c->ftp->s_data, SOL_SOCKET, SO_REUSEADDR,
			&c->ftp->opt, sizeof(c->ftp->opt));
  c->ftp->cin_data_size = sizeof(c->ftp->cin_data);
  c->ftp->auth = 0;
  if (vars == -1)
    return (INIT_FAILURE);
  return (INIT_SUCCESS);
}

static int		init_socket_cmd(t_client *c, t_ftp *ftp, t_vars *v,
					char *addr, PORT port)
{
  FLAG			vars[2];

  c->ftp = ftp;
  c->ftp->v = v;
  c->ftp->p_cmd = port;
  c->proto = getprotobyname("tcp");
  c->ftp->s_cmd = my_xsocket(AF_INET, SOCK_STREAM, (c)->proto->p_proto);
  vars[0] = c->ftp->s_cmd;
  c->ftp->cin_cmd.sin_addr.s_addr = inet_addr(addr);
  c->ftp->cin_cmd.sin_port = htons(c->ftp->p_cmd);
  c->ftp->cin_cmd.sin_family = AF_INET;
  c->ftp->opt = 1;
  vars[1] = my_xsetsockopt(c->ftp->s_cmd, SOL_SOCKET, SO_REUSEADDR,
			   &c->ftp->opt, sizeof(c->ftp->opt));
  c->ftp->cin_cmd_size = sizeof(c->ftp->cin_cmd);
  if (vars[0] == INIT_FAILURE || vars[1] == INIT_FAILURE)
    return (INIT_FAILURE);
  return (INIT_SUCCESS);
}

int			init_client(t_client *c, char *addr, PORT port)
{
  FLAG			errors[3];
  PORT			cmd;
  PORT			data;
  t_ftp			*ftp;
  t_vars		*v;

  cmd = port;
  if (port > 1)
    data = cmd -1;
  else
    return (INIT_FAILURE);
  ftp = my_xmalloc(sizeof(*ftp));
  v = my_xmalloc(sizeof(*v));
  errors[0] = init_vars(v);
  if (errors[0] == INIT_FAILURE)
    return (ENV_FAILURE);
  errors[1] = init_socket_cmd(c, ftp, v, addr, cmd);
  errors[2] = init_socket_data(c, addr, data);
  if (errors[1] == INIT_SUCCESS && errors[2] == INIT_SUCCESS)
    return (INIT_SUCCESS);
  return (INIT_FAILURE);
}
