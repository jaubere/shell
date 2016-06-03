/*
** my_malloc.c for my_malloc in /home/jaubere/Bureau/projets/tetris
** 
** Made by jauber_e
** Login   <Jaubert Elise@epitech.net>
** 
** Started on  Tue Feb 23 19:59:38 2016 jauber_e
** Last update Wed Mar 30 14:57:10 2016 jauber_e
*/

#include <stdlib.h>
#include <unistd.h>

char	*my_malloc(int nb)
{
  int	i;
  char	*dest;

  i = 0;
  if ((dest = malloc(sizeof(char) * nb)) == NULL)
    {
      write(2, "Erreur malloc\n", 14);
      exit(0);
    }
  while (i < nb)
    {
      dest[i] = 0;
      i++;
    }
  return (dest);
}
