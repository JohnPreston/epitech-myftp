/*
** user.c for user in /home/mille_j//c/My_ftp/src_client
**
** Made by john mille
** Login   <John@epitech.net>
**
** Started on  Thu Mar 31 11:15:09 2011 john mille
** Last update Sun Apr  3 21:49:03 2011 john mille
*/

#define _XOPEN_SOURCE
#include <unistd.h>
#include <stdlib.h>
#include <termios.h>
#include <stdio.h>
#include "ftp.h"
#include "client.h"
#include "tools.h"
#include "my.h"

int			syntax_user_ok(t_ftp *ftp)
{
  if (ftp->v->argc != 2)
    {
      my_puterror(USER_USAGE);
      return (0);
    }
  return (1);
}

int			send_user_ok(t_ftp *ftp, SOCKET to)
{
  char			*answer;

  my_xwrite(to, ftp->v->prompt, my_strlen(ftp->v->prompt));
  answer = get_cmd(to);
  if (my_strcmp(answer, USER_OK) == 0)
    {
      answer = my_xxfree(answer);
      return (1);
    }
  else if (my_strcmp(answer, USER_KO))
    {
      my_puterror(answer);
      answer = my_xxfree(answer);
      return (0);
    }
  return (0);
}

int			passwd_ctrl(SOCKET to)
{
  char			*answer;

  answer = get_cmd(to);
  if (my_strcmp(answer, PASS_OK) == 0)
    {
      my_putchar('\n');
      my_puterror(PASS_OK);
      answer = my_xxfree(answer);
      return (1);
    }
  else if (my_strcmp(answer, PASS_KO) == 0)
    {
      my_puterror(PASS_KO);
      answer = my_xxfree(answer);
    }
  return (0);
}

int			passwd_ok(t_ftp *ftp, SOCKET to)
{
  struct termios	t;
  char			*cmd;
  char			*pass;
  FLAG			ret;

  ftp->v->prompt = my_xxfree(ftp->v->prompt);
  my_putstr("passwd:");
  tcgetattr(0, &t);
  t.c_lflag &= ~ECHO;
  tcsetattr(0, TCSANOW, &t);
  ftp->v->prompt = get_cmd(0);
  pass = crypt(ftp->v->prompt, "aA");
  tcgetattr(0, &t);
  t.c_lflag |= ECHO;
  tcsetattr(0, TCSANOW, &t);
  cmd = my_strcat("PASSWD ", pass);
  ftp->v->write = my_xwrite(to, cmd, my_strlen(cmd));
  ret = passwd_ctrl(to);
  cmd = my_xxfree(cmd);
  ftp->v->prompt = my_xxfree(ftp->v->prompt);
  my_putchar('\n');
  return (ret);
}

void			user_authen(t_ftp *ftp, SOCKET to)
{
  if (syntax_user_ok(ftp) && send_user_ok(ftp, to))
    {
      if (passwd_ok(ftp, to))
	ftp->auth = 1;
    }
}
