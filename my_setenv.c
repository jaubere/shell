/*
** my_setenv.c for my_setenv in /home/jaubere/Bureau/projets/PSU_2015_minishell2
** 
** Made by jauber_e
** Login   <Jaubert Elise@epitech.net>
** 
** Started on  Thu Mar 31 13:37:33 2016 jauber_e
** Last update Mon Apr  4 09:01:09 2016 jauber_e
*/

#include	<stdlib.h>
#include	<unistd.h>
#include	"my.h"

char		**create_env2(char **command, char **env, char **newenv)
{
  int		i;

  i = 0;
  while (env[i] != NULL)
    {
      newenv[i] = env[i];
      i++;
    }
  newenv[i] = command[1];
  newenv[i] = my_strcat(newenv[i], "=");
  if (command[2] != NULL)
    newenv[i] = my_strcat(newenv[i], command[2]);
  newenv[i + 1] = NULL;
  return (newenv);
}

char		**create_env(char **command, char **env)
{
  int		i;
  int		j;
  char		**newenv;

  i = 0;
  while (env[i] != NULL)
    i++;
  if ((newenv = malloc(sizeof(char *) * (i + 2))) == NULL)
    my_puterror("Erreur malloc\n");
  newenv[0] = NULL;
  j = 0;
  while (j < i)
    {
      newenv[j] = my_malloc(my_strlen(env[j]) + 1);
      j++;
    }
  if (command[2] == NULL)
    newenv[j] = my_malloc(my_strlen(command[1] + 2));
  else if (command[3] == NULL)
    newenv[j] = my_malloc(my_strlen(command[1] + my_strlen(command[2] + 1)));
  newenv = create_env2(command, env, newenv);
  return (newenv);
}

char		**my_setenv2(char **command, char **env, int i)
{
  int		x;
  int		j;
  char		*s;

  s = command[1];
  s = my_strcat(s, "=");
  i = search_env(env, s);
  if (i == -1)
    env = create_env(command, env);
  else
    {
      x = my_strlen(command[1]) + 1;
      env[i][x] = 0;
      if (command[2] != NULL)
	env[i] = my_strcat(env[i], command[2]);
    }
  return (env);
}

char		**my_setenv(char **command, char **env)
{
  int		i;

  i = 0;
  if (command[1] == NULL)
    print_env(env);
  else if (command[2] == NULL || command[3] == NULL)
    {
      if (alphanum(command[1]) == 0)
	my_puterror("setenv : Argument invalide\n");
      else
	env = my_setenv2(command, env, i);
    }
  else
    my_puterror("setenv : Trop d'arguments\n");
  return (env);
}
