/*
** my_revstr.c for my_revstr in /home/jauber_e/rendu/exos_simples
**
** Made by Elise Jaubert
** Login   <jauber_e@epitech.net>
**
** Started on  Thu Oct 15 14:17:07 2015 Elise Jaubert
** Last update Wed Mar 30 13:50:35 2016 jauber_e
*/

#include "my_printf.h"

void	my_revstr(char *str)
{
  int	i;
  int	j;

  i = 0;
  j = my_strlen(str) - 1;
  while (i < j)
    {
      my_swap(&str[i], &str[j]);
      i++;
      j--;
    }
}
