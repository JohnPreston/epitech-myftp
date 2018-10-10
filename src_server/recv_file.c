/*
** recv_file.c for recv file in /home/mille_j//my_ftp/src_server
**
** Made by john mille
** Login   <John@epitech.net>
**
** Started on  Wed Mar 30 12:27:22 2011 john mille
** Last update Sun Apr  3 18:50:49 2011 john mille
*/

#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <stdio.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include "ftp.h"
#include "server.h"
#include "tools.h"
#include "my.h"

int			check_file(t_ftp *ftp, SOCKET to)
{
  char			*file;

  file = my_strcat("./", ftp->v->argv[1]);
  ftp->v->argv[1] = my_xxfree(ftp->v->argv[1]);
  ftp->v->argv[1] = file;
  if ((ftp->v->fd_file = open(ftp->v->argv[1], O_RDONLY)) == -1)
    {
      my_xwrite(to, TRANSFERT_OK, my_strlen(TRANSFERT_OK));
      ftp->v->fd_file = open(ftp->v->argv[1], O_WRONLY | O_CREAT, 00644);
      return (1);
    }
  my_xwrite(to, TRANSFERT_KO, my_strlen(TRANSFERT_KO));
  return (0);
}

int			get_size(t_ftp *ftp, SOCKET to)
{
  char			*answer;

  answer = get_cmd(to);
  ftp->v->file_size = my_getnbr(answer);
  if (ftp->v->file_size == -1)
    {
      my_xwrite(to, TRANSFERT_KO, my_strlen(TRANSFERT_KO));
      my_puterror("Invalid File Size.\n");
      return (0);
    }
  my_xwrite(to, TRANSFERT_OK, my_strlen(TRANSFERT_OK));
  return (1);
}

void			transfert_from_socket(t_ftp *ftp, pid_t pere)
{
  char			buff[BUFF_SIZE];

  do
    {
      my_memset(buff, '\0', BUFF_SIZE);
      ftp->v->nb_read = my_xread(ftp->s_data, buff, BUFF_SIZE);
      my_xwrite(ftp->v->fd_file, buff, ftp->v->nb_read);
    } while (ftp->v->nb_read == BUFF_SIZE);
  my_xclose(ftp->v->fd_file);
  my_xclose(ftp->s_cmd);
  my_xclose(ftp->s_data);
  kill(pere, SIGUSR1);
}

void			recv_file(t_ftp *ftp, SOCKET to)
{
  pid_t			pere;
  pid_t			fils;

  pere = getpid();
  if (check_file(ftp, to))
    {
      if (get_size(ftp, to))
	{
	  if ((fils = fork()) == 0)
	    {
	      transfert_from_socket(ftp, pere);
	      exit(EXIT_SUCCESS);
	    }
	  setpgid(fils, pere);
	  ftp->data = 1;
	}
    }
}
