/*
** list_functions.c for list functionc in /home/mille_j//my_ftp/src_common
**
** Made by john mille
** Login   <John@epitech.net>
**
** Started on  Tue Mar 29 13:41:08 2011 john mille
** Last update Tue Mar 29 21:46:14 2011 john mille
*/

#include <stdlib.h>
#include "my.h"
#include "ftp.h"

int			list_size(t_list *list)
{
  int			i;

  i = 0;
  if (!list)
    return (i);
  while (list->next)
    {
      i += 1;
      list = list->next;
    }
  return (i);
}

void		free_list(t_list *list)
{
  if (list->next)
    free_list(list->next);
  list->str = my_xxfree(list->str);
  list = my_xfree(list);
}
