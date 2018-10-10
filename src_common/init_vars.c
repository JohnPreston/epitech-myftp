/*
** init_vars.c for init_vars in /media/data/my_ftp/src_server
**
** Made by john mille
** Login   <John@epitech.net>
**
** Started on  Sun Mar 27 17:20:03 2011 john mille
** Last update Mon Mar 28 12:14:31 2011 john mille
*/

#include <stdlib.h>
#include "ftp.h"
#include "tools.h"
#include "my.h"

void			clean_vars(t_vars *v)
{
  if (v->env)
    v->env = my_xfree_tab(v->env);
  if (v->argv)
    v->argv = my_xfree_tab(v->argv);
  if (v->prompt)
    v->prompt = my_xxfree(v->prompt);
  if (v->cd_minus)
    v->cd_minus = my_xxfree(v->cd_minus);
  if (v->recv_cmd)
    v->recv_cmd = my_xxfree(v->recv_cmd);
}

char			**get_extern_env()
{
  extern char		**environ;
  char			**env;
  int			i;

  i = 0;
  if (!my_tablen(environ))
    return (NULL);
  env = my_xmalloc((my_tablen(environ) + 1) * sizeof(*env));
  while (environ[i])
    {
      env[i] = my_strdup(environ[i]);
      i += 1;
    }
  env[i] = NULL;
  return (env);
}

int			init_vars(t_vars *v)
{
  v->env = get_extern_env();
  if (!v->env)
    return (INIT_FAILURE);
  v->prompt = NULL;
  v->argv = NULL;
  v->recv_cmd = NULL;
  v->recv_data = NULL;
  v->cd_minus = my_getenv(v, "PWD");
  return (INIT_SUCCESS);
}
