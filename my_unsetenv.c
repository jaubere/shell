/*
** my_unsetenv.c for my_unsetenv in /home/jaubere/Bureau/projets/PSU_2015_minishell2
** 
** Made by jauber_e
** Login   <Jaubert Elise@epitech.net>
** 
** Started on  Fri Apr  1 09:48:03 2016 jauber_e
** Last update Mon Apr  4 11:59:15 2016 jauber_e
*/

#include	<stdlib.h>
#include	<unistd.h>
#include	"my.h"

char		**del_line(char *name, char **env)
{
  int		i;

  name = my_strcat(name, "=");
  i = search_env(env, name);
  if (i != -1)
    while (env[i] != NULL)
      {
	env[i] = env[i + 1];
	i++;
      }
  return (env);
}

char		**my_unsetenv(char **command, char **env)
{
  int		i;

  i = 1;
  if (command[1] == NULL)
    my_puterror("unsetenv : Pas assez d'arguments\n");
  else
    while (command[i] != NULL)
      {
	if (alphanum(command[i]) == 1)
	  env = del_line(command[i], env);
	i++;
      }
  return (env);
}

