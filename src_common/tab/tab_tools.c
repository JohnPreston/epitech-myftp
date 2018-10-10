/*
** tab_tools.c for tab tools in /home/mille_j//42sh/src/pipes
**
** Made by john mille
** Login   <John@epitech.net>
**
** Started on  Tue Dec  7 22:43:40 2010 john mille
** Last update Thu Mar 24 22:07:39 2011 john mille
*/

#include <stdlib.h>
#include "ftp.h"
#include "my.h"

char		*concat_tab_elems(char **array, char *sep)
{
  char		*str;
  char		*tmp;
  int		i;

  i = 0;
  tmp = NULL;
  str = my_strdup(array[i]);
  while (array[i + 1])
    {
      tmp = str;
      str = my_strcat(tmp, sep);
      tmp = my_xxfree(tmp);
      tmp = str;
      str = my_strcat(tmp, array[i + 1]);
      tmp = my_xxfree(tmp);
      i += 1;
    }
  tmp = my_xxfree(tmp);
  tmp = str;
  str = my_strcat(tmp, sep);
  tmp = my_xxfree(tmp);
  return (str);
}

char		*concat_tab_elems2(char **array, char *sep)
{
  char		*str;
  char		*tmp;
  int		i;

  i = 0;
  tmp = NULL;
  str = my_strdup(array[i]);
  while (array[i + 1])
    {
      tmp = str;
      str = my_strcat(tmp, sep);
      tmp = my_xxfree(tmp);
      tmp = str;
      str = my_strcat(tmp, array[i + 1]);
      tmp = my_xxfree(tmp);
      i += 1;
    }
  my_xxfree(tmp);
  return (str);
}

char		*nconcat_tab_elems(char **array, char *sep, int a, int b)
{
  char		*str;
  char		*tmp;
  int		i;

  i = a;
  str = my_strdup(array[i]);
  while (i < b)
    {
      tmp = str;
      str = my_strcat(tmp, sep);
      tmp = my_xxfree(tmp);
      tmp = str;
      str = my_strcat(tmp, array[i + 1]);
      tmp = my_xxfree(tmp);
      i += 1;
    }
  return (str);
}
