/*
** special_command.c for special command in /home/jaubere/Bureau/projets/PSU_2015_minishell2
**
** Made by jauber_e
** Login   <Jaubert Elise@epitech.net>
**
** Started on  Mon Apr  4 16:44:20 2016 jauber_e
** Last update Wed Apr  6 15:44:14 2016 jauber_e
*/

#include        <unistd.h>
#include        <stdlib.h>
#include        "my.h"

char		**exec_pipe1(char **com1, char **com2, char **path, char **env)
{
  int		pipefd[2];
  pid_t		pid;
  pid_t		pid2;
  int		status;

  if (com1[0] == NULL)
    return (env);
  
  return (env);
}

char		**exec_pipe(char **com1, char **com2, char **env)
{
  int           i;
  int           ok;
  char          *tmp;
  char          **path;

  i = 0;
  ok = -1;
  while (env[i] != NULL)
    {
      if (my_strncmp(env[i], "PATH=", 5) == 0)
	ok = i;
      i++;
    }
  if (ok == -1)
    env = exec_pipe1(com1, com2, NULL, env);
  else
    {
      tmp = env[ok] + 5;
      path = my_str_to_wordtab(tmp, ':', 0);
      env = exec_pipe1(com1, com2, path, env);
    }
  return (env);
}

char		**pipe1(char **command, char **env)
{
  int		i;
  int		j;
  char		**com1;
  char		**com2;

  i = 0;
  j = 0;
  while (command[i] != NULL)
    i++;
  if ((com1 = malloc(sizeof(char *) * (i + 1))) == NULL)
    return (NULL);
  if ((com2 = malloc(sizeof(char *) * (i + 1))) == NULL)
    return (NULL);
  i = 0;
  while (my_strcmp(command[i], "|") != 0)
    {
      com1[j] = my_malloc(my_strlen(command[i]));
      com1[j] = command[i];
      j++;
      i++;
    }
  com1[j] = NULL;
  //my_printf("com1 : %s %s\n", com1[0], com1[1]);
  i++;
  j = 0;
  while (command[i] != NULL)
    {
      com2[j] = my_malloc(my_strlen(command[i]));
      com2[j] = command[i];
      j++;
      i++;
    }
  com2[j] = NULL;
  //my_printf("com2 : %s %s\n", com2[0], com2[1]);
  env = exec_pipe(com1, com2, env);
  return (env);
}

char		**pipe_command(char **command, char **env)
{
  int		i;
  int		j;

  i = 0;
  j = 0;
  while (command[i] != NULL)
    {
      if (my_strcmp(command[i], "|") == 0)
	j++;
      i++;
    }
  if (j == 1)
    env = pipe1(command, env);
  return (env);
}
