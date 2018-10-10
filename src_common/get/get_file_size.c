/*
** tools.c for tools in /home/mille_j//my_ftp/src_common
**
** Made by john mille
** Login   <John@epitech.net>
**
** Started on  Wed Mar 30 19:39:14 2011 john mille
** Last update Wed Mar 30 19:50:01 2011 john mille
*/

#include "ftp.h"
#include "my.h"

unsigned int		get_file_size(const int fd)
{
  char			buff[BUFF_SIZE];
  int			nb_read;
  unsigned int		nb;

  nb = 0;
  do
    {
      nb_read = my_xread(fd, buff, BUFF_SIZE);
      nb += nb_read;
    } while (nb_read > 0);
  nb += nb_read;
  my_xclose(fd);
  return (nb);
}
