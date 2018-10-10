/*
** shell_client.c for shell_client in /home/mille_j//my_ftp/src_client
**
** Made by john mille
** Login   <John@epitech.net>
**
** Started on  Mon Mar 28 16:15:20 2011 john mille
** Last update Sun Apr  3 21:31:23 2011 john mille
*/

#include <stdlib.h>
#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include "tools.h"
#include "ftp.h"
#include "client.h"
#include "my.h"

static t_client		*client;

static void		gere_sigint()
{
  signal(SIGINT, gere_sigint);
  my_putstr("\b\b         \nFTP $>");
}

static void		gere_sigpipe()
{
  signal(SIGPIPE, gere_sigpipe);
  my_puterror("Connection Closed Unexpectedly.\n");
  client->ftp->data = 0;
  quit_client(client);
}

static void		gere_sigusr()
{
  signal(SIGUSR1, gere_sigusr);
  if (client->ftp->data == 1)
    {
      my_xclose(client->ftp->v->fd_file);
      client->ftp->data = 0;
    }
}

static void		gere_signals()
{
  signal(SIGINT, gere_sigint);
  signal(SIGPIPE, gere_sigpipe);
  signal(SIGUSR1, gere_sigusr);
}

int			shell_client(t_client *c)
{
  client = c;
  while (c->ftp->connected)
    {
      my_putstr("FTP $>");
      gere_signals();
      if ((c->ftp->v->prompt = get_cmd(0)))
	{
	  if (c->ftp->data == 1 && !my_strlen(c->ftp->v->prompt))
	    {
	      c->ftp->v->prompt = my_xxfree(c->ftp->v->prompt);
	      my_putstr("\n");
	    }
	  else if (c->ftp->data == 0 && !my_strlen(c->ftp->v->prompt))
	    quit_client(c);
	  manage_cmds(c);
	}
     }
  return (1);
}
