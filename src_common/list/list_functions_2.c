/*
** list_functions_2.c for list functions in /home/mille_j//my_ftp/src_common
**
** Made by john mille
** Login   <John@epitech.net>
**
** Started on  Tue Mar 29 20:34:57 2011 john mille
** Last update Sat Apr  2 17:48:40 2011 john mille
*/

#include <stdlib.h>
#include "my.h"
#include "ftp.h"

t_list			*init_list(char *elem)
{
  t_list		*head;
  t_list		*new;

  head = NULL;
  new = my_xmalloc(sizeof(*new));
  new->str = my_strdup(elem);
  new->next = NULL;
  new->prev = NULL;
  return (new);
}

t_list			*add_elem_at_end(t_list *list, char *elem)
{
  t_list		*new;
  t_list		*tmp;

  tmp = list;
  if (tmp)
    {
      while (tmp->next)
	tmp = tmp->next;
      new = my_xmalloc(sizeof(*new));
      new->str = my_strdup(elem);
      new->next = NULL;
      new->prev = tmp;
      tmp->next = new;
    }
  else
    list = init_list(elem);
  return (list);
}

t_list			*delete_elem_at_begin(t_list *list)
{
  if (list)
    {
      list->str = my_xxfree(list->str);
      list = list->next;
      list->prev = NULL;
    }
  return (list);
}

void			list_dump(t_list *list)
{
  while (list)
    {
      my_putstr(list->str);
      my_putstr("\n");
      list = list->next;
    }
}
