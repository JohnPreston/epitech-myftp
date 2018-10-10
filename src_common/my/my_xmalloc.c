/*
** my_xmalloc.c for my_xmalloc in /home/mille_j//rendu/c/42sh/lib
**
** Made by john mille
** Login   <John@epitech.net>
**
** Started on  Sun Oct  3 19:04:24 2010 john mille
** Last update Thu Dec 16 01:40:22 2010 john mille
*/

#include <stdlib.h>
#include "my.h"

void		*my_xmalloc(unsigned int size)
{
  void		*ptr;

  ptr = malloc(size);
  if (!ptr)
    exit(EXIT_FAILURE);
  ptr = my_memset(ptr, 0, size);
  return (ptr);
}

void		*my_xxmalloc(unsigned int size)
{
  void		*ptr;

  ptr = my_xmalloc(size);
  ptr = my_memset(ptr, 0, size);
  return (ptr);
}
