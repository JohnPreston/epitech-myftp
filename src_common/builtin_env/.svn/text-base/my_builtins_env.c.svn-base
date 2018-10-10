/*
** my_builtins_env.c for my_builtins_env.c in /home/mille_j//rendu/c/42sh/src
**
** Made by john mille
** Login   <John@epitech.net>
**
** Started on  Sun Oct  3 22:10:31 2010 john mille
** Last update Sat Dec 18 22:02:20 2010 john mille
*/

#include <stdlib.h>
#include "42sh.h"
#include "builtins_env.h"
#include "tools.h"
#include "my.h"

int		my_setenv(t_vars *v)
{
  char		*elem;
  char		*tmp;

  if (check_setenv_syntax(v) == SYNTAX_KO)
    return (EXIT_FAILURE);
  else
    {
      if (v->argc == 2)
	{
	  elem = my_strcat(v->argv[1], "=");
	  v->env = add_elem_to_tab(v->env, elem);
	  elem = my_xxfree(elem);
	}
      else if (v->argc == 3)
	{
	  tmp = my_strcat(v->argv[1], "=");
	  elem = my_strcat(tmp, v->argv[2]);
	  v->env = add_elem_to_tab(v->env, elem);
	  tmp = my_xxfree(tmp);
	  elem = my_xxfree(elem);
	}
    }
  return (EXIT_SUCCESS);
}

int		my_unsetenv(t_vars *v)
{
  int		to_find;
  int		i;

  i = 1;
  if (check_unsetenv_syntax(v) == ALL)
    {
      v->env = my_xfree_tab(v->env);
      v->env = my_xmalloc(sizeof(*v->env));
      v->env[0] = NULL;
    }
  else if (check_unsetenv_syntax(v) == SYNTAX_KO)
    return (EXIT_FAILURE);
  else
    {
      while (v->argv[i])
	{
	  to_find = find_pos_in_env(v->env, v->argv[i]);
	  if (to_find != NOT_FOUND)
	    v->env = delete_elem_in_tab(v->env, to_find);
	  i += 1;
	}
    }
  return (EXIT_SUCCESS);
}

int		my_env(t_vars *v)
{
  if (check_env_syntax(v) == SYNTAX_OK)
    {
      my_show_tab(v->env, '\n');
      return (EXIT_SUCCESS);
    }
  return (EXIT_FAILURE);
}

int		my_update_env(t_vars *v, int to_find)
{
  char		*elem;
  char		*tmp;

  elem = NULL;
  if (check_setenv_syntax(v) == SYNTAX_KO ||
      to_find == NOT_FOUND)
    return (EXIT_FAILURE);
  else
    {
      if (v->argc == 2 && to_find != NOT_FOUND)
	{
	  elem = my_strcat(v->argv[1], "=");
	  v->env = update_elem_in_tab(v->env, elem, to_find);
	}
      else if (v->argc == 3 && to_find != NOT_FOUND)
	{
	  tmp = my_strcat(v->argv[1], "=");
	  elem = my_strcat(tmp, v->argv[2]);
	  v->env = update_elem_in_tab(v->env, elem, to_find);
	  tmp = my_xxfree(tmp);
	}
      elem = my_xxfree(elem);
    }
  return (EXIT_SUCCESS);
}

int		my_up_or_setenv(t_vars *v)
{
  int		exec;
  int		to_find;

  to_find = find_pos_in_env(v->env, v->argv[1]);
  if (to_find != NOT_FOUND)
    exec = my_update_env(v, to_find);
  else
    exec = my_setenv(v);
  return (exec);
}
