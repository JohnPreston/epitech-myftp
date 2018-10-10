/*
** xfunctions_network_2.c for network functions in /media/data/my_ftp/src_common
**
** Made by john mille
** Login   <John@epitech.net>
**
** Started on  Sun Mar 27 16:03:37 2011 john mille
** Last update Sun Mar 27 18:17:54 2011 john mille
*/

#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include "ftp.h"
#include "my.h"

int			my_xaccept(SOCKET socket, SOCKADDR *addr,
				   SOCKLEN *socklen)
{
  int			admitted;

  admitted = accept(socket, addr, socklen);
  if (admitted == -1)
    perror("accept");
  return (admitted);
}

int			my_xconnect(SOCKET socket, SOCKADDR *addr,
				    SOCKLEN len)
{
  int			admitted;

  admitted = connect(socket, addr, len);
  if (admitted == -1)
    {
      my_xclose(socket);
      perror("connect");
    }
  return (admitted);
}

int			my_xsetsockopt(SOCKET sock, int level, int optname,
				       void *optval, SOCKLEN optlen)
{
  int			opt;

  opt = setsockopt(sock, level, optname, optval, optlen);
  if (opt == -1)
    {
      my_xclose(sock);
      perror("setsockopt");
    }
  return (opt);
}
