/*
** my_getnbr.c for my_getnbr in /home/mille_j//rendu/c/42sh/lib
**
** Made by john mille
** Login   <John@epitech.net>
**
** Started on  Sun Oct  3 21:01:34 2010 john mille
** Last update Sun Oct  3 21:01:35 2010 john mille
*/

#include "my.h"

int		my_getnbr(char *str)
{
  int		neg;
  int		nb;
  int		i;

  i = 0;
  nb = 0;
  neg = 1;
  while (str[i] == '-' || str[i] == '+')
    {
      if (str[i] == '-')
	neg = - neg;
      i += 1;
    }
  while (str[i] >= '0' && str[i] <= '9' && str[i] != '\0')
    {
      nb = nb * 10 + (str[i] - '0');
      i += 1;
    }
  return (neg * nb);
}
