/*
** my_tablen.c for my tablen in /home/mille_j//my_ftp/src_common
**
** Made by john mille
** Login   <John@epitech.net>
**
** Started on  Tue Mar 29 15:48:54 2011 john mille
** Last update Tue Mar 29 15:49:47 2011 john mille
*/

#include <stdlib.h>

int		my_tablen(char **tab)
{
  int		i;

  i = 0;
  if (!tab)
    return (i);
  while (tab[i])
    i += 1;
  return (i);
}
