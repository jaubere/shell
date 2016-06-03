/*
** my_strncmp.c for my_strncmp.c in /home/jauber_e/rendu/exos_simples
**
** Made by Elise Jaubert
** Login   <jauber_e@epitech.net>
**
** Started on  Sat Oct 17 17:31:26 2015 Elise Jaubert
** Last update Wed Mar 30 13:50:54 2016 jauber_e
*/

#include <stdlib.h>
#include "my_printf.h"

int	my_strncmp2(char *s1, char *s2, int nb)
{
  int	i;
  int	j;
  int	x;

  x = 0;
  i = my_strlen(s1) - 1;
  j = my_strlen(s2) - 1;
  while (x != nb)
    {
      if (s1[i] != s2[j])
	return (1);
      i--;
      j--;
      x++;
    }
  return (0);
}
