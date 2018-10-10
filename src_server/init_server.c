/*
** init_server.c for init server in /media/data/my_ftp/src_server
**
** Made by john mille
** Login   <John@epitech.net>
**
** Started on  Sun Mar 27 16:22:10 2011 john mille
** Last update Fri Apr  1 19:36:39 2011 john mille
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "ftp.h"
#include "server.h"
#include "tools.h"
#include "my.h"

int			init_ftp_socket(t_server *s)
{
  FLAG			vars[2];

  s->ftp->p_cmd = s->p_cmd;
  s->ftp->cin_cmd.sin_addr.s_addr = htonl(INADDR_ANY);
  s->ftp->cin_cmd.sin_port = htons(s->ftp->p_cmd);
  s->ftp->cin_cmd.sin_family = AF_INET;
  s->ftp->opt = 1;
  vars[0] = my_xsetsockopt(s->s_cmd, SOL_SOCKET, SO_REUSEADDR,
			   &s->ftp->opt, sizeof(s->ftp->opt));
  s->ftp->p_data = s->p_data;
  s->ftp->cin_data.sin_addr.s_addr = htonl(INADDR_ANY);
  s->ftp->cin_data.sin_port = htons(s->p_data);
  s->ftp->cin_data.sin_family = AF_INET;
  s->ftp->opt = 1;
  s->ftp->auth = 0;
  vars[1] = my_xsetsockopt(s->s_data, SOL_SOCKET, SO_REUSEADDR,
			   &s->ftp->opt, sizeof(s->ftp->opt));
  if (vars[0] == INIT_FAILURE || vars[1] == INIT_FAILURE)
    return (INIT_FAILURE);
  return (INIT_SUCCESS);
}

int			init_socket_data(t_server *s, PORT port)
{
  FLAG			vars[4];

  s->p_data = port;
  s->proto = getprotobyname("tcp");
  s->s_data = my_xsocket(AF_INET, SOCK_STREAM, s->proto->p_proto);
  s->sin_data.sin_addr.s_addr = htonl(INADDR_ANY);
  s->sin_data.sin_port = htons(s->p_data);
  s->sin_data.sin_family = AF_INET;
  s->ftp->opt = 1;
  s->ftp->user = NULL;
  vars[0] = my_xsetsockopt(s->s_data, SOL_SOCKET, SO_REUSEADDR,
			   &s->ftp->opt, sizeof(s->ftp->opt));
  s->sin_data_size = sizeof(s->sin_data);
  vars[1] = my_xbind(s->s_data, (SOCKADDR *)&s->sin_data, s->sin_data_size);
  vars[2] = my_xlisten(s->s_data, 42);
  if (vars[0] == -1 || vars[1] == -1 || vars[2] == -1)
    return (INIT_FAILURE);
  return (INIT_SUCCESS);
}

int			init_socket_cmd(t_server *s, t_ftp *ftp, t_vars *v, PORT port)
{
  FLAG			vars[4];

  s->ftp = ftp;
  s->ftp->v = v;
  s->p_cmd = port;
  s->proto = getprotobyname("tcp");
  s->s_cmd = my_xsocket(AF_INET, SOCK_STREAM, s->proto->p_proto);
  vars[0] = s->s_cmd;
  s->sin_cmd.sin_addr.s_addr = htonl(INADDR_ANY);
  s->sin_cmd.sin_port = htons(s->p_cmd);
  s->sin_cmd.sin_family = AF_INET;
  s->ftp->opt = 1;
  vars[1] = my_xsetsockopt(s->s_cmd, SOL_SOCKET, SO_REUSEADDR,
			   &s->ftp->opt, sizeof(s->ftp->opt));
  s->sin_cmd_size = sizeof(s->sin_cmd);
  vars[2] = my_xbind(s->s_cmd, (SOCKADDR *)&s->sin_cmd, s->sin_cmd_size);
  vars[3] = my_xlisten(s->s_cmd, 42);
  if (vars[0] == INIT_FAILURE || vars[1] == INIT_FAILURE ||
      vars[2] == INIT_FAILURE || vars[3] == INIT_FAILURE)
    return (INIT_FAILURE);
  return (INIT_SUCCESS);
}

int			init_server(t_server *s, PORT cmd, PORT data)
{
  FLAG			errors[4];
  t_ftp			*ftp;
  t_vars		*v;

  ftp = my_xmalloc(sizeof(*ftp));
  memset(ftp, 0, sizeof(*ftp));
  v = my_xmalloc(sizeof(*v));
  errors[0] = init_vars(v);
  if (errors[0] == INIT_FAILURE)
    {
      my_puterror(ENVIRON_ERROR);
      return (INIT_FAILURE);
    }
  errors[1] = init_socket_cmd(s, ftp, v, cmd);
  errors[2] = init_socket_data(s, data);
  errors[3] = init_ftp_socket(s);
  if (errors[1] == INIT_SUCCESS && errors[2] == INIT_SUCCESS &&
      errors[3] == INIT_SUCCESS)
    return (INIT_SUCCESS);
  return (INIT_FAILURE);
}
