/*
** copy_env.c for copy env in /home/jaubere/Bureau/projets/PSU_2015_minishell2
** 
** Made by jauber_e
** Login   <Jaubert Elise@epitech.net>
** 
** Started on  Wed Mar 30 15:26:17 2016 jauber_e
** Last update Mon Apr  4 08:55:45 2016 jauber_e
*/

#include	<unistd.h>
#include	<stdlib.h>
#include	"my.h"

char		**copy_env(char **ae, char **env)
{
  int		i;
  int		j;

  i = 0;
  while (ae[i] != NULL)
    i++;
  if ((env = malloc(sizeof(char *) * (i + 1))) == NULL)
    my_puterror("Erreur malloc\n");
  j = 0;
  while (j < i)
    {
      env[j] = my_malloc(my_strlen(ae[j]) + 1);
      j++;
    }
  i = 0;
  while (ae[i] != NULL)
    {
      env[i] = my_strcpy(env[i], ae[i]);
      i++;
    }
  env[i] = NULL;
  return (env);
}
