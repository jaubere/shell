/*
** my_strlen.c for my_strlen in /home/jauber_e/rendu/Piscine_C_J04
**
** Made by Elise Jaubert
** Login   <jauber_e@epitech.net>
**
** Started on  Thu Oct  1 20:03:23 2015 Elise Jaubert
** Last update Mon Apr  4 13:39:12 2016 jauber_e
*/

#include	<stdlib.h>

int		my_strlen(char *str)
{
  int		i;

  i = 0;
  if (str == NULL)
    return (0);
  while (str[i] != 0)
    i++;
  return (i);
}
