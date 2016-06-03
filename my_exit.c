/*
** my_exit.c for my_exit in /home/jaubere/Bureau/projets/PSU_2015_minishell2
** 
** Made by jauber_e
** Login   <Jaubert Elise@epitech.net>
** 
** Started on  Wed Mar 30 16:58:28 2016 jauber_e
** Last update Mon Apr  4 08:59:35 2016 jauber_e
*/

#include	<stdlib.h>
#include	<unistd.h>
#include	"my.h"

void		my_exit(char **s)
{
  int		i;

  i = 0;
  if (s[1] ==  NULL)
    exit(0);
  else if (s[2] == NULL)
    {
      if (my_str_isnum(s[1]) == 1)
	exit(i = (unsigned char)my_getnbr(s[1]));
      else
	my_puterror("Erreur exit\n");
    }
  else
    my_puterror("Erreur exit\n");
}
