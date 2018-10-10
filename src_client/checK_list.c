/*
** checK_list.c for check_list.c in /home/mille_j//my_ftp/src_client
**
** Made by john mille
** Login   <John@epitech.net>
**
** Started on  Wed Mar 30 00:25:20 2011 john mille
** Last update Sun Apr  3 14:00:21 2011 john mille
*/

#include <stdlib.h>
#include "ftp.h"
#include "client.h"
#include "my.h"

static t_functions		gl_f[] = {
  {1, 1, 0, "ls", NULL},
  {2, 1, 0, "cd", NULL},
  {3, 1, 0, "pwd", NULL},
  {4, 1, 0, "put", NULL},
  {5, 1, 0, "get", NULL},
  {6, 1, 0, "user", NULL},
  {0, 1, 0, NULL, NULL},
};

int			check_list(t_vars *v)
{
  int			i;

  i = 0;
  while (gl_f[i].id && gl_f[i].flag)
    {
      if (my_strcmp(gl_f[i].flag, v->argv[0]) == 0)
	return (1);
      i += 1;
    }
  return (0);
}
