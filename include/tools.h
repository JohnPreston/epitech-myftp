/*
** tools.h for tools in /media/data/my_ftp/include
**
** Made by john mille
** Login   <John@epitech.net>
**
** Started on  Sun Mar 27 14:48:18 2011 john mille
** Last update Sun Apr  3 21:13:18 2011 john mille
*/

#ifndef			__TOOLS_H__
# define		__TOOLS_H__

#include		<sys/stat.h>

#include		"ftp.h"

/******************************************************************************/
/********************** network x functions ***********************************/
SOCKET                  my_xsocket(int domain, int type, int protocol);
int                     my_xbind(SOCKET socketfd, SOCKADDR *addr,
				 SOCKLEN addrlen);
int                     my_xlisten(SOCKET socket, int backlog);
int                     my_xaccept(SOCKET socket, SOCKADDR *addr,
				   SOCKLEN *socklen);
int                     my_xconnect(SOCKET socket, SOCKADDR *addr,
				    SOCKLEN len);
int                     my_xsetsockopt(SOCKET sock, int level, int optname,
				       void *optval, SOCKLEN optlen);
/******************************************************************************/
/*********************** vars | env functions *********************************/
void			clean_vars(t_vars *v);
void			mainSDL(t_ftp *ftp, pid_t pere, SOCKET from, SOCKET to);

int			init_vars(t_vars *v);
int			my_xstat(const char *path, struct stat *st);
int			get_argc(char *str);
int			get_ip_argc(char *str);
char			**get_argv(char *str);
char			**get_ip_argv(char *str);
char			**get_cd_path(char *str);

int			my_setenv(t_vars *v);
int			my_unsetenv(t_vars *v);
int			find_pos_in_env(char **env, char *to_find);
int			my_up_or_setenv(t_vars *v);

unsigned int		get_file_size(const int fd);

char			*get_cmd(const int fd);
char			*my_getenv(t_vars *v, char *to_find);
char			*get_pwd(t_vars *v);
char			*get_home(t_vars *v);
char			*make_pwd(char **array);

char			*concat_tab_elems(char **tab, char *sep);

char			**add_elem_to_tab(char **tab, char *elem);
char			**add_elem_to_tab(char **old_array, char *elem);
char			**delete_elem_in_tab(char **old_array, int pos);
char			**update_elem_in_tab(char **old_array,
					     char *val, int pos);
char			**delete_last_elem_in_tab(char **old_array);

/*******************************************************************************/
/********************** functions **********************************************/
int			my_xchdir(const char *path);
int			str_is_num(char *str);
int			my_strstr(char *str, char *to_find);
int			find_char(char *str, char c);

/*******************************************************************************/
/*******************************************************************************/
t_list			*init_list(char *elem);
t_list			*add_elem_at_end(t_list *list, char *elem);
t_list			*delete_elem_at_begin(t_list *list);
int			list_size(t_list *list);
void			list_dump(t_list *list);
void			free_list(t_list *list);
void			sort_word(t_list *list);

/******************************************************************************/
/********************** cmds **************************************************/
void			ls_client(t_ftp *ftp, SOCKET to);
void			ls_server(t_ftp *ftp, SOCKET to);
void			myLs(t_ftp *ftp, SOCKET to);
void			myCd(t_ftp *ftp, SOCKET to);
void			myPwd(t_ftp *ftp, SOCKET to);
int			my_cd(t_vars *v);
void			help(t_ftp *ftp, SOCKET to);

/******************************************************************************/
/******************************************************************************/
#endif			/* !__TOOLS_H__ */
