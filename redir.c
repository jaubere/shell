/*
** redir.c for redir in /home/jaubere/Bureau/PSU_2015_minishell2
** 
** Made by jauber_e
** Login   <Jaubert Elise@epitech.net>
** 
** Started on  Thu Apr  7 14:37:11 2016 jauber_e
** Last update Thu Apr  7 14:56:59 2016 jauber_e
*/

#include        <stdlib.h>
#include        <unistd.h>
#include        <sys/stat.h>
#include        <fcntl.h>
#include        <dirent.h>
#include        <sys/types.h>
#include        <sys/wait.h>

int	main()
{
  char	*buf;

  buf = malloc(11);
  read(0, buf, 10);
  printf("buf = %s\n", buf);
}
