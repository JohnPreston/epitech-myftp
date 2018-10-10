/*
** get_argc_argv.c for get argc argv in /home/mille_j//rendu/c/42sh/src
**
** Made by john mille
** Login   <John@epitech.net>
**
** Started on  Wed Oct  6 22:34:13 2010 john mille
** Last update Sun Dec 12 11:26:41 2010 john mille
*/

#include <stdlib.h>
#include "my.h"

static int	is_printable(char c)
{
  if (c >= ' ' && c <= '~')
    return (1);
  return (0);
}

static int	char_ok(char c)
{
  if (is_printable(c) == 1 && c != '/')
    return (1);
  return (0);
}

static char	*fill_array(char *dest, char *str, int i)
{
  int		j;

  j = 0;
  while (char_ok(str[i + j]) == 1 && (i + j) < my_strlen(str))
    j += 1;
  dest = my_xxmalloc((j + 1) * sizeof(*dest));
  j = 0;
  while (char_ok(str[i + j]) == 1 && (i + j) < my_strlen(str))
    {
      dest[j] = str[i + j];
      j += 1;
    }
  dest[j] = '\0';
  return (dest);
}

int		get_nb_pwd(char *str)
{
  int		nb;
  int		in;
  int		i;

  i = 0;
  in = 0;
  nb = 0;
  while (str[i])
    {
      if (char_ok(str[i]) == 1 && in == 0)
	{
	  in = 1;
	  nb += 1;
	}
      else if (char_ok(str[i]) == 0 && in == 1)
	in = 0;
      i += 1;
    }
  return (nb);
}

char		**get_cd_path(char *str)
{
  char		**array;
  int		in;
  int		i;
  int		k;

  i = 0;
  k = 0;
  in = 0;
  array = my_xmalloc((get_nb_pwd(str) + 1) * sizeof(*array));
  while (str[i])
    {
      if (char_ok(str[i]) == 1 && in == 0)
	{
	  in = 1;
	  array[k] = fill_array(array[k], str, i);
	  k += 1;
	}
      else if (char_ok(str[i]) == 0 && in == 1)
	in = 0;
      i += 1;
    }
  array[k] = NULL;
  return (array);
}
