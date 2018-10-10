##
## Makefile for my_ftp in /home/mille_j//data/my_ftp
## 
## Made by john mille
## Login   <John@epitech.net>
## 
## Started on  Sun Mar 27 14:43:47 2011 john mille
## Last update Sun Apr  3 22:02:26 2011 john mille
##

N_SERVEUR	=		serveur
N_CLIENT	=		client

HDDIR		=		./include/
LDDIR		=		./lib/

SERV_DIR	=		./src_server/
COMMON_DIR	=		./src_common/
CLI_DIR		=		./src_client/
BUILT_CD_SERV	=		$(COMMON_DIR)builtin_cd_serv/
BUILT_CD_CLIENT	=		$(COMMON_DIR)builtin_cd_client/
BUILT_ENV	=		$(COMMON_DIR)builtin_env/
TAB		=		$(COMMON_DIR)tab/
GET		=		$(COMMON_DIR)get/
LIST		=		$(COMMON_DIR)list/
MY		=		$(COMMON_DIR)my/
XFUNC		=		$(COMMON_DIR)xfunctions/


COMMON_FILES	=		$(MY)my_getnbr.c				\
				$(MY)my_memset.c				\
				$(MY)my_put_tools.c				\
				$(MY)my_strcat.c				\
				$(MY)my_strcmp.c				\
				$(MY)my_strcpy.c				\
				$(MY)my_strdup.c				\
				$(MY)my_strlen.c				\
				$(MY)my_tablen.c				\
				$(MY)my_xfree.c					\
				$(MY)my_xclose.c				\
				$(MY)my_xwrite.c				\
				$(MY)my_xmalloc.c				\
				$(MY)my_xfunctions.c				\
				$(MY)my_str_is_num.c				\
				$(MY)my_strstr.c				\
				$(MY)my_getenv.c				\
				$(GET)get_cmd.c					\
				$(GET)get_argc_argv.c				\
				$(GET)get_ip.c					\
				$(GET)get_cd_path.c				\
				$(GET)get_file_size.c				\
				$(GET)get_pwd.c					\
				$(GET)get_home.c				\
				$(TAB)tab_tools.c				\
				$(TAB)tab_functions.c				\
				$(TAB)sort_word.c				\
				$(LIST)list_functions.c				\
				$(LIST)list_functions_2.c			\
				$(LIST)ls.c					\
				$(XFUNC)xfunctions_network.c			\
				$(XFUNC)xfunctions_network_2.c			\
				$(BUILT_ENV)my_builtins_env.c			\
				$(BUILT_ENV)check_builtins_env_syntax.c		\
				$(COMMON_DIR)init_vars.c			\
				$(COMMON_DIR)SDL.c

SERV_FILES	=		$(SERV_DIR)main_server.c			\
				$(SERV_DIR)init_server.c			\
				$(SERV_DIR)multi_client.c			\
				$(SERV_DIR)init_connection.c			\
				$(SERV_DIR)server_tools.c			\
				$(SERV_DIR)shell_server.c			\
				$(SERV_DIR)do_cmds.c				\
				$(SERV_DIR)manage_cmds.c			\
				$(SERV_DIR)quit.c				\
				$(SERV_DIR)recv_file.c				\
				$(SERV_DIR)send_file.c				\
				$(SERV_DIR)user.c				\
				$(BUILT_CD_SERV)go_from_root.c			\
				$(BUILT_CD_SERV)make_pwd.c			\
				$(BUILT_CD_SERV)my_cd.c

CLI_FILES	=		$(CLI_DIR)main_client.c				\
				$(CLI_DIR)init_client.c				\
				$(CLI_DIR)init_connection.c			\
				$(CLI_DIR)client_tools.c			\
				$(CLI_DIR)quit.c				\
				$(CLI_DIR)shell_client.c			\
				$(CLI_DIR)manage_cmds.c				\
				$(CLI_DIR)do_cmds.c				\
				$(CLI_DIR)print_shell.c				\
				$(CLI_DIR)checK_list.c				\
				$(CLI_DIR)send_file.c				\
				$(CLI_DIR)recv_file.c				\
				$(CLI_DIR)user.c				\
				$(CLI_DIR)cmds.c				\
				$(BUILT_CD_CLIENT)go_from_root.c		\
				$(BUILT_CD_CLIENT)make_pwd.c			\
				$(BUILT_CD_CLIENT)my_cd.c			\
				$(CLI_DIR)checks.c



OBJS_COMMON	=		$(COMMON_FILES:.c=.o)
OBJS_SERVER	=		$(SERV_FILES:.c=.o)
OBJS_CLIENT	=		$(CLI_FILES:.c=.o)

CC		=		gcc
CFLAGS		=		-W -Wall -Wextra -lSDL -lcrypt
HDFLAGS		+=		-I$(HDDIR)

RM		=		rm -f
ECHO		=		echo -e
TAG		=		etags

NORME		=		./norme -nocheat

server		: $(OBJS_COMMON) $(OBJS_SERVER)
		@$(CC) $(CFLAGS) $(HDFLAGS) -o $(N_SERVEUR) $(OBJS_COMMON) $(OBJS_SERVER)
		@$(ECHO) '\033[0;32m> SERVER Compiled Without Error\033[0m'

client		: $(OBJS_COMMON) $(OBJS_CLIENT)
		@$(CC) $(CFLAGS) $(HDFLAGS) -o $(N_CLIENT) $(OBJS_COMMON) $(OBJS_CLIENT)
		@$(ECHO) '\033[0;32m> CLIENT Compiled Without Error\033[0m'

clean		:
		-@$(RM) $(OBJS_COMMON) $(OBJS_SERVER) $(OBJS_CLIENT)
		-@$(RM) *~
		-@$(RM) #*#
		@$(ECHO) '\033[0;35m> Directory cleaned\033[0m'

all		: server client

fclean		: clean
		-@$(RM) $(NAME)
		@$(ECHO) '\033[0;35m> Remove executable\033[0m'

re		: fclean all

tag		:
		-@$(TAG) $(SERV_FILES) $(CLI_FILES) $(COMMON_FILES)
		@$(ECHO) '\033[0;32m> TAGS Done\033[0m'

norme		:
		$(NORME) $(CLI_FILES) $(SERV_FILES) $(COMMON_FILES)

.c.o		:
		$(CC) $(CFLAGS) $(HDFLAGS) -c $< -o $@

.PHONY		: all clean re fclean tag debug norme
