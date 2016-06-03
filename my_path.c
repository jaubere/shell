/*
** currentdir_path.c for currentdir_path in /home/jaubere/Bureau/projets/PSU_2015_minishell2
**
** Made by jauber_e
** Login   <Jaubert Elise@epitech.net>
**
** Started on  Fri Apr  1 18:49:00 2016 jauber_e
** Last update Fri Apr  8 10:30:44 2016 jauber_e
*/

#include	<stdlib.h>
#include	<unistd.h>
#include	<sys/stat.h>
#include	<fcntl.h>
#include	<dirent.h>
#include	<sys/types.h>
#include	<sys/wait.h>
#include	"my.h"

char		**exec_path2(t_exec *ex, char **env, int *ok)
{
  pid_t		pid;
  int		status;
  int		fd;

  if (access(ex->command[0], X_OK) == 0)
    {
      if ((pid = fork()) == 0)
	{
	  if (ex->redir == 2)
	    {
	      fd = open(ex->file, O_RDWR | O_CREAT | O_TRUNC, S_IRWXU);
	      close(1);
	      dup2(fd, 1);
	    }
	  else if (ex->redir == 3)
	    {
	      fd = open(ex->file, O_RDWR | O_APPEND | O_CREAT, S_IRWXU);
	      close(1);
	      dup2(fd, 1);
	    }
	  else if (ex->redir == 4)
	    {
	      fd = open(ex->file, O_RDWR | O_APPEND | O_CREAT, S_IRWXU);
	      close(0);
	      dup2(fd, 0);
	    }
	  signal(SIGINT, SIG_DFL);
	  execve(ex->command[0], ex->command, env);
	}
      else
	{
	  *ok = 1;
	  segfault(pid);
	}
    }
  return (env);
}

char		**exec_path(t_exec *ex, char **env)
{
  int		i;
  char		*tmp;
  char		*com;
  int		ok;

  i = 0;
  ok = 0;
  com = ex->command[0];
  if (com == NULL)
    return (env);
  if (ex->path == NULL)
    my_puterror("PATH inexistant ou commande introuvable\n");
  else
    {
      while (ex->path[i] != NULL)
	{
	  ex->command[0] = com;
	  tmp = ex->path[i];
	  tmp = my_strcat(tmp, "/");
	  tmp = my_strcat(tmp, ex->command[0]);
	  ex->command[0] = tmp;
	  if (access(ex->command[0], X_OK) == 0)
	    env = exec_path2(ex, env, &ok);
	  i++;
	}
      if (ok == 0)
	my_puterror("PATH inexistant ou commande introuvable\n");
    }
  return (env);
}
