/*
** shell_server.c for shell server in /home/mille_j//my_ftp/src_server
**
** Made by john mille
** Login   <John@epitech.net>
**
** Started on  Mon Mar 28 20:02:43 2011 john mille
** Last update Sun Apr  3 21:33:57 2011 john mille
*/

#include <stdlib.h>
#include <signal.h>
#include <stdio.h>
#include "ftp.h"
#include "tools.h"
#include "server.h"
#include "my.h"

static t_server		*server;

void			print_shell(t_server *s)
{
  int			p;

  if (my_strlen(s->ftp->v->recv_cmd) > 1)
    {
      s->ftp->v->recv_cmd[my_strlen(s->ftp->v->recv_cmd) - 1] = '\0';
      if (s->ftp->user)
      	p = printf("[%s]:[%d]-[%s]-[CMD] : %s\n",
      		   inet_ntoa(s->sin_cmd.sin_addr),
		   htons(s->ftp->p_cmd), s->ftp->user->login, s->ftp->v->recv_cmd);
      else
      p = printf("[%s]:[%d]-[NOT LOGGED IN]-[CMD] : %s\n",
		 inet_ntoa(s->sin_cmd.sin_addr),
		 htons(s->ftp->p_cmd), s->ftp->v->recv_cmd);
    }
  if (p == -1)
    perror("printf");
}

static void		gere_sigusr()
{
  signal(SIGUSR1, gere_sigusr);
  if (server->ftp->data == 1)
    {
      my_xclose(server->ftp->v->fd_file);
      server->ftp->data = 0;
    }
}

static void		gere_sigint()
{
  signal(SIGINT, gere_sigint);
  quit(server->ftp, server->ftp->s_cmd);
}

int			shell_server(t_server *s)
{
  server = s;
  s->ftp->v->recv_cmd = my_xxfree(s->ftp->v->recv_cmd);
  printf("[SERVER] [CONNECTION INITIALIZED WITH] [%s]:[%d]\n",
	 inet_ntoa(s->sin_cmd.sin_addr), htons(s->p_cmd));
  while (s->ftp->connected)
    {
      signal(SIGINT, gere_sigint);
      signal(SIGUSR1, gere_sigusr);
      if ((s->ftp->v->recv_cmd = get_cmd(s->ftp->s_cmd)))
	{
	  print_shell(s);
	  manage_cmds(s);
	}
    }
  return (1);
}
