/*
** my_getnbr.c for my_getnbr in /home/jauber_e/rendu/exos_simples
**
** Made by Elise Jaubert
** Login   <jauber_e@epitech.net>
**
** Started on  Thu Oct 15 15:48:02 2015 Elise Jaubert
** Last update Fri Feb 26 18:04:43 2016 jauber_e
*/

int	my_getnbr(char *nbr)
{
  int	i;
  int	x;
  int	n;

  i = 0;
  x = 0;
  n = 0;
  while (nbr[i] != '\0')
    {
      if ('0' <= nbr[i] && nbr[i] <= '9')
	{
	  if (i != 0)
	    if (nbr[i - 1] == '-')
	      n = 1;
	  x = x * 10 + (nbr[i] - 48);
	  if (nbr[i + 1] < '0' || nbr[i + 1] > '9')
	    {
	      if (n == 1)
		x = -x;
	      return (x);
	    }
	}
      i++;
    }
  return (0);
}
