/*
** my_xwrite.c for xwrite in /media/data/my_ftp/src_client
**
** Made by john mille
** Login   <John@epitech.net>
**
** Started on  Mon Mar 28 12:26:14 2011 john mille
** Last update Mon Mar 28 12:31:23 2011 john mille
*/

#include <unistd.h>
#include <stdio.h>

int			my_xwrite(const int fd, char *buff, unsigned int size)
{
  int			nb_write;

  nb_write = write(fd, buff, size);
  if (nb_write == -1)
    perror("write");
  return (nb_write);
}

int			my_xread(const int fd, char *buff, unsigned int size)
{
  int			nb_read;

  nb_read = read(fd, buff, size);
  if (nb_read == -1)
    perror("read");
  return (nb_read);
}
