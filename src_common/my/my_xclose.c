/*
** my_xclose.c for my xclose in /media/data/my_ftp/src_common
**
** Made by john mille
** Login   <John@epitech.net>
**
** Started on  Sun Mar 27 18:33:46 2011 john mille
** Last update Sun Mar 27 18:37:52 2011 john mille
*/

#include <unistd.h>
#include <stdio.h>

int			my_xclose(int fd)
{
  int			xclose;

  xclose = close(fd);
  if (xclose == -1)
    perror("close");
  return (xclose);
}
