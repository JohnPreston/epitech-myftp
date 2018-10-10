/*
** check_builtins_env_syntax.c for check_builtins_env_syntax for 42sh in /home/mille_j//rendu/c/42sh/src
**
** Made by john mille
** Login   <John@epitech.net>
**
** Started on  Sun Oct  3 22:16:49 2010 john mille
** Last update Wed Mar 30 10:57:55 2011 john mille
*/

#include <stdlib.h>
#include "ftp.h"
#include "tools.h"
#include "my.h"

int		check_setenv_syntax(t_vars *v)
{
  if (v->argc == 1 && my_strcmp(v->argv[0], "setenv") == 0)
    {
      my_show_tab(v->env, '\n');
      return (SYNTAX_KO);
    }
  else if ((v->argc == 2 || v->argc == 3) &&
	   find_char(v->argv[1], '=') == FOUND)
    {
      my_puterror("setenv: Syntax Error.\n");
      return (SYNTAX_KO);
    }
  else if (v->argc > 3)
    {
      my_puterror("setenv: Too many arguments.\n");
      return (SYNTAX_KO);
    }
  return (SYNTAX_OK);
}

int		check_unsetenv_syntax(t_vars *v)
{
  if (v->argc == 1)
    return (SYNTAX_KO);
  else if (v->argc == 2 && my_strcmp(v->argv[1], "*") == 0)
    return (ALL);
  return (SYNTAX_OK);
}

int		check_env_syntax(t_vars *v)
{
  int		i;

  i = 1;
  if (v->argc > 1)
    {
      while (v->argv[i])
	{
	  if (find_char(v->argv[i], '-') == NOT_FOUND)
	    {
	      my_puterror("env: ");
	      my_puterror(v->argv[i]);
	      my_puterror(": No such file or directory\n");
	      return (SYNTAX_KO);
	    }
	  i += 1;
	}
    }
  return (SYNTAX_OK);
}
