/*
** send_file.c for send file in /home/mille_j//my_ftp/src_client
**
** Made by john mille
** Login   <John@epitech.net>
**
** Started on  Wed Mar 30 12:27:08 2011 john mille
** Last update Sun Apr  3 21:29:56 2011 john mille
*/

#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <sys/stat.h>
#include <sys/types.h>
#include "ftp.h"
#include "server.h"
#include "tools.h"
#include "my.h"

int			send_file_ok(t_ftp *ftp, SOCKET to)
{
  struct stat		st;
  char			*tmp;

  tmp = my_strcat("./", ftp->v->argv[1]);
  ftp->v->argv[1] = my_xxfree(ftp->v->argv[1]);
  ftp->v->argv[1] = tmp;
  my_xstat(ftp->v->argv[1], &st);
  ftp->v->fd_file = open(ftp->v->argv[1], O_RDONLY);
  if (S_ISREG(st.st_mode) && ftp->v->fd_file > 0)
    {
      my_xwrite(ftp->s_cmd, FILE_OK, my_strlen(FILE_OK));
      return (1);
    }
  my_xwrite(to, FILE_KO, my_strlen(FILE_KO));
  return (0);
}

void			send_file_to_client(t_ftp *ftp, pid_t pere)
{
  char			buff[BUFF_SIZE];
  int			nb;

  nb = 0;
  do
    {
      my_memset(buff, '\0', BUFF_SIZE);
      ftp->v->nb_read = my_xread(ftp->v->fd_file, buff, BUFF_SIZE);
      nb += ftp->v->nb_read;
      my_xwrite(ftp->s_data, buff, ftp->v->nb_read);
    } while (nb < ftp->v->file_size);
  my_xclose(ftp->v->fd_file);
  my_xclose(ftp->s_data);
  my_xclose(ftp->s_cmd);
  kill(pere, SIGUSR1);
}

int			can_send_file(SOCKET to)
{
  char			*answer;

  answer = get_cmd(to);
  if (my_strcmp(answer, TRANSFERT_OK) == 0)
    {
      answer = my_xxfree(answer);
      return (1);
    }
  answer = my_xxfree(answer);
  return (0);
}

void			send_file(t_ftp *ftp, SOCKET to)
{
  pid_t			pere;
  pid_t			fils;

  pere = getpid();
  if (send_file_ok(ftp, to))
    {
      send_size(ftp, to);
      if (can_send_file(to))
	{
	  if ((fils = fork()) == 0)
	    {
	      send_file_to_client(ftp, to);
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
