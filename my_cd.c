/*
** my_cd.c for my_cd in /home/jaubere/Bureau/projets/PSU_2015_minishell2
** 
** Made by jauber_e
** Login   <Jaubert Elise@epitech.net>
** 
** Started on  Wed Mar 30 20:51:39 2016 jauber_e
** Last update Mon Apr  4 08:58:46 2016 jauber_e
*/

#include	<stdlib.h>
#include	<unistd.h>
#include	<dirent.h>
#include	<sys/types.h>
#include	"my.h"

char		**my_cd_way(char **command, char **env)
{
  char		*s;

  s = my_malloc(100);
  s = getcwd(s, 100);
  if (access(command[1], X_OK) == 0)
    {
      if (chdir(command[1]) == -1)
	my_puterror("cd : Erreur\n");
      env = modif_pwd(env, s);
    }
  else
    my_puterror("Dossier introuvable\n");
  return (env);
}

char		**my_cd_home(char *home, char **env)
{
  char		*s;

  s = my_malloc(100);
  s = getcwd(s, 100);
  if (chdir(home) == -1)
    my_puterror("cd : Erreur\n");
  env = modif_pwd(env, s);
  return (env);
}

char		**my_cd_search(char **command, char **env, char *home)
{
  if (command[1] == NULL)
    env = my_cd_home(home, env);
  else if (command[2] == NULL)
    {
      if (my_strcmp(command[1], "~") == 0)
	env = my_cd_home(home, env);
      else if (my_strcmp(command[1], "-") == 0)
	env = my_cd_moins(command, env);
      else
	env = my_cd_way(command, env);
    }
  else
    my_puterror("cd : Trop d'aguments\n");
  return (env);
}

char		**my_cd(char **command, char **env)
{
  int		i;
  char		*home;

  i = search_env(env, "HOME=");
  home = env[i] + 5;
  env = my_cd_search(command, env, home);
  return (env);
}
