/*
** my_sdl.h for my sdl in /home/mille_j//c/My_ftp/include
**
** Made by john mille
** Login   <John@epitech.net>
**
** Started on  Sat Apr  2 11:50:03 2011 john mille
** Last update Sun Apr  3 16:07:16 2011 john mille
*/

#ifndef			__MY_SDL_H__
# define		__MY_SDL_H__
#include		<SDL/SDL.h>

/******************************************************************************/
/******************************************************************************/
typedef struct		s_mysdl
{
  SDL_Surface		*ecran;
  SDL_Surface		*bar;
  SDL_Event		event;
  SDL_Rect		position;
  int			pere;
  int			on;
}			t_mysdl;

/******************************************************************************/
/******************************************************************************/
#endif			/* !__MY_SDL_H__ */
