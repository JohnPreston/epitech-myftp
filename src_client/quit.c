/*
** quit.c for quit in /media/data/my_ftp/src_client
**
** Made by john mille
** Login   <John@epitech.net>
**
** Started on  Mon Mar 28 11:18:32 2011 john mille
** Last update Sun Apr  3 11:50:43 2011 john mille
*/

#include <stdlib.h>
#include "ftp.h"
#include "client.h"
#include "tools.h"
#include "my.h"

void			quit_client(t_client *c)
{
  if (c->ftp->data == 0)
    {
      clean_vars(c->ftp->v);
      my_xclose(c->ftp->s_cmd);
      my_xclose(c->ftp->s_data);
      c->ftp->v = my_xfree(c->ftp->v);
      c->ftp = my_xfree(c->ftp);
      my_puterror("\nQuit Client\n");
      exit(EXIT_FAILURE);
    }
  else
    my_puterror("A file is currently being transfered. Please, wait\n");
}

void			quit_init_failure(t_client *c)
{
  if (c->ftp->s_data > 0)
    my_xclose(c->ftp->s_data);
  if (my_tablen(c->ftp->v->env))
    clean_vars(c->ftp->v);
  if (c->ftp->v)
    c->ftp->v = my_xfree(c->ftp->v);
  if (c->ftp)
    c->ftp = my_xfree(c->ftp);
  exit(EXIT_FAILURE);
}

void			quit(t_ftp *ftp, __attribute__((unused))SOCKET to)
{
  if (ftp->data == 0)
    {
      my_xwrite(ftp->s_cmd, ftp->v->prompt, my_strlen(ftp->v->prompt));
      clean_vars(ftp->v);
      my_xclose(ftp->s_cmd);
      my_xclose(ftp->s_data);
      ftp->v = my_xfree(ftp->v);
      ftp = my_xfree(ftp);
      my_puterror("Quit Client\n");
      exit(EXIT_FAILURE);
    }
  else
    my_puterror("A file is currently being transfered. Please, wait\n");
}
