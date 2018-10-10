/*
** server.h for server in /media/data/my_ftp/include
**
** Made by john mille
** Login   <John@epitech.net>
**
** Started on  Sun Mar 27 14:47:26 2011 john mille
** Last update Sun Apr  3 15:56:12 2011 john mille
*/

#ifndef			__SERVER_H__
# define		__SERVER_H__

#include		"ftp.h"

typedef struct		s_server
{
  int			gid;
  SOCKET		s_cmd;
  SOCKET		s_data;
  SOCKADDR_IN		sin_cmd;
  SOCKADDR_IN		sin_data;
  SOCKLEN		sin_cmd_size;
  SOCKLEN		sin_data_size;
  PROTO			*proto;
  PORT			p_cmd;
  PORT			p_data;
  pid_t			pere;
  pid_t			fils;
  gid_t			server;
  t_ftp			*ftp;
}			t_server;

/******************************************************************************/
/********************** functions *********************************************/
void			quit_client_closed(t_server *s);
void			quit_whole_server(t_server *s);
void			quit(t_ftp *ftp, SOCKET to);
void			send_file_to_client(t_ftp *ftp, SOCKET to);
void			send_size(t_ftp *ftp, SOCKET to);
void			cd_server(t_ftp *ftp, SOCKET to);
void			ls_server(t_ftp *ftp, SOCKET to);
void			pwd_server(t_ftp *ftp, SOCKET to);
void			cd_server(t_ftp *ftp, SOCKET to);
void			get_user(t_ftp *ftp, SOCKET to);
void			recv_file(t_ftp *ftp, SOCKET to);
void			send_file(t_ftp *ftp, SOCKET to);
void			do_cmds(t_ftp *ftp);

int			init_server(t_server *server, PORT cmd, PORT data);
int			init_connection_server(t_server *server);

int			multi_client(t_server *s);
int			shell_server(t_server *s);
int			manage_cmds(t_server *s);

int			syst(t_ftp *ftp, SOCKET to);
int			port(t_ftp *ftp, SOCKET to);
int			feat(t_ftp *ftp, SOCKET to);

int			send_cmd_s_to_c(t_server *s, char *cmd);
int			recv_cmd_from_client(t_server *s);

int			gere_path(t_vars *v, char *home, char *pwd);
int			move_from_root(t_vars *v, char *curr_path, char *home);
int			go_to_home(t_vars *v, char *curr, char *home);

char			**make_pwd_tab(char **path_tab, char *curr_path,
				       char *h);
/******************************************************************************/
/******************************************************************************/
#endif			/* !__SERVER_H__ */
