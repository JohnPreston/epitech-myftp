/*
** get_pwd.c for get pwd in /home/mille_j//42sh/src/builtin_cd
**
** Made by john mille
** Login   <John@epitech.net>
**
** Started on  Wed Nov 17 12:25:42 2010 john mille
** Last update Fri Apr  1 10:15:12 2011 john mille
*/

#include <stdlib.h>
#include "ftp.h"
#include "tools.h"
#include "my.h"

char		*get_pwd(t_vars *v)
{
  char		*pwd;

  pwd = my_getenv(v, "PWD");
  return (pwd);
}
