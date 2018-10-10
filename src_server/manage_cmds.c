/*
** manage_cmds.c for manage_cmds in /home/mille_j//my_ftp/src_server
**
** Made by john mille
** Login   <John@epitech.net>
**
** Started on  Tue Mar 29 21:54:17 2011 john mille
** Last update Wed Mar 30 00:17:44 2011 john mille
*/

#include <stdlib.h>
#include <unistd.h>
#include "ftp.h"
#include "server.h"
#include "tools.h"
#include "my.h"

int			manage_cmds(t_server *s)
{
  if (my_strlen(s->ftp->v->recv_cmd) > 1)
    {
      s->ftp->v->argc = get_argc(s->ftp->v->recv_cmd);
      s->ftp->v->argv = get_argv(s->ftp->v->recv_cmd);
      do_cmds(s->ftp);
      s->ftp->v->argv = my_xfree_tab(s->ftp->v->argv);
      s->ftp->v->recv_cmd = my_xxfree(s->ftp->v->recv_cmd);
    }
  else if (!my_strlen(s->ftp->v->recv_cmd))
    quit_client_closed(s);
  return (1);
}
