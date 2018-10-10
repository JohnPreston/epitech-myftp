/*
** checks.c for checks in /home/mille_j//c/My_ftp/src_client
**
** Made by john mille
** Login   <John@epitech.net>
**
** Started on  Fri Apr  1 13:18:21 2011 john mille
** Last update Sat Apr  2 01:18:37 2011 john mille
*/

#include <stdlib.h>
#include "ftp.h"
#include "tools.h"
#include "client.h"
#include "my.h"

FLAG			check_each_nbs(char **ip)
{
  int			i;

  i = 0;
  while (ip[i])
    {
      if (my_getnbr(ip[i]) > 255)
	{
	  my_puterror("IP bad format:\nFrom 0.0.0.0 to 255.255.255.255.\n");
	  ip = my_xfree_tab(ip);
	  return (0);
	}
      else if (str_is_num(ip[i]) == 0)
	{
	  my_puterror("IP must only contains numbers\n");
	  ip = my_xfree_tab(ip);
	  return (0);
	}
      i += 1;
    }
  ip = my_xfree_tab(ip);
  return (1);
}

FLAG			check_ip(char *str)
{
  char			**ip;
  int			args_ip;

  ip = get_ip_argv(str);
  args_ip = get_ip_argc(str);
  if (args_ip != 4)
    {
      my_puterror("Not enough numbers in IP Adress.\n");
      return (0);
    }
  return (check_each_nbs(ip));
}

FLAG			check_args(char **argv)
{
  if (check_ip(argv[1]))
    {
      if (str_is_num(argv[2]) &&
	  (my_getnbr(argv[2]) > 0 && my_getnbr(argv[2]) < 65535))
	return (1);
      else
	my_puterror("Invalid Port number :\nFrom 0 to 65535\n");
    }
  return (0);
}

FLAG			check_init(t_client *c, FLAG init)
{
 if (init == INIT_FAILURE)
    {
      my_puterror(INIT_ERROR);
      quit_init_failure(c);
    }
  else if (init == ENV_FAILURE)
    {
      my_puterror(ENVIRON_ERROR);
      exit(EXIT_FAILURE);
    }
  return (INIT_SUCCESS);
}

FLAG			check_init_connection(t_client *c, FLAG init)
{
  if (init == INIT_FAILURE)
    {
      my_puterror(INIT_CO_ERROR);
      quit_init_failure(c);
    }
  return (INIT_SUCCESS);
}
