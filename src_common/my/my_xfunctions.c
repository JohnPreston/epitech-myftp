/*
** my_xfunctions.c for xfunctions in /home/mille_j//my_ftp/src_common
**
** Made by john mille
** Login   <John@epitech.net>
**
** Started on  Tue Mar 29 16:42:13 2011 john mille
** Last update Sun Apr  3 18:33:56 2011 john mille
*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

int			my_xchdir(const char *path)
{
  int			cd;

  cd = chdir(path);
  if (cd == -1)
    {
      perror("chdir");
      return (0);
    }
  return (1);
}

int			my_xstat(const char *path, struct stat *st)
{
  int			ret;

  ret = stat(path, st);
    if (ret == -1)
      perror("stat");
  return (ret);
}
