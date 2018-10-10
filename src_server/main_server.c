/*
** main_server.c for main_server in /media/data/my_ftp/src_server
**
** Made by john mille
** Login   <John@epitech.net>
**
** Started on  Sun Mar 27 16:20:36 2011 john mille
** Last update Sat Apr  2 01:22:56 2011 john mille
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "ftp.h"
#include "tools.h"
#include "server.h"
#include "my.h"

FLAG			check_port(char *argv)
{
  if (my_getnbr(argv) > 0 && my_getnbr(argv) < 65535)
    return (1);
  my_puterror("Bad port number : From 0 to 65535\n");
  return (0);
}

int			main(int argc, char **argv)
{
  t_server		server;
  PORT			port;
  FLAG			init;

  if (argc == 2 && str_is_num(argv[1]) && check_port(argv[1]))
    {
      port = my_getnbr(argv[1]);
      init = init_server(&server, port, (port - 1));
      if (init == INIT_FAILURE)
	{
	  my_puterror(INIT_ERROR);
	  return (EXIT_FAILURE);
	}
      multi_client(&server);
    }
  else
    perror(SERVER_USAGE);
  return (EXIT_SUCCESS);
}
