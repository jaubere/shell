/*
** my_put_nbr_base_uli.c for base_uli in /home/jaubere/PSU_2015_my_printf
** 
** Made by jauber_e
** Login   <Jaubert Elise@epitech.net>
** 
** Started on  Thu Nov 12 15:41:11 2015 jauber_e
** Last update Wed Mar 30 13:45:03 2016 jauber_e
*/

#include        "my_printf.h"

void		my_put_nbr_base_uli(unsigned long int nbr, char *base)
{
  if (nbr > 0)
    {
      if (nbr / my_strlen(base) != 0)
	my_put_nbr_base_uli(nbr / my_strlen(base), base);
      my_putchar(base[nbr % my_strlen(base)]);
    }
  else if (nbr == 0)
    my_putchar(base[0]);
}

