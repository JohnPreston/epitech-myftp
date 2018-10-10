/*
** client.h for client in /media/data/my_ftp/include
**
** Made by john mille
** Login   <John@epitech.net>
**
** Started on  Sun Mar 27 14:47:38 2011 john mille
** Last update Sun Apr  3 11:49:19 2011 john mille
*/

#ifndef			__CLIENT_H__
# define		__CLIENT_H__

#include		"ftp.h"

typedef struct		s_client
{
  t_ftp			*ftp;
  PROTO			*proto;
}			t_client;

/******************************************************************************/
/********************** client ************************************************/
void			print_shell(t_client *c);
void			quit_client(t_client *c);
void			quit(t_ftp *ftp, SOCKET to);
void			quit_init_failure(t_client *c);
void			user_authen(t_ftp *ftp, SOCKET to);
void			send_file(t_ftp *ftp, SOCKET to);
void			recv_file(t_ftp *ftp, SOCKET to);

int			do_cmds(t_ftp *ftp);

FLAG			check_args(char **argv);
FLAG			check_init(t_client *c, FLAG init);
FLAG			check_init_connection(t_client *c, FLAG init);

int			init_client(t_client *c, char *addr, PORT port);
int                     init_connection_client(t_client *c);
int                     recv_cmd_from_server(t_client *c);
int                     send_cmd_c_to_s(t_client *c, char *cmd);

int                     check_connect(t_client *c);
int                     check_welcome(t_client *c);

int			shell_client(t_client *c);
int			manage_cmds(t_client *c);
int			do_local_functions(t_client *c);
int			do_dist_functions(t_client *c);
int			check_list(t_vars *v);

int			move_from_root(t_vars *v, char *curr_path);
int			go_to_home(t_vars *v, char *home, char *curr);
char			*clean_cmd(char *cmd);
char			**make_pwd_tab(char **path_tab, char *curr_path);

/******************************************************************************/
/******************************************************************************/
#endif			/* !__CLIENT_H__ */
