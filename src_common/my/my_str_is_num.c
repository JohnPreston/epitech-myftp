/*
** my_str_is_num.c for str is num in /home/mille_j//c/My_ftp/src_common
**
** Made by john mille
** Login   <John@epitech.net>
**
** Started on  Fri Apr  1 13:16:28 2011 john mille
** Last update Fri Apr  1 13:37:10 2011 john mille
*/

#include "my.h"

int			str_is_num(char *str)
{
  int			i;

  i = 0;
  while (str[i])
    {
      if (str[i] < '0' || str[i] > '9')
	return (0);
      i += 1;
    }
  return (1);
}

