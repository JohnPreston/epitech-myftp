/*
** get_cmd.c for get_cmd in /home/mille_j//my_ftp
**
** Made by john mille
** Login   <John@epitech.net>
**
** Started on  Mon Mar 28 16:03:13 2011 john mille
** Last update Tue Mar 29 23:26:51 2011 john mille
*/

#include "ftp.h"
#include "my.h"

char		*get_cmd(const int fd)
{
  char		*cmd;
  char		*buff;
  char		*tmp;
  int		nb_read;
  int		size;

  size = 0;
  cmd = my_xxmalloc(sizeof(*cmd));
  buff = my_xxmalloc((BUFF_SIZE) * sizeof(*buff));
  nb_read = my_xread(fd, buff, BUFF_SIZE);
  size += nb_read;
  while (nb_read == BUFF_SIZE)
    {
      tmp = cmd;
      cmd = my_strcat(tmp, buff);
      tmp = my_xxfree(tmp);
      my_memset(buff, '\0', BUFF_SIZE);
      nb_read = my_xread(fd, buff, BUFF_SIZE);
      size += nb_read;
    }
  tmp = cmd;
  cmd = my_strcat(tmp, buff);
  tmp = my_xxfree(tmp);
  buff = my_xxfree(buff);
  return (cmd);
}
