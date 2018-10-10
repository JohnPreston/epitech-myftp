/*
** user.c for user in /home/mille_j//c/My_ftp/src_server
**
** Made by john mille
** Login   <John@epitech.net>
**
** Started on  Thu Mar 31 18:07:46 2011 john mille
** Last update Sun Apr  3 22:02:03 2011 john mille
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "ftp.h"
#include "server.h"
#include "tools.h"
#include "my.h"

t_users			users[] = {
  {"john", "aAR20Vcsktd1A", "/home/", 1},
  {NULL, NULL, NULL, 0},
};

void			build_vars_for_user(t_ftp *ftp, char *home)
{
  my_xchdir(home);
  ftp->v->prompt = my_xxfree(ftp->v->prompt);
  ftp->v->argv = my_xfree_tab(ftp->v->argv);
  ftp->v->prompt = my_strcat("setenv PWD ", home);
  ftp->v->argc = get_argc(ftp->v->prompt);
  ftp->v->argv = get_argv(ftp->v->prompt);
  my_up_or_setenv(ftp->v);
  ftp->v->prompt = my_xxfree(ftp->v->prompt);
  ftp->v->argv = my_xfree_tab(ftp->v->argv);
  ftp->v->prompt = my_strcat("setenv HOME ", home);
  ftp->v->argc = get_argc(ftp->v->prompt);
  ftp->v->argv = get_argv(ftp->v->prompt);
  my_up_or_setenv(ftp->v);
  ftp->v->prompt = my_xxfree(ftp->v->prompt);
  ftp->v->argv = my_xfree_tab(ftp->v->argv);
}

int			passwd_ok(t_ftp *ftp, SOCKET to, char *passwd)
{
  char			*answer;

  answer = get_cmd(to);
  ftp->v->argc = get_argc(answer);
  ftp->v->argv = get_argv(answer);
  if (my_strcmp(ftp->v->argv[1], passwd) == 0)
    {
      answer = my_xxfree(answer);
      my_xwrite(to, PASS_OK, my_strlen(PASS_OK));
      return (1);
    }
  else if (my_strcmp(answer, ftp->v->argv[1]))
    {
      answer = my_xxfree(answer);
      my_xwrite(to, PASS_KO, my_strlen(PASS_KO));
    }
  return (0);
}

int			login_ok(t_ftp *ftp, SOCKET to)
{
  int			i;

  i = 0;
  while (users[i].login)
    {
      if (my_strcmp(users[i].login, ftp->v->argv[1]) == 0)
	{
	  my_xwrite(to, USER_OK, my_strlen(USER_OK));
	  build_vars_for_user(ftp, users[i].dir);
	  ftp->user = &users[i];
	  return (passwd_ok(ftp, to, users[i].passwd));
	}
      i += 1;
    }
  my_xwrite(to, USER_KO, my_strlen(USER_KO));
  return (0);
}

void			get_user(t_ftp *ftp, SOCKET to)
{
  if (login_ok(ftp, to))
    {
      printf("[USER] [%s] [LOGGED IN]\n", ftp->user->login);
      ftp->auth = 1;
    }
}
