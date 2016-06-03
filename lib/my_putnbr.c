/*
** my_putnbr.c for my_putnbr in /home/jauber_e/rendu/exos_simples
**
** Made by Elise Jaubert
** Login   <jauber_e@epitech.net>
**
** Started on  Thu Oct 15 14:53:26 2015 Elise Jaubert
** Last update Wed Mar 30 13:45:35 2016 jauber_e
*/

#include	"my_printf.h"

int		my_putnbr(int nbr)
{
  int	i;

  i = nbr;
  if (nbr < 0)
    {
      my_putchar('-');
      my_putnbr(nbr * (-1));
    }
  else if (nbr > 0)
    {
      i = nbr % 10;
      if (nbr / 10 != 0)
	my_putnbr(nbr / 10);
      my_putchar(i + 48);
    }
  else if (nbr == 0)
    my_putchar('0');
  return (0);
}
