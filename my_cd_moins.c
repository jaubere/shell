/*
** my_cd_moins.c for my_cd_moins in /home/jaubere/Bureau/projets/PSU_2015_minishell2
** 
** Made by jauber_e
** Login   <Jaubert Elise@epitech.net>
** 
** Started on  Sat Apr  2 17:37:14 2016 jauber_e
** Last update Mon Apr  4 08:59:08 2016 jauber_e
*/

#include	<stdlib.h>
#include	<unistd.h>
#include	"my.h"

char		**my_cd_moins(char **command, char **env)
{
  char		*s;
  int		ok;

  s = my_malloc(100);
  s = getcwd(s, 100);
  if ((ok = search_env(env, "OLDPWD=")) == -1)
    my_puterror("OLDPWD non défini\n");
  else
    {
      if (chdir(env[ok] + 7) == -1)
	my_puterror("cd : Erreur\n");
      env = modif_pwd(env, s);
    }
  return (env);
}
