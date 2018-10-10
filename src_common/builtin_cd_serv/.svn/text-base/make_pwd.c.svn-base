/*
** make_pwd.c for make pwd in /home/mille_j//42sh/src/builtin_cd
**
** Made by john mille
** Login   <John@epitech.net>
**
** Started on  Tue Nov 16 22:02:05 2010 john mille
** Last update Sun Dec 12 15:08:21 2010 john mille
*/

#include <stdlib.h>
#include "42sh.h"
#include "builtin_cd.h"
#include "tools.h"
#include "gets.h"
#include "my.h"

char		**tab_cpy(char **array)
{
  char		**new;
  int		i;

  i = 0;
  new = my_xmalloc((my_tablen(array) + 1) * sizeof(*new));
  while (array[i])
    {
      new[i] = my_strdup(array[i]);
      i += 1;
    }
  new[i] = NULL;
  return (new);
}

char		**make_pwd_tab(char **path_tab, char *curr_path)
{
  char		**final;
  char		**tmp;
  char		*pwd;
  int		i;

  tmp = get_cd_path(curr_path);
  i = my_tablen(tmp);
  final = tab_cpy(tmp);
  while (path_tab[i])
    {
      if (my_strncmp(path_tab[i], "..", 2) == 0)
	{
	  pwd = make_pwd(final);
	  if (my_strcmp(pwd, "/"))
	    final = delete_last_elem_in_tab(final);
	  pwd = my_xxfree(pwd);
	}
      else if (my_strncmp(path_tab[i], "..", 2))
	final = add_elem_to_tab(final, path_tab[i]);
	  i += 1;
    }
  path_tab = my_xfree_tab(path_tab);
  tmp = my_xfree_tab(tmp);
  return (final);
}

char		*make_pwd(char **array)
{
  char		*pwd;
  char		*tmp;
  int		i;

  i = 0;
  pwd = my_xxmalloc(2 * sizeof(*pwd));
  pwd[0] = '/';
  while (array[i])
    {
      tmp = pwd;
      pwd = my_strcat(tmp, array[i]);
      tmp = my_xxfree(tmp);
      tmp = pwd;
      pwd = my_strcat(tmp, "/");
      tmp = my_xxfree(tmp);
      i += 1;
    }
  return (pwd);
}
