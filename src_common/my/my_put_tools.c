/*
** my_put_tools.c for put functions in /home/mille_j//rendu/c/42sh/lib
**
** Made by john mille
** Login   <John@epitech.net>
**
** Started on  Sun Oct  3 19:39:44 2010 john mille
** Last update Mon Oct 17 14:24:29 2011 John Preston
*/

#include <unistd.h>
#include "my.h"

void		my_putchar(char c)
{
  my_xwrite(1, &c, 1);
}

void		my_putstr(char *str)
{
  my_xwrite(1, str, my_strlen(str));
}

void		my_puterror(char *str)
{
  my_xwrite(2, str, my_strlen(str));
}

void		my_putnbr(int nb)
{
  int		div;

  div = 1;
  if (nb >= 0)
    nb = -nb;
  else
    my_putchar('-');
  while ((nb / div) < -9)
    div *= 10;
  while (div)
    {
      my_putchar(((nb / div) * -1) + '0');
      nb = nb % div;
      div = div / 10;
    }
}
