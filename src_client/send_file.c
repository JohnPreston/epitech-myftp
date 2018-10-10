/*
** send_file.c for send file in /home/mille_j//my_ftp/src_client
**
** Made by john mille
** Login   <John@epitech.net>
**
** Started on  Wed Mar 30 12:27:08 2011 john mille
** Last update Sun Apr  3 18:54:13 2011 john mille
*/

#define _GNU_SOURCE
#include <stdlib.h>
#include <fcntl.h>
#include <termios.h>
#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "ftp.h"
#include "client.h"
#include "tools.h"
#include "my.h"

int			send_syntax_ok(t_ftp *ftp)
{
  struct stat		st;
  char			*tmp;

  if (ftp->v->argc == 2)
    {
      tmp =  my_strcat("./", ftp->v->argv[1]);
      ftp->v->argv[1] = my_xxfree(ftp->v->argv[1]);
      ftp->v->argv[1] = tmp;
      my_xstat(ftp->v->argv[1], &st);
      if (S_ISREG(st.st_mode) &&
	  (ftp->v->fd_file = open(ftp->v->argv[1], O_RDONLY)) > 0)
	return (1);
    }
  if (ftp->v->argc == 2 && ftp->v->fd_file == -1)
    {
      my_puterror(ftp->v->argv[1]);
      my_puterror(": No file found in your directory\n");
    }
  else if (ftp->v->argc == 1)
    my_puterror(SEND_USAGE);
  return (0);
}

int			send_file_ok(t_ftp *ftp, SOCKET to)
{
  char			*answer;

  my_xwrite(to, ftp->v->prompt, my_strlen(ftp->v->prompt));
  answer = get_cmd(to);
  if (my_strcmp(answer, TRANSFERT_OK) == 0)
    return (1);
  else if (my_strcmp(answer, TRANSFERT_KO) == 0)
    my_puterror("FIle Already Exists on the Server\n");
  return (0);
}

int			transfert_on_socket(t_ftp *ftp, pid_t pere)
{
  struct stat		st;

  stat(ftp->v->argv[1], &st);
  ftp->v->file_size = st.st_size;
  mainSDL(ftp, pere, ftp->v->fd_file, ftp->s_data);
  return (EXIT_SUCCESS);
}

int			send_size(t_ftp *ftp, SOCKET to)
{
  struct stat		st;
  FLAG			ret;
  char			*size;

  ret = stat(ftp->v->argv[1], &st);
  if (!ret)
    {
      ret = asprintf(&size, "%ld", st.st_size);
      ftp->v->file_size = st.st_size;
      my_xwrite(to, size, my_strlen(size));
    }
  ftp->v->file_size = -1;
  size = my_xxfree(size);
  size = get_cmd(to);
  if (my_strcmp(size, TRANSFERT_OK) == 0)
    {
      size = my_xxfree(size);
      return (1);
    }
  size = my_xxfree(size);
  return (0);
}

void			send_file(t_ftp *ftp, SOCKET to)
{
  pid_t			pere;
  pid_t			fils;

  pere = getpid();
  if (send_syntax_ok(ftp))
    {
      if (send_file_ok(ftp, to))
	{
	  if (send_size(ftp, to))
	    {
	      if ((fils = (fork())) == 0)
		{
		  transfert_on_socket(ftp, pere);
		  exit(EXIT_SUCCESS);
		}
	      else if (fils == -1)
		perror("fork");
	      setpgid(fils, pere);
	      ftp->data = 1;
	    }
	}
    }
}
