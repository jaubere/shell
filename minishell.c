/*
** minishell.c for minishell in /home/jaubere/Bureau/projets/PSU_2015_minishell2
** 
** Made by jauber_e
** Login   <Jaubert Elise@epitech.net>
** 
** Started on  Wed Mar 30 13:55:55 2016 jauber_e
** Last update Fri Apr  8 09:55:29 2016 jauber_e
*/

#include	<unistd.h>
#include	<stdlib.h>
#include	<signal.h>
#include	"my.h"

//http://ithink.ch/blog/2004/08/09/pipes_and_redirections_in_tcsh.html

char		**mysh(char *s, char **env)
{
  char		**com_line;
  int		i;

  com_line = my_str_to_wordtab(s, ';', ';');
  i = 0;
  while (com_line[i] != NULL)
    {
      env = commands(com_line[i], env);
      free(com_line[i]);
      i++;
    }
  free(com_line);
  return (env);
}

char		**prompt_loop(char **env)
{
  char		*s;
  int		i;
  char		*pwd;

  i = search_env(env, "PWD=");
  pwd = env[i] + 4;
  write(STDIN_FILENO, pwd, my_strlen(pwd));
  write(STDIN_FILENO, "$> ", 3);
  signal(SIGTSTP, SIG_IGN);
  signal(SIGINT, SIG_IGN);
  signal(SIGQUIT, SIG_IGN);
  if ((s = get_next_line(0)) != NULL && s[0] != 0)
    env = mysh(s, env);
  else if (s == NULL)
    {
      i = 0;
      while (env[i] != NULL)
	free(env[i++]);
      free(env);
      exit(0);
    }
  free(s);
  return (env);
}

int		main(int ac, char **av, char **ae)
{
  char		**env;
  int		x;

  env = copy_env(ae, env);
  x = 0;
  while (x == 0)
    env = prompt_loop(env);
  return (0);
}
