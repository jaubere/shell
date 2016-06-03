/*
** my_put_nbr_base.c for my_put_nbr_base in /home/jaubere/PSU_2015_my_printf
** 
** Made by jauber_e
** Login   <Jaubert Elise@epitech.net>
** 
** Started on  Mon Nov  9 11:37:52 2015 jauber_e
** Last update Wed Mar 30 13:44:54 2016 jauber_e
*/

#include	"my_printf.h"

void		my_put_nbr_base(unsigned int nbr, char *base)
{
  if (nbr > 0)
    {
      if (nbr / my_strlen(base) != 0)
	my_put_nbr_base(nbr / my_strlen(base), base);
      my_putchar(base[nbr % my_strlen(base)]);
    }
  else if (nbr == 0)
    my_putchar(base[0]);
}
