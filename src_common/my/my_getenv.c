/*
** get_env_var.c for get env var in /home/mille_j//42sh/src/builtin_cd
**
** Made by john mille
** Login   <John@epitech.net>
**
** Started on  Tue Nov 16 22:10:26 2010 john mille
** Last update Wed Mar 30 10:59:45 2011 john mille
*/

#include <stdlib.h>
#include "ftp.h"
#include "tools.h"
#include "my.h"

int		find_char(char *str, char c)
{
  int		i;

  i = 0;
  if (!str)
    return (NOT_FOUND);
  while (str[i])
    {
      if (str[i] == c)
	return (FOUND);
      i += 1;
    }
  return (NOT_FOUND);
}

int		find_pos_in_env(char **env, char *to_find)
{
  int		i;

  i = 0;
  if (!env)
    return (NOT_FOUND);
 if (!to_find)
   return (NOT_FOUND);
 while (env[i])
    {
      if (my_strncmp(env[i], to_find, my_strlen2(env[i], '=')) == 0 &&
	  my_strlen(to_find) == my_strlen2(env[i], '='))
	return (i);
      i += 1;
    }
  return (NOT_FOUND);
}

char		*my_getenv(t_vars *v, char *find)
{
  char		*var;
  int		to_find;

  var = NULL;
  to_find = find_pos_in_env(v->env, find);
  if (to_find != NOT_FOUND)
    var = my_strdup3(v->env[to_find], '=');
  return (var);
}
