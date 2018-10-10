/*
** strstr.c for strstr in /home/mille_j//42sh/src/lexer
**
** Made by john mille
** Login   <John@epitech.net>
**
** Started on  Mon Nov 22 13:48:43 2010 john mille
** Last update Mon Nov 22 13:48:43 2010 john mille
*/

int		my_strstr(char *str, char *to_find)
{
  int		i;
  int		j;

  i = 0;
  while (str[i])
    {
      j = 0;
      while (to_find[j] && str[i + j] == to_find[j])
	j++;
      if (to_find[j] == '\0')
	return (i);
      i++;
    }
  return (-1);
}
