/*
** my_xfree.c for free functions in /home/mille_j//rendu/c/42sh/lib
**
** Made by john mille
** Login   <John@epitech.net>
**
** Started on  Sun Oct  3 19:25:04 2010 john mille
** Last update Thu Dec 16 10:19:13 2010 john mille
*/

#include <stdlib.h>
#include "my.h"

void		*my_xfree(void *ptr)
{
  if (ptr)
    {
      free(ptr);
      ptr = NULL;
    }
  return (ptr);
}

char		*my_xxfree(char *str)
{
  if (str)
    {
      free(str);
      str = NULL;
    }
  return (str);
}

char		**my_xfree_tab(char **tab)
{
  int		i;

  i = 0;
  if (!tab)
    return (tab);
  while (tab[i])
    {
      tab[i] = my_xxfree(tab[i]);
      i += 1;
    }
  free(tab[i]);
  tab[i] = NULL;
  free(tab);
  tab = NULL;
  return (tab);
}
