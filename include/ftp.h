/*
** ftp.h for ftp in /media/data/my_ftp/include
**
** Made by john mille
** Login   <John@epitech.net>
**
** Started on  Sun Mar 27 14:47:16 2011 john mille
** Last update Sun Apr  3 21:50:15 2011 john mille
*/

#include			<sys/socket.h>
#include			<netinet/in.h>
#include			<arpa/inet.h>
#include			<sys/types.h>
#include			<netdb.h>

#ifndef				__FTP_H__
# define			__FTP_H__

# define			BUFF_SIZE	4069
# define			NOT_FOUND	-1
# define			FOUND		0

# define			UNKNOWN		0
# define			LOCAL		1
# define			DISTANT		2

# define			INIT_FAILURE	-1
# define			INIT_SUCCESS	1
# define			ENV_FAILURE	-2

# define			INIT_ERROR	"Could Not Initialize. Quit.\n"
# define			ENVIRON_ERROR	"No environnement. Could not start.\n"
# define			INIT_CO_ERROR	"Connection to server impossible.\n"
# define			AUTH_ERROR	"Authentification Failed\n"

# define			USER_OK		"331 Password required for user\n"
# define			USER_KO		"Invalid User\n"

# define			PASS_OK		"230 PASS_OK - Logged on\n"
# define			PASS_KO		"530 PASS KO - Login or Passwd incorrect\n"

# define			FILE_OK		"FILE OK"
# define			FILE_KO		"FILE KO"

# define			SYST		"215 UNIX - FTP done by mille_j\n"
# define			FEAT		"211 - LS\n"
# define			FEAT_END	"211 End\n"

# define			SERVER_USAGE	"Usage: ./serveur PORT\n"
# define			CLIENT_USAGE	"Usage: ./client ip_server PORT\n"
# define			USER_USAGE	"USER login\n"
# define			PASS_USAGE	"PASS password\n"

# define			LS_ERROR	"ls: Usage: ls option [-a]\n"

# define			WELCOME		"220 - Welcome On FTP Server\n"
# define			WELCOME_OK	"WELCOME SUCCESS"
# define			WELCOME_KO	"WELCOME FAILURE"
# define			WAIT_WELCOME	"WANTS WELCOME"
# define			CLOSE_MSG	"CLOSING CONNECTION\n"

# define			CON_DATA_OK	"DATA CONNECTION SUCCESS\n"
# define			CON_DATA_KO	"DATA CONNECTION FAILURE\n"

# define			SYNTAX_KO	0
# define			SYNTAX_OK	1
# define			ALL		2

# define			SEND_USAGE	"Usage: send: send file\n"

# define			TRANSFERT_OK	"OK FOR FILE TRANSFERT"
# define			TRANSFERT_KO	"KO FOR FILE TRANSFERT"
# define			TRANSF_ERROR	"Transfert Error\n"

int				my_xclose(const int fd);

typedef int			PORT;
typedef int			FLAG;
typedef int			SOCKET;
typedef struct	sockaddr	SOCKADDR;
typedef struct	sockaddr_in	SOCKADDR_IN;
typedef struct	protoent	PROTO;
typedef socklen_t		SOCKLEN;

typedef struct			s_vars
{
  FLAG				write;
  int				fd_file;
  int				nb_read;
  int				file_size;
  int				argc;
  int				cmd_type;
  char				*cd_minus;
  char				*recv_cmd;
  char				*recv_data;
  char				*prompt;
  char				**argv;
  char				**env;
  char				*str_tmp;
  char				**tab_tmp;
}				t_vars;

typedef struct			s_users
{
  char				*login;
  char				*passwd;
  char				*dir;
  FLAG				subdirs;
}				t_users;

typedef struct			s_ftp
{
  SOCKET			s_cmd;
  SOCKET			s_data;
  SOCKADDR_IN			cin_cmd;
  SOCKADDR_IN			cin_data;
  SOCKLEN			cin_cmd_size;
  SOCKLEN			cin_data_size;
  PORT				p_cmd;
  PORT				p_data;
  FLAG				opt;
  FLAG				connected;
  FLAG				data;
  FLAG				auth;
  t_vars			*v;
  t_users			*user;
}				t_ftp;

typedef struct			s_functions
{
  int				id;
  FLAG				auth;
  FLAG				data;
  char				*flag;
  void				(*func)(t_ftp *ftp, SOCKET to);
}				t_functions;

typedef struct			s_list
{
  char				*str;
  void				*prev;
  void				*next;
}				t_list;

#endif			/* !__FTP_H__ */
