/*
** my_cd.c for my cd in /home/mille_j//42sh/src/builtin_cd
**
** Made by john mille
** Login   <John@epitech.net>
**
** Started on  Tue Nov 16 22:01:21 2010 john mille
** Last update Sat Dec 18 22:05:16 2010 john mille
*/

#include <stdlib.h>
#include "42sh.h"
#include "builtin_cd.h"
#include "execs.h"
#include "gets.h"
#include "tools.h"
#include "my.h"

char		**add_path_to_pwd(t_vars *v)
{
  char		**pwd;
  char		**path;
  char		*pwd_str;
  int		i;

  i = 0;
  path = get_cd_path(v->argv[1]);
  pwd_str = get_env_var(v, "PWD");
  if (!pwd_str)
    return (NULL);
  pwd = get_cd_path(pwd_str);
  if (!pwd)
    {
      pwd = my_xmalloc(2 * sizeof(*pwd));
      pwd[0] = "/";
      pwd[1] = NULL;
    }
  while (path[i])
    {
      pwd = add_elem_to_tab(pwd, path[i]);
      i += 1;
    }
  path = my_xfree_tab(path);
  return (pwd);
}

int		go_to_home(t_vars *v, char *home, char *curr_path)
{
  char		*tmp;
  int		pwd;
  int		exe;

  tmp = NULL;
  pwd = find_pos_in_env(v->env, "PWD");
  if (pwd != NOT_FOUND)
    {
      tmp = my_strcat("PWD=", home);
      v->env = update_elem_in_tab(v->env, tmp, pwd);
      v->cd_minus = my_xxfree(v->cd_minus);
      v->cd_minus = my_strdup(curr_path);
    }
  exe = my_xchdir(home);
  tmp = my_xxfree(tmp);
  return (exe);
}

int		go_somewhere(t_vars *v, char **path_tab, char *pwd)
{
  char		*path;
  char		*tmp;
  int		to_find;
  int		exe;

  to_find = find_pos_in_env(v->env, "PWD");
  path_tab = make_pwd_tab(path_tab, pwd);
  path = make_pwd(path_tab);
  exe = my_xchdir(path);
  if (to_find != NOT_FOUND && exe)
    {
      tmp = my_strcat("PWD=", path);
      v->env = update_elem_in_tab(v->env, tmp, to_find);
      v->cd_minus = my_xxfree(v->cd_minus);
      v->cd_minus = my_strdup(pwd);
      tmp = my_xxfree(tmp);
    }
  path = my_xxfree(path);
  path_tab = my_xfree_tab(path_tab);
  return (exe);
}

int		go_back(t_vars *v, char *curr_path)
{
  char		*tmp;
  int		to_find;
  int		exe;

  to_find = find_pos_in_env(v->env, "PWD");
  exe = my_xchdir(v->cd_minus);
  if (to_find != NOT_FOUND && exe)
    {
      tmp = my_strcat("PWD=", v->cd_minus);
      v->env = update_elem_in_tab(v->env, tmp, to_find);
      my_xxfree(v->cd_minus);
      v->cd_minus = my_strdup(curr_path);
      my_xxfree(tmp);
    }
  return (exe);
}

int		my_cd(t_vars *v)
{
  char		**pwd_tab;
  char		*home;
  char		*pwd;
  int		exe;

  exe = 0;
  home = get_home(v);
  pwd = get_pwd(v);
  if (pwd == NULL)
    return (EXIT_SUCCESS);
  else if (v->argc == 1)
    exe = go_to_home(v, home, pwd);
  else if (v->argc == 2 && my_strncmp(v->argv[1], "/", 1) == 0)
    exe = move_from_root(v, pwd);
  else if (v->argc == 2 && my_strcmp(v->argv[1], "-"))
    {
      pwd_tab = add_path_to_pwd(v);
      exe = go_somewhere(v, pwd_tab, pwd);
    }
  else if (v->argc == 2 && my_strcmp(v->argv[1], "-") == 0)
    exe = go_back(v, pwd);
  home = my_xxfree(home);
  pwd = my_xxfree(pwd);
  return (exe);
}
