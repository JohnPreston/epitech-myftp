/*
** SDL.c for sdl ftp  in /home/mille_j//c/My_ftp/src_common
**
** Made by john mille
** Login   <John@epitech.net>
**
** Started on  Sat Apr  2 10:18:48 2011 john mille
** Last update Sun Apr  3 21:16:35 2011 john mille
*/

#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include "ftp.h"
#include "tools.h"
#include "my_sdl.h"
#include "my.h"

static	t_mysdl		*my_sdl;
static	t_ftp		*my_ftp;

int			init_SDL(t_mysdl *sdl)
{
  if (SDL_Init(SDL_INIT_VIDEO) == -1)
    {
      perror("SDL INIT FAILED.\n");
      exit(EXIT_SUCCESS);
    }
  sdl->ecran = SDL_SetVideoMode(400, 32, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
  SDL_WM_SetCaption("Chargement du fichier", NULL);
  SDL_FillRect(sdl->ecran, NULL, SDL_MapRGB(sdl->ecran->format,
  					    0xFF, 0xFF, 0xFF));
  sdl->bar = SDL_CreateRGBSurface(SDL_HWSURFACE | SDL_DOUBLEBUF,
  				  1, 32, 32, 0, 0, 0, 0);
  SDL_FillRect(sdl->bar, NULL, SDL_MapRGB(sdl->ecran->format,
  					  0xFF, 0x00, 0x00));
  sdl->on = 1;
  sdl->position.x = 0;
  sdl->position.y = 0;
  SDL_BlitSurface(sdl->bar, NULL, sdl->ecran, &sdl->position);
  SDL_Flip(sdl->ecran);
  return (1);
}

static void		gere_sigpipe()
{
  signal(SIGPIPE, gere_sigpipe);
  my_puterror("Connection Close Unexpectedly While Transfering\n");
  kill(my_sdl->pere, SIGUSR1);
  my_xclose(my_ftp->s_cmd);
  my_xclose(my_ftp->s_data);
  my_xclose(my_ftp->v->fd_file);
  clean_vars(my_ftp->v);
  my_ftp->v = my_xfree(my_ftp->v);
  my_ftp = my_xfree(my_ftp);
  SDL_FreeSurface(my_sdl->bar);
  SDL_Quit();
  exit(EXIT_FAILURE);
}

void			draw(t_ftp *ftp, t_mysdl *sdl, double nb, double x)
{
  double		z;

  x = ((nb / ftp->v->file_size) * 100 * 4);
  z = 0;
  while (z < x)
    {
      sdl->position.x = z;
      SDL_BlitSurface(sdl->bar, NULL, sdl->ecran, &sdl->position);
      z += 1;
    }
  SDL_Flip(sdl->ecran);
}

void			get_file(t_ftp *ftp, t_mysdl *sdl, SOCKET from, SOCKET to)
{
  char			buff[BUFF_SIZE];
  double		nb;
  double		x;

  nb = 0.0;
  x = 0.0;
  do
    {
      signal(SIGPIPE, gere_sigpipe);
      my_memset(buff, '\0', BUFF_SIZE);
      ftp->v->nb_read = my_xread(from, buff, BUFF_SIZE);
      if (ftp->v->nb_read == 0)
	gere_sigpipe();
      nb += ftp->v->nb_read;
      draw(ftp, sdl, nb, x);
      my_xwrite(to, buff, ftp->v->nb_read);
    } while ((int)nb < ftp->v->file_size);
}

void			mainSDL(t_ftp *ftp, pid_t pere, SOCKET from, SOCKET to)
{
  t_mysdl		*sdl;

  sdl = my_xmalloc(sizeof(*sdl));
  if (init_SDL(sdl))
    {
      sdl->pere = pere;
      my_sdl = sdl;
      my_ftp = ftp;
      get_file(ftp, sdl, from, to);
      kill(pere, SIGUSR1);
      my_xclose(ftp->s_cmd);
      my_xclose(ftp->s_data);
      my_xclose(ftp->v->fd_file);
      SDL_FreeSurface(sdl->bar);
      SDL_Quit();
    }
  sdl = my_xfree(sdl);
}
