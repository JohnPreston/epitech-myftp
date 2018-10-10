/*
** manage_cmds.c for manage_cmds in /home/mille_j//my_ftp/src_client
**
** Made by john mille
** Login   <John@epitech.net>
**
** Started on  Tue Mar 29 00:37:27 2011 john mille
** Last update Sun Apr  3 11:19:46 2011 john mille
*/

#include <stdlib.h>
#include <stdio.h>
#include "ftp.h"
#include "client.h"
#include "tools.h"
#include "my.h"

void			define_cmd_type(t_vars *v)
{
  if (my_tablen(v->argv))
    {
      if (my_strstr(v->argv[0], "!") == 0)
	{
	  v->argv[0] = clean_cmd(v->argv[0]);
	  v->cmd_type = LOCAL;
	}
      else if ((my_strcmp(v->argv[0], "quit") == 0) ||
	       (my_strcmp(v->argv[0], "help") == 0))
	v->cmd_type = LOCAL;
      else if (my_strstr(v->argv[0], "!") == NOT_FOUND && check_list(v))
	v->cmd_type = DISTANT;
      else
	v->cmd_type = UNKNOWN;
    }
}

int			manage_cmds(t_client *c)
{
  FLAG			ret;

  if (my_strlen(c->ftp->v->prompt) > 1)
    {
      c->ftp->v->argc = get_argc(c->ftp->v->prompt);
      c->ftp->v->argv = get_argv(c->ftp->v->prompt);
      define_cmd_type(c->ftp->v);
      ret = do_cmds(c->ftp);
      c->ftp->v->argv = my_xfree_tab(c->ftp->v->argv);
      c->ftp->v->prompt = my_xxfree(c->ftp->v->prompt);
      c->ftp->v->recv_cmd = my_xxfree(c->ftp->v->recv_cmd);
      c->ftp->v->cmd_type = -1;
    }
  return (EXIT_SUCCESS);
}
