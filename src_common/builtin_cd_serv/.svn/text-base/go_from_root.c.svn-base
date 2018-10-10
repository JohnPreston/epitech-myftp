/*
** go_from_root.c for go from root in /home/mille_j//42sh/src/builtin_cd
**
** Made by john mille
** Login   <John@epitech.net>
**
** Started on  Wed Nov 17 20:23:22 2010 john mille
** Last update Sun Dec 12 15:07:41 2010 john mille
*/

#include "42sh.h"
#include "builtin_cd.h"
#include "tools.h"
#include "my.h"

int		move_from_root(t_vars *v, char *curr_path)
{
  char		*tmp;
  int		to_find;
  int		exe;

  to_find = find_pos_in_env(v->env, "PWD");
  exe = my_xchdir(v->argv[1]);
  if (to_find != NOT_FOUND && exe)
    {
      tmp = my_strcat("PWD=", v->argv[1]);
      v->env = update_elem_in_tab(v->env, tmp, to_find);
      v->cd_minus = my_xxfree(v->cd_minus);
      v->cd_minus = my_strdup(curr_path);
      tmp = my_xxfree(tmp);
    }
  return (exe);
}
