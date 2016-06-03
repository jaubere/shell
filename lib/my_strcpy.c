/*
** my_strcpy.c for my_strcpy in /home/jauber_e/rendu/Piscine_C_J06
**
** Made by Elise Jaubert
** Login   <jauber_e@epitech.net>
**
** Started on  Mon Oct  5 10:21:31 2015 Elise Jaubert
** Last update Sat Mar 19 15:37:59 2016 Louis Henry
*/

#include	<stdlib.h>
#include	<unistd.h>

char		*my_strcpy(char *dest, char *src)
{
  int		i;

  i = 0;
  while (src[i] != '\0')
    {
      dest[i] = src[i];
      i++;
    }
  dest[i] = '\0';
  return (dest);
}

char		*my_strcpy2(char *dest, char *src)
{
  dest = src;
  return (dest);
}

char		*my_strcpy3(char *dest, char *src)
{
  char		*tmp;
  int		i;
  int		a;

  a = 0;
  i = 0;
  if ((tmp = (malloc(sizeof(char *) * 3))) == NULL)
    exit (-1);
  dest = src;
  while (dest[i] != '=')
    i++;
  i++;
  while (dest[i])
    {
      tmp[a] = dest[i];
      i++;
      a++;
    }
  tmp[a] = 0;
  return (tmp);
}
