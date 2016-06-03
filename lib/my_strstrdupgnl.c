/*
** my_strstr.c for my_strstr in /home/jauber_e/rendu/exos_simples
**
** Made by Elise Jaubert
** Login   <jauber_e@epitech.net>
**
** Started on  Sun Oct 18 14:15:24 2015 Elise Jaubert
** Last update Fri Apr  1 11:38:05 2016 jauber_e
*/

#include <stdlib.h>
#include "my_printf.h"

char	*my_strdup(char *str)
{
  char	*newstr;
  int	i;

  i = 0;
  while (str[i] != 0)
    i++;
  if ((newstr = my_malloc(i + 1)) == NULL)
    return (NULL);
  i = 0;
  while (str[i] != 0)
    {
      newstr[i] = str[i];
      i++;
    }
  newstr[i] = 0;
  return (newstr);
}

char	*my_strstrgnl(char *str, char c)
{
  int	i;
  char	*newstr;

  i = 0;
  while (str[i] != 0)
    i++;
  i = 0;
  newstr = my_strdup(str);
  while (str[i] != 0)
    {
      if (str[i] == c)
	{
	  newstr[i] = 0;
	  newstr = str + i;
	  return (newstr);
	}
      i++;
    }
  return (NULL);
}
