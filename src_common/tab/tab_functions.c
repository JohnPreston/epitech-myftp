/*
** tab_functions.c for tab_functions in /home/mille_j//rendu/c/42sh/src
**
** Made by john mille
** Login   <John@epitech.net>
**
** Started on  Sun Oct  3 21:49:32 2010 john mille
** Last update Wed Mar 30 11:03:11 2011 john mille
*/

#include <stdlib.h>
#include "ftp.h"
#include "my.h"

char		**add_elem_to_tab(char **old_array, char *elem)
{
  char		**new_array;
  int		i;

  i = 0;
  new_array = my_xmalloc((my_tablen(old_array) + 2) * sizeof(*new_array));
  while (old_array[i])
    {
      new_array[i] = my_strdup(old_array[i]);
      i += 1;
    }
  new_array[i] = my_strdup(elem);
  new_array[i + 1] = NULL;
  old_array = my_xfree_tab(old_array);
  return (new_array);
}

char		**delete_elem_in_tab(char **old_array, int pos)
{
  char		**new_array;
  int		i;
  int		j;

  i = 0;
  j = 0;
  new_array = my_xmalloc((my_tablen(old_array) + 1) * sizeof(*new_array));
  while (old_array[i])
    {
      if (j == pos)
	j += 1;
      new_array[i] = my_strdup(old_array[j]);
      j += 1;
      i += 1;
    }
  new_array[i] = NULL;
  old_array = my_xfree_tab(old_array);
  return (new_array);
}

char		**update_elem_in_tab(char **old_array, char *val, int pos)
{
  char		**new_array;
  int		i;

  i = 0;
  new_array = my_xmalloc((my_tablen(old_array) + 1) * sizeof(*new_array));
  while (i < my_tablen(old_array))
    {
      if (i == pos)
	{
	  new_array[i] = my_strdup(val);
	  i += 1;
	}
      new_array[i] = my_strdup(old_array[i]);
      i += 1;
    }
  i = my_tablen(old_array);
  new_array[i] = NULL;
  old_array = my_xfree_tab(old_array);
  return (new_array);
}

char		**delete_last_elem_in_tab(char **old_array)
{
  char		**new_array;
  int		i;

  i = 0;
  new_array = my_xmalloc((my_tablen(old_array)) * sizeof(*new_array));
  while (old_array[i + 1])
    {
      new_array[i] = my_strdup(old_array[i]);
      i += 1;
    }
  new_array[i] = NULL;
  old_array = my_xfree_tab(old_array);
  return (new_array);
}

void		my_show_tab(char **tab, char c)
{
  int		i;

  i = 0;
  if (tab)
    {
      while (tab[i])
	{
	  my_putstr(tab[i]);
	  my_putchar(c);
	  i += 1;
	}
    }
}
