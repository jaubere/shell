/*
** my_swap.c for my_swap in /home/jauber_e/rendu/Piscine_C_J04
**
** Made by Elise Jaubert
** Login   <jauber_e@epitech.net>
**
** Started on  Thu Oct  1 11:47:44 2015 Elise Jaubert
** Last update Wed Mar 30 13:48:45 2016 jauber_e
*/

void	my_swap(char *a, char *b)
{
  int	c;

  c = *a;
  *a = *b;
  *b = c;
}
