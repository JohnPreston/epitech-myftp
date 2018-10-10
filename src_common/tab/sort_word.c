/*
** sort_word.c for sort word in /exam//rendu/ex_1
**
** Made by exam_user
** Login   <mille_j@epitech.net>
**
** Started on  Fri Dec 17 09:29:45 2010 exam_user
** Last update Wed Mar 30 10:21:39 2011 john mille
*/

#include <stdlib.h>
#include <stdio.h>
#include "ftp.h"
#include "my.h"

# define	MAX(a)(a <= 'Z' && a >= 'A')?(a + 32):(a)

int		str_cmp(char *s1, char *s2)
{
  int		a;
  int		b;
  int		i;
  int		j;
  int		res;

  j = 0;
  i = 0;
  while (s1[i] || s2[j])
    {
      a = MAX(s1[i]);
      b = MAX(s2[j]);
      res = a - b;
      if (res)
	return (res);
      i += 1;
      j += 1;
    }
  return (0);
}

void		sort_word(t_list *list)
{
  t_list	*tmp_list;
  t_list	*head;
  char		*tmp;

  head = list;
  while ((list)->next)
    {
      tmp_list = list->next;
      if (tmp_list->str && str_cmp(list->str, tmp_list->str) > 0)
	{
	  tmp = list->str;
	  list->str = tmp_list->str;
	  tmp_list->str = tmp;
	  list = head;
	}
      else
	list = list->next;
    }
}
