/*
** envs.c for envs in /home/jaubere/Bureau/projets/PSU_2015_minishell2
** 
** Made by jauber_e
** Login   <Jaubert Elise@epitech.net>
** 
** Started on  Wed Mar 30 16:47:27 2016 jauber_e
** Last update Mon Apr  4 08:56:11 2016 jauber_e
*/

#include	<stdlib.h>
#include	<unistd.h>
#include	"my.h"

void		print_env(char **env)
{
  int		i;

  i = 0;
  while (env[i] != NULL)
    {
      my_printf("%s\n", env[i]);
      i++;
    }
}

char	**envs(char **command, char **env)
{
  char	*s;

  s = command[0];
  if (my_strcmp(s, "env") == 0)
    print_env(env);
  else if (my_strcmp(s, "setenv") == 0)
    env = my_setenv(command, env);
  else if (my_strcmp(s, "unsetenv") == 0)
    env = my_unsetenv(command, env);
  return (env);
}
