/*
** get_home.c for get home in /home/mille_j//42sh/src/builtin_cd
**
** Made by john mille
** Login   <John@epitech.net>
**
** Started on  Tue Nov 16 22:40:41 2010 john mille
** Last update Fri Apr  1 10:14:39 2011 john mille
*/

#include <stdlib.h>
#include <sys/types.h>
#include <signal.h>
#include "ftp.h"
#include "tools.h"
#include "my.h"

char		*get_home(t_vars *v)
{
  char		*home;

  home = my_getenv(v, "HOME");
  return (home);
}
