/*
** modif_oldpwd.c for modif_oldpwd in /home/jaubere/Bureau/projets/PSU_2015_minishell2
** 
** Made by jauber_e
** Login   <Jaubert Elise@epitech.net>
** 
** Started on  Sat Apr  2 17:40:20 2016 jauber_e
** Last update Wed Apr  6 13:43:30 2016 jauber_e
*/

#include	<stdlib.h>
#include	<unistd.h>
#include	"my.h"

char		**modif_pwd2(char **env, int p, char **tmp, char *oldpwd)
{
  char		*newpwd;
  int		o;
  int		x;

  if (p == -1)
    x = 200;
  else
    x = my_strlen(env[p]) + 7;
  newpwd = my_malloc(x + 50);
  newpwd = getcwd(newpwd, x + 50);
  tmp[2] = my_malloc(my_strlen(oldpwd) + my_strlen(newpwd));
  //o = search_env(env, "PWD=");
  tmp[0] = "setenv";
  tmp[1] = "OLDPWD";
  tmp[2] = oldpwd;
  tmp[3] = NULL;
  env = my_setenv(tmp, env);
  tmp[1] = "PWD";
  tmp[2] = newpwd;
  env = my_setenv(tmp, env);
  return (env);
}

char		**modif_pwd(char **env, char *oldpwd)
{
  int		p;
  char		**tmp;

  if ((tmp = malloc(sizeof(char *) * 4)) == NULL)
    {
      my_puterror("Erreur malloc\n");
      p = 0;
      while (env[p] != NULL)
	free(env[p++]);
      free(env);
      exit(0);
    }
  tmp[0] = my_malloc(7);
  tmp[1] = my_malloc(7);
  p = search_env(env, "OLDPWD=");
  env = modif_pwd2(env, p, tmp, oldpwd);
  return (env);
}
