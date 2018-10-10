/*
** my.h for my in /home/mille_j//rendu/c/42sh/lib
**
** Made by john mille
** Login   <John@epitech.net>
**
** Started on  Sun Oct  3 18:11:54 2010 john mille
** Last update Sat Apr  2 01:12:21 2011 john mille
*/

#ifndef		__MY_H__
# define	__MY_H__

/************** void function ***********************************************/
void		my_show_tab(char **array, char c);
void		my_putchar(char c);
void		my_putstr(char *str);
void		my_puterror(char *str);
void		my_putnbr(int nb);
void		my_strcpy(char *dest, char *src);
void		my_strncpy(char *dest, char *src, int n);
void		my_strcpy2(char *dest, char *src, char c);
void		my_strcpy3(char *dest, char *src, char c);
void		my_strcpy4(char *dest, char *src, int from, int to);

/************** void * functions **********************************************/
/******************************************************************************/
void		*my_xmalloc(unsigned int size);
void		*my_xxmalloc(unsigned int size);
void		*my_xfree(void *ptr);
void            *my_memset(void *str, int c, unsigned int size);
char		*my_xxfree(char *str);
char		**my_xfree_tab(char **array);

/******************************************************************************/
/*************** char * functions *********************************************/
char		*my_strdup(char *str);
char		*my_strdup2(char *str, char c);
char		*my_strdup3(char *str, char c);
char		*my_strdup4(char *str, int from, int to);
char		*my_strcat(char *s1, char *s2);
char		*my_strncat(char *s1, char *s2, int n);
char		*replace(char *to_replace, char *to_add);

/******************************************************************************/
/************** int functions *************************************************/
int		my_strlen(char *str);
int		my_strlen2(char *str, char c);
int		my_strlen3(char *str, char c);
int		my_strcmp(char *s1, char *s2);
int		my_strncmp(char *s1, char *s2, int n);
int		my_tablen(char **array);
int		my_getnbr(char *str);
int		my_strstr(char *str, char *to_find);
int		my_xopen(const char *path);
int		my_xopen2(const char *path);
int		my_xopen3(const char *path);
int		my_xread(const int fd, char *buffer, unsigned int size);
int		my_xwrite(const int fd, char *buffer, unsigned int size);

/******************************************************************************/
/******************************************************************************/
#endif		/* !__MY_H__ */
