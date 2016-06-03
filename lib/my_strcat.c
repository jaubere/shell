/*
** my_strcat.c for my_strcpy in /home/jauber_e/rendu/Piscine_C_J07/ex_02
** 
** Made by Elise Jaubert
** Login   <jauber_e@epitech.net>
** 
** Started on  Tue Oct  6 15:14:12 2015 Elise Jaubert
** Last update Fri Apr  1 11:31:41 2016 jauber_e
*/

#include <stdlib.h>
#include "my_printf.h"

char	*my_strcat(char *dest, char *src)
{
  char	*tmp;
  int	i;
  int	j;

  i = 0;
  j = 0;
  tmp = my_malloc(my_strlen(dest) + my_strlen(src) + 3);
  while (dest[i] != 0)
    {
      tmp[i] = dest[i];
      i++;
    }
  tmp[i] = 0;
  while (src[j] != 0)
    {
      tmp[j + i] = src[j];
      j++;
    }
  tmp[i + j] = 0;
  return (tmp);
}
