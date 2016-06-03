/*
** my_printf.h for my_printf in /home/jaubere/Bureau/projets/PSU_2015_minishell2/lib
** 
** Made by jauber_e
** Login   <Jaubert Elise@epitech.net>
** 
** Started on  Wed Mar 30 13:33:46 2016 jauber_e
** Last update Thu Apr  7 14:23:47 2016 jauber_e
*/

#ifndef MY_H_
# define MY_H_

typedef struct	s_exec
{
  char		**command;
  int		redir;
  char		**path;
  char		*file;
}		t_exec;

int	my_getnbr(char *nbr);
int	my_strlen(char *str);
void	my_putstr(char *str);
void	my_puterror(char *str);
int	my_putnbr(int nb);
void	my_putchar(char c);
void	my_swap(char *a, char *b);
void	my_revstr(char *str);
char	*my_malloc(int nb);
char	*my_strstrgnl(char *str, char c);
char	*my_strstr(char *str, char *to_find);
char	*get_next_line(int fd);
char	**copy_env(char **ae, char **env);
int	my_printf(char *str, ...);
char	**my_str_to_wordtab(char *str, char c, char cc);
int	my_str_isnum(char *str);
int	my_strcmp(char *s1, char *s2);
void	my_exit(char **s);
char	**commands(char *com, char **env);
char	**envs(char **command, char **env);
int	my_strncmp(char *s1, char *s2, int nb);
char	**my_cd(char **command, char **env);
char	*my_strcat(char *dest, char *src);
char	**my_setenv(char **command, char **env);
char	**my_unsetenv(char **command, char **env);
int	search_env(char **env, char *str);
void	print_env(char **env);
int	alphanum(char *str);
char	*my_strcpy(char *dest, char *src);
char	*my_strcpy3(char *dest, char *src);
char	**exec_path(t_exec *ex, char **env);
char	**currentdir_path(char **command, char **env);
char	**modif_pwd(char **env, char *newpwd);
char	**my_cd_moins(char **command, char **env);
char	**my_exec(t_exec *ex, char **env);
char	**pipe_command(char **command, char **env);
void	segfault(pid_t pid);

#endif
