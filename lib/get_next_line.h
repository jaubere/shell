/*
** get_next_line.h for getnextline in /home/jaubere/Bureau/projets/CPE_2015_getnextline
** 
** Made by jauber_e
** Login   <Jaubert Elise@epitech.net>
** 
** Started on  Mon Jan  4 10:07:41 2016 jauber_e
** Last update Tue Apr  5 13:50:35 2016 jauber_e
*/

#ifndef GET_NEXT_LINE_H_
# define GET_NEXT_LINE_H_

#ifndef READ_SIZE
# define READ_SIZE (1)
#endif /* !READ_SIZE */

#include <fcntl.h>
#include <sys/types.h>

typedef struct	s_struc
{
  char		*buf;
  char		*save;
  char		*tmp;
  int		rd;
  int		i;
}		t_s;

char	*get_next_line(const int fd);
char	*my_strdup(char *str);
char	*my_strstrgnl(char *str, char c);

ssize_t read(int fd, void *buf, size_t count);

#endif
