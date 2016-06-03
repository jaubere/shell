/*
** my_strcmp.c for my_strcmp in /home/jauber_e/rendu/exos_simples
**
** Made by Elise Jaubert
** Login   <jauber_e@epitech.net>
**
** Started on  Sat Oct 17 16:21:05 2015 Elise Jaubert
** Last update Wed Mar 30 13:47:54 2016 jauber_e
*/

#include	"my_printf.h"

int		my_strcmp(char *s1, char *s2)
{
  int		i;

  i = 0;
  if (my_strlen(s1) == my_strlen(s2))
    {
      while (s1[i] != 0)
	{
	  if (s1[i] < s2[i])
	    return (-1);
	  else if (s1[i] > s2[i])
	    return (1);
	  i++;
	}
      return (0);
    }
  else if (my_strlen(s1) < my_strlen(s2))
    return (-1);
  else if (my_strlen(s1) > my_strlen(s2))
    return (1);
  return (0);
}
