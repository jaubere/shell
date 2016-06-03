/*
** search_env.c for search env in /home/jaubere/Bureau/projets/PSU_2015_minishell2
** 
** Made by jauber_e
** Login   <Jaubert Elise@epitech.net>
** 
** Started on  Thu Mar 31 13:43:44 2016 jauber_e
** Last update Mon Apr  4 11:59:31 2016 jauber_e
*/

#include	<stdlib.h>
#include	<unistd.h>
#include	"my.h"

int		search_env(char **env, char *str)
{
  int		i;

  i = 0;
  while (env[i] != 0)
    {
      if (my_strncmp(env[i], str, my_strlen(str)) == 0)
	return (i);
      i++;
    }
  return (-1);
}
