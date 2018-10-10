/*
** cmds.c for cmds in /home/mille_j//c/My_ftp/src_client
**
** Made by john mille
** Login   <John@epitech.net>
**
** Started on  Sat Apr  2 01:55:54 2011 john mille
** Last update Sun Apr  3 20:36:18 2011 john mille
*/

#include <stdlib.h>
#include <stdio.h>
#include "ftp.h"
#include "client.h"
#include "tools.h"
#include "my.h"

void			print_answer(char *answer, char *func)
{
  my_puterror(func);
  my_puterror(answer);
  my_puterror("\n");
}

void			myCd(t_ftp *ftp, SOCKET to)
{
  char			*answer;

  if (ftp->v->cmd_type == LOCAL)
    {
      my_cd(ftp->v);
      answer = get_pwd(ftp->v);
      print_answer(answer, "[CLIENT][CD] : ");
      answer = my_xxfree(answer);
    }
  else if (ftp->v->cmd_type == DISTANT)
    {
      my_xwrite(to, ftp->v->prompt, my_strlen(ftp->v->prompt));
      answer = get_cmd(to);
      print_answer(answer, "[SERVER][CD] : ");
      answer = my_xxfree(answer);
    }
}

void			myLs(t_ftp *ftp, SOCKET to)
{
  char			*answer;

  if (ftp->v->cmd_type == LOCAL)
    {
      my_puterror("[CLIENT][LS] \n");
      ls_client(ftp, to);
      my_puterror("\n");
    }
  else if (ftp->v->cmd_type == DISTANT)
    {
      my_xwrite(to, ftp->v->prompt, my_strlen(ftp->v->prompt));
      answer = get_cmd(to);
      print_answer(answer, "[SERVER][LS] :\n");
      answer = my_xxfree(answer);
    }
}

void			myPwd(t_ftp *ftp, SOCKET to)
{
  char			*answer;

  if (ftp->v->cmd_type == LOCAL)
    {
      answer = get_pwd(ftp->v);
      print_answer(answer, "[CLIENT][PWD] : ");
      answer = my_xxfree(answer);
    }
  else if (ftp->v->cmd_type == DISTANT)
    {
      my_xwrite(to, ftp->v->prompt, my_strlen(ftp->v->prompt));
      answer = get_cmd(to);
      print_answer(answer, "[SERVER][PWD] : ");
      answer = my_xxfree(answer);
    }
}
