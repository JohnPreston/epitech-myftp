/*
** my_strcat.c for my_strcat in /home/mille_j//rendu/c/42sh/lib
**
** Made by john mille
** Login   <John@epitech.net>
**
** Started on  Sun Oct  3 19:15:19 2010 john mille
** Last update Sun Nov 14 12:52:13 2010 john mille
*/

#include "my.h"

char		*my_strcat(char *s1, char *s2)
{
  char		*new;
  int		len1;
  int		len2;
  int		i;
  int		j;

  len1 = my_strlen(s1);
  len2 = my_strlen(s2);
  i = 0;
  j = 0;
  new = my_xxmalloc((len1 + len2 + 1) * sizeof(*new));
  while (i < len1)
    {
      new[i] = s1[i];
      i += 1;
    }
  while (j < len2)
    {
      new[len1 + j] = s2[j];
      j += 1;
    }
  new[i + j] = '\0';
  return (new);
}

char		*my_strncat(char *s1, char *s2, int n)
{
  char		*new;
  char		*tmp;

  tmp = my_strcat(s1, s2);
  new = my_xxmalloc((n + 1) * sizeof(*new));
  my_strncpy(new, tmp, n);
  my_xxfree(tmp);
  return (new);
}

char		*replace(char *to_replace, char *to_add)
{
  char		*tmp;

  tmp = to_replace;
  to_replace = my_strcat(tmp, to_add);
  my_xxfree(tmp);
  return (to_replace);
}
