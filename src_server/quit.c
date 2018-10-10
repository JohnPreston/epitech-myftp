/*
** quit.c for quit in /home/mille_j//my_ftp/src_server
**
** Made by john mille
** Login   <John@epitech.net>
**
** Started on  Wed Mar 30 00:11:49 2011 john mille
** Last update Sun Apr  3 21:27:09 2011 john mille
*/

#include <stdlib.h>
#include <stdio.h>
#include "ftp.h"
#include "tools.h"
#include "server.h"
#include "my.h"

void		quit_client_closed(t_server *s)
{
  printf("[%s]:[%d] : Connection closed by peer\n",
	 inet_ntoa(s->sin_cmd.sin_addr), htons(s->p_cmd));
  my_xclose(s->ftp->s_cmd);
  my_xclose(s->ftp->s_data);
  clean_vars(s->ftp->v);
  s->ftp->v = my_xfree(s->ftp->v);
  s->ftp = my_xfree(s->ftp);
  exit(EXIT_SUCCESS);
}

void		quit(t_ftp *ftp, SOCKET to)
{
  if (my_strlen(ftp->v->recv_cmd))
    ftp->v->recv_cmd = my_xxfree(ftp->v->recv_cmd);
  my_xwrite(to, CLOSE_MSG, my_strlen(CLOSE_MSG));
  if (ftp->data == 1)
    my_xclose(ftp->v->fd_file);
  my_xclose(to);
  my_xclose(ftp->s_data);
  clean_vars(ftp->v);
  ftp->v = my_xfree(ftp->v);
  ftp = my_xfree(ftp);
  exit(EXIT_SUCCESS);
}

void		quit_whole_server(t_server *s)
{
  if (s->ftp->data == 1)
    my_xclose(s->ftp->v->fd_file);
  my_xclose(s->ftp->s_cmd);
  my_xclose(s->ftp->s_data);
  clean_vars(s->ftp->v);
  s->ftp->v = my_xfree(s->ftp->v);
  s->ftp = my_xfree(s->ftp);
  my_puterror("\r\rSERVER SHUTTING DOWN\n");
  my_xclose(s->s_cmd);
  my_xclose(s->s_data);
  exit(EXIT_FAILURE);
}
