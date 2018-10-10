/*
** multi_client.c for multi_client in /media/data/my_ftp/src_server
**
** Made by john mille
** Login   <John@epitech.net>
**
** Started on  Sun Mar 27 20:15:25 2011 john mille
** Last update Sun Apr  3 15:56:37 2011 john mille
*/

#include <stdlib.h>
#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include "ftp.h"
#include "tools.h"
#include "server.h"
#include "my.h"

static t_server		*server;

void			gere_sigint()
{
  signal(SIGINT, gere_sigint);
  quit_whole_server(server);
}

int			multi_client(t_server *s)
{
  server = s;
  s->pere = getpid();
  while (42)
    {
      signal(SIGINT, gere_sigint);
      if ((s->ftp->s_cmd = my_xaccept(s->s_cmd,
				      (SOCKADDR *)&s->sin_cmd,
				      &s->sin_cmd_size)))
	{
	  if ((s->ftp->connected = init_connection_server(s)))
	    {
	      if ((s->fils = fork()) == 0)
		{
		  my_xclose(s->s_cmd);
		  my_xclose(s->s_data);
		  shell_server(s);
		  exit(EXIT_SUCCESS);
		}
	      s->gid = setpgid(s->fils, s->pere);
	    }
	}
    }
  return (EXIT_SUCCESS);
}

