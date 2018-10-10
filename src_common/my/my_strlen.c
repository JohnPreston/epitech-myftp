/*
** my_strlen.c for my_strlen in /home/mille_j//rendu/c/42sh/lib
**
** Made by john mille
** Login   <John@epitech.net>
**
** Started on  Sun Oct  3 18:08:45 2010 john mille
** Last update Tue Nov  9 15:43:33 2010 john mille
*/

int		my_strlen(char *str)
{
  int		i;

  i = 0;
  if (!str)
    return (i);
  while (str[i])
    i += 1;
  return (i);
}

int		my_strlen2(char *str, char c)
{
  int		i;

  i = 0;
  if (!str)
    return (i);
  while (str[i] != c)
    i += 1;
  return (i);
}

int		my_strlen3(char *str, char c)
{
  int		i;
  int		j;

  i = 0;
  j = 0;
  if (!str)
    return (j);
  while (str[i])
    {
      if (str[i] == c)
	{
	  while (str[i])
	    {
	      i += 1;
	      j += 1;
	    }
	  return (j);
	}
      i += 1;
    }
  return (j);
}
