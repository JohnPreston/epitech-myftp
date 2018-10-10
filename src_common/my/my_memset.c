/*
** my_memset.c for my_memset in /home/mille_j//rendu/c/42sh/lib
**
** Made by john mille
** Login   <John@epitech.net>
**
** Started on  Sun Oct  3 18:59:41 2010 john mille
** Last update Thu Dec 16 08:56:12 2010 john mille
*/

void		*my_memset(void *str, int c, unsigned int size)
{
  char		*st;
  unsigned int	i;

  i = 0;
  st = (char*)str;
  while (i < size)
    {
      st[i] = c;
      i += 1;
    }
  return (str);
}
