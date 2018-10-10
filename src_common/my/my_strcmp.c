/*
** my_strcmp.c for my_strcmp in /home/mille_j//rendu/c/42sh/lib
**
** Made by john mille
** Login   <John@epitech.net>
**
** Started on  Sun Oct  3 19:28:20 2010 john mille
** Last update Thu Oct  7 14:38:58 2010 john mille
*/

#include <stdlib.h>
#include "my.h"

int		my_strcmp(char *s1, char *s2)
{
  int		i;

  i = 0;
  if (!(s1 && s2))
    return (-1);
  else if (!s1 && s2)
    return (s2[0]);
  else if (!s2 && s1)
    return (s1[0]);
  while (s1[i] || s2[i])
    {
      if (s1[i] != s2[i])
	return (s1[i] - s2[i]);
      i += 1;
    }
  return (0);
}

int		my_strncmp(char *s1, char *s2, int n)
{
  int		i;

  i = 0;
  if (!(s1 && s2))
    return (0);
  else if (!s1 && s2)
    return (s2[0]);
  else if (!s2 && s1)
    return (s1[0]);
  while (i < n)
    {
      if (s1[i] != s2[i])
	return (s1[i] - s2[i]);
      i += 1;
    }
  return (0);
}
