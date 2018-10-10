/*
** print_shell.c for print_shell in /home/mille_j//my_ftp/src_client
**
** Made by john mille
** Login   <John@epitech.net>
**
** Started on  Tue Mar 29 23:15:19 2011 john mille
** Last update Sat Apr  2 00:32:07 2011 john mille
*/

#include <stdlib.h>
#include <signal.h>
#include <stdio.h>
#include "tools.h"
#include "ftp.h"
#include "client.h"
#include "my.h"

void			print_shell(t_client *c)
{
  if (c->ftp->v->cmd_type == DISTANT && my_strlen(c->ftp->v->recv_cmd))
    {
      printf("[SERVER] [ANSWER] : %s", c->ftp->v->recv_cmd);
    }
}
