/*
** recv_file.c for recv file in /home/mille_j//my_ftp/src_server
**
** Made by john mille
** Login   <John@epitech.net>
**
** Started on  Wed Mar 30 12:27:22 2011 john mille
** Last update Sun Apr  3 18:51:01 2011 john mille
*/

#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "ftp.h"
#include "client.h"
#include "tools.h"
#include "my.h"

int			check_file_on_client(t_ftp *ftp)
{
  char			*tmp;

  tmp = my_strcat("./", ftp->v->argv[1]);
  if (open(tmp, O_RDONLY) < 0)
    {
      tmp = my_xxfree(tmp);
      return (1);
    }
  tmp = my_xxfree(tmp);
  my_puterror("File already exists in your current directory\n");
  return (0);
}

int			file_exits_on_server(t_ftp *ftp, SOCKET to)
{
  char			*answer;

  answer = get_cmd(to);
  if (my_strcmp(FILE_OK, answer) == 0)
    {
      ftp->v->fd_file = open(ftp->v->argv[1], O_WRONLY | O_CREAT, 00644);
      answer = my_xxfree(answer);
      return (1);
    }
  else if (my_strcmp(FILE_KO, answer) == 0)
    {
      my_puterror("No such file on server.\n");
      answer = my_xxfree(answer);
    }
  return (0);
}

int			get_size(t_ftp *ftp, SOCKET to)
{
  char			*answer;

  answer = get_cmd(to);
  ftp->v->file_size = my_getnbr(answer);
  if (ftp->v->file_size == -1)
    {
      my_puterror("Invalid File Size.\n");
      return (0);
    }
  return (1);
}

void			recv_file(t_ftp *ftp, SOCKET to)
{
  pid_t			pere;
  pid_t			fils;

  pere = getpid();
  if (check_file_on_client(ftp))
    {
      write(to, ftp->v->prompt, my_strlen(ftp->v->prompt));
      if (file_exits_on_server(ftp, to) && get_size(ftp, to))
	{
	  my_xwrite(to, TRANSFERT_OK, my_strlen(TRANSFERT_OK));
	  if ((fils = fork()) == 0)
	    {
	      mainSDL(ftp, pere, ftp->s_data, ftp->v->fd_file);
	      exit(EXIT_SUCCESS);
	    }
	  if (fils > 0)
	    {
	      setpgid(fils, pere);
	      ftp->data = 1;
	    }
	}
    }
}
