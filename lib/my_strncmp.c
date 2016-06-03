/*
** my_strncmp.c for my_strncmp.c in /home/jauber_e/rendu/exos_simples
**
** Made by Elise Jaubert
** Login   <jauber_e@epitech.net>
**
** Started on  Sat Oct 17 17:31:26 2015 Elise Jaubert
** Last update Sat Oct 17 21:56:53 2015 Elise Jaubert
*/

int	my_strncmp(char *s1, char *s2, int nb)
{
  int	i;

  i = 0;
  while (i != nb)
    {
      if (s1[i] < s2[i])
	return (-1);
      else if (s1[i] > s2[i])
	return (1);
      i++;
    }
  return (0);
}
