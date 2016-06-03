/*
** my_exec.c for my_exec in /home/jaubere/Bureau/projets/PSU_2015_minishell2
** 
** Made by jauber_e
** Login   <Jaubert Elise@epitech.net>
** 
** Started on  Sun Apr  3 14:32:37 2016 jauber_e
** Last update Fri Apr  8 10:31:01 2016 jauber_e
*/

#include	<stdlib.h>
#include	<unistd.h>
#include	<sys/stat.h>
#include	<fcntl.h>
#include	<sys/types.h>
#include	<sys/wait.h>
#include	<dirent.h>
#include	"my.h"

void		segfault(pid_t pid)
{
  int		status;

  waitpid(pid, &status, 0);
  if ((WTERMSIG(status)) == 11)
    {
      my_puterror("Segfault\n");
      exit (139);
    }
}

char		**my_exec(t_exec *ex, char **env)
{
  pid_t		pid;
  int		status;
  int		fd;

  if (ex->command[0] == NULL)
    return (env);
  fd = 0;
  while (ex->command[fd] != NULL && my_strncmp(ex->command[fd], ">", 1) != 0 &&
	 my_strncmp(ex->command[fd], "<", 1) != 0)
    fd++;
  ex->file = my_malloc(1);
  ex->file[0] == 0;
  if (ex->redir != 0)
    {
      ex->file = ex->command[fd + 1];
      while (ex->command[fd + 2] != NULL)
	{
	  ex->command[fd] = ex->command[fd + 2];
	  fd++;
	}
      ex->command[fd] = NULL;
     }
  if (ex->file == NULL || ex->command[0] == NULL)
    my_puterror("Erreur redirection\n");
  else
    {
      if (ex->command[0][0] == '/' || ex->command[0][0] == '.')
	{
	  if (access(ex->command[0], X_OK) == 0)
	    {
	      if ((pid = fork()) == 0)
		{
		  if (ex->redir == 2)
		    {
		      fd = open(ex->file, O_WRONLY | O_CREAT | O_TRUNC, S_IRWXU);
		      close(1);
		      dup2(fd, 1);
		    }
		  else if (ex->redir == 3)
		    {
		      fd = open(ex->file, O_WRONLY | O_APPEND | O_CREAT, S_IRWXU);
		      close(1);
		      dup2(fd, 1);
		    }
		  else if (ex->redir == 4)
		    {
		      fd = open(ex->file, O_WRONLY | O_APPEND | O_CREAT, S_IRWXU);
		      close(0);
		      dup2(fd, 0);
		    }
		  signal(SIGINT, SIG_DFL);
		  execve(ex->command[0], ex->command, env);
		  exit(0);
		}
	      else
		segfault(pid);
	      return (env);
	    }
	  else
	    my_puterror("PATH inexistant ou commande introuvable\n");
	}
      else
	env = exec_path(ex, env);
    }
  return (env);
}
  
