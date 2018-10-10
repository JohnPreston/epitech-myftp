/*
** main_client.c for main client in /media/data/my_ftp/src_client
**
** Made by john mille
** Login   <John@epitech.net>
**
** Started on  Mon Mar 28 09:27:35 2011 john mille
** Last update Sun Apr  3 00:36:16 2011 john mille
*/

#include <stdlib.h>
#include <stdio.h>
#include "ftp.h"
#include "client.h"
#include "tools.h"
#include "my.h"

int			main(int argc, char **argv)
{
  t_client		c;
  PORT			port;
  FLAG			init;

  if (argc == 3 && check_args(argv))
    {
      port = my_getnbr(argv[2]);
      init = init_client(&c, argv[1], port);
      if (check_init(&c, init) == INIT_SUCCESS)
	init = init_connection_client(&c);
      if (check_init_connection(&c, init) == INIT_SUCCESS)
	{
	  c.ftp->connected = 1;
	  shell_client(&c);
	}
    }
  else
    {
      my_puterror(CLIENT_USAGE);
      return (EXIT_SUCCESS);
    }
  return (EXIT_SUCCESS);
}
