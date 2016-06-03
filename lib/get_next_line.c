/*
** get_next_line.c for gnl in /home/jaubere/Bureau/projets/CPE_2015_getnextline
** 
** Made by jauber_e
** Login   <Jaubert Elise@epitech.net>
** 
** Started on  Wed Mar  2 11:08:50 2016 jauber_e
** Last update Fri Apr  1 21:59:55 2016 jauber_e
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include "get_next_line.h"
#include "my_printf.h"

char		*my_strcatgnl(char *dest, char *src)
{
  char		*tmp;
  int		i;
  int		j;

  i = 0;
  j = 0;
  tmp = my_malloc(10000);
  tmp[0] = 0;
  while (dest[i] != 0)
    {
      tmp[i] = dest[i];
      i++;
    }
  while (src[j] != 0)
    {
      tmp[i + j] = src[j];
      j++;
    }
  tmp[i + j] = 0;
  free(dest);
  return (tmp);
}

char	*return_save(t_s *gnl, char **recup, char c)
{
  *recup = my_strdup(gnl->tmp);
  gnl->i = 0;
  while (gnl->save[gnl->i] != c)
    gnl->i++;
  (*recup)++;
  gnl->save[gnl->i] = 0;
  return (gnl->save);
}

void	loop(t_s *gnl, int *x)
{
  *x = 1;
  gnl->i = 0;
  while (gnl->save[gnl->i] != '\n' && gnl->save[gnl->i] != 0)
    gnl->i++;
  gnl->rd = 1;
}

void	ini_data(t_s *gnl, char *recup, int x)
{
  if (x == 0)
    {
      recup = my_malloc(5000);
      recup[0] = 0;
    }
  gnl->tmp = my_malloc(5000);
  gnl->buf = my_malloc(READ_SIZE + 2);
  gnl->save = my_malloc(50000);
  gnl->save[0] = 0;
  gnl->save = my_strcatgnl(gnl->save, recup);
}

char	*get_next_line(const int fd)
{
  t_s		gnl;
  static char	*recup;
  static int	x = 0;

  ini_data(&gnl, recup, x);
  while (x != 2)
    {
      loop(&gnl, &x);
      if (x == 1 && gnl.save[gnl.i] == 0)
	{
	  gnl.rd = read(fd, gnl.buf, READ_SIZE);
	  gnl.buf[gnl.rd] = 0;
	  (gnl.rd == 0) ? (x = 2) : (x = x);
	  if (gnl.rd == -1)
	    return (NULL);
	  gnl.save = my_strcatgnl(gnl.save, gnl.buf);
	}
      if (x == 2)
	return (NULL);
      if ((gnl.tmp = my_strstrgnl(gnl.save, '\n')) != NULL)
	return (return_save(&gnl, &recup, '\n'));
    }
  return (return_save(&gnl, &recup, 0));
}
