/*
** go_from_root.c for go from root in /home/mille_j//42sh/src/builtin_cd
**
** Made by john mille
** Login   <John@epitech.net>
**
** Started on  Wed Nov 17 20:23:22 2010 john mille
** Last update Fri Apr  1 19:00:26 2011 john mille
*/

#include <stdlib.h>
#include "ftp.h"
#include "server.h"
#include "tools.h"
#include "my.h"

int		move_from_root(t_vars *v, char *curr_path, char *home)
{
  char		*go_to;
  char		*tmp;
  int		to_find;
  int		exe;

  to_find = find_pos_in_env(v->env, "PWD");
  go_to = my_strcat(home, v->argv[1]);
  exe = my_xchdir(go_to);
  if (to_find != NOT_FOUND && exe)
    {
      tmp = my_strcat("PWD=", home);
      v->env = update_elem_in_tab(v->env, tmp, to_find);
      v->cd_minus = my_xxfree(v->cd_minus);
      v->cd_minus = my_strdup(curr_path);
      tmp = my_xxfree(tmp);
    }
  go_to = my_xxfree(go_to);
  return (exe);
}
