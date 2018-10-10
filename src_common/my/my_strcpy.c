/*
** my_strcpy.c for my_strcpy in /home/mille_j//rendu/c/42sh/lib
**
** Made by john mille
** Login   <John@epitech.net>
**
** Started on  Sun Oct  3 18:14:17 2010 john mille
** Last update Tue Nov  9 15:42:24 2010 john mille
*/

void		my_strcpy(char *dest, char *src)
{
  int		i;

  i = 0;
  if (dest && src)
    {
      while (src[i])
	{
	  dest[i] = src[i];
	  i += 1;
	}
    }
}

void		my_strncpy(char *dest, char *src, int n)
{
  int		i;

  i = 0;
  if (dest && src)
    {
      while (i < n)
	{
	  dest[i] = src[i];
	  i += 1;
	}
    }
}

void		my_strcpy2(char *dest, char *src, char c)
{
  int		i;

  i = 0;
  if (dest && src)
    {
      while (src[i] != c)
	{
	  dest[i] = src[i];
	  i += 1;
	}
    }
}

void		my_strcpy3(char *dest, char *src, char c)
{
  int		i;
  int		j;

  i = 0;
  j = 0;
  if (dest && src)
    {
      while (src[i])
	{
	  if (src[i] == c)
	    {
	      i += 1;
	      while (src[i])
		{
		  dest[j] = src[i];
		  j += 1;
		  i += 1;
		}
	    }
	  if (src[i])
	    i += 1;
	}
    }
}

void		my_strcpy4(char *dest, char *src, int from, int to)
{
  int		i;
  int		j;

  i = from;
  j = 0;
  while (i != to)
    {
      dest[j] = src[i];
      i += 1;
    }
}
