/*
** commands.c for commands in /home/jaubere/Bureau/projets/PSU_2015_minishell2
**
** Made by jauber_e
** Login   <Jaubert Elise@epitech.net>
**
** Started on  Wed Mar 30 16:05:56 2016 jauber_e
** Last update Thu Apr  7 14:34:23 2016 jauber_e
*/

#include	<stdlib.h>
#include	<unistd.h>
#include	<sys/types.h>
#include	<sys/wait.h>
#include	<dirent.h>
#include	"my.h"

char		**make_path(t_exec *ex, char **env)
{
  int		i;
  int		ok;
  char		*tmp;

  i = 0;
  ok = -1;
  while (env[i] != NULL)
    {
      if (my_strncmp(env[i], "PATH=", 5) == 0)
	ok = i;
      i++;
    }
  if (ok == -1)
    {
      ex->path = NULL;
      env = my_exec(ex, env);
    }
  else
    {
      tmp = env[ok] + 5;
      ex->path = my_str_to_wordtab(tmp, ':', 0);
      env = my_exec(ex, env);
    }
  return (env);
}

int	        check_command(char **command)
{
  int		i;

  i = 0;
  while (command[i] != NULL)
    {
      if (my_strcmp(command[i], "|") == 0)
	return (1);
      if (my_strcmp(command[i], ">") == 0)
	return (2);
      if (my_strcmp(command[i], ">>") == 0)
	return (3);
      if (my_strcmp(command[i], "<") == 0)
	return (4);
      if (my_strcmp(command[i], "<<") == 0)
	return (5);
      i++;
    }
  return (0);
}

char		**commands(char *com, char **env)
{
  t_exec	ex;
  char		*s;
  int		i;

  ex.redir = 0;
  ex.command = my_str_to_wordtab(com, ' ', '\t');
  ex.redir = check_command(ex.command);
  s = ex.command[0];
  if (my_strcmp(s, "exit") == 0)
    {
      i = 0;
      while (env[i] != NULL)
	free(env[i++]);
      free(env);
      my_exit(ex.command);
    }
  else if (my_strcmp(s, "cd") == 0)
    env = my_cd(ex.command, env);
  else if (my_strcmp(s, "env") == 0 ||
	   my_strcmp(s, "setenv") == 0 ||
	   my_strcmp(s, "unsetenv") == 0)
    env = envs(ex.command, env);
  else
    env = make_path(&ex, env);
  return (env);
}
