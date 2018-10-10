/*
** my_strdup.c for my_strdup in /home/mille_j//rendu/c/42sh/lib
**
** Made by john mille
** Login   <John@epitech.net>
**
** Started on  Sun Oct  3 19:06:43 2010 john mille
** Last update Tue Nov  9 16:22:41 2010 john mille
*/

#include <stdlib.h>
#include "my.h"

char		*my_strdup(char *str)
{
  char		*new;

  if (!str)
    return (NULL);
  new = my_xxmalloc((my_strlen(str) + 1) * sizeof(*new));
  my_strcpy(new, str);
  return (new);
}

char		*my_strdup2(char *str, char c)
{
  char		*new;

  if (!str)
    return (NULL);
  new = my_xxmalloc((my_strlen2(str, c) + 1) * sizeof(*new));
  my_strcpy2(new, str, c);
  return (new);
}

char		*my_strdup3(char *str, char c)
{
  char		*new;

  if (!str)
    return (NULL);
  new = my_xxmalloc((my_strlen3(str, c) + 1) * sizeof(*new));
  my_strcpy3(new, str, c);
  return (new);
}

char		*my_strdup4(char *src, int from, int to)
{
  char		*dest;

  if (!src)
    return (NULL);
  dest = my_xxmalloc((to - from + 1) * sizeof(*dest));
  my_strcpy4(dest, src, from, to);
  return (dest);
}
