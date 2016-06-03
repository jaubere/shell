/*
** my_strncpy.c for my_strncopy in /home/jauber_e/rendu/Piscine_C_J06/ex_03
**
** Made by Elise Jaubert
** Login   <jauber_e@epitech.net>
**
** Started on  Mon Oct  5 13:09:06 2015 Elise Jaubert
** Last update Sat Oct 17 21:10:28 2015 Elise Jaubert
*/

char	*my_strncpy(char *dest, char *src, int n)
{
  int	i;

  i = 0;
  while (n > 0 && src[i] != 0)
    {
      dest[i] = src[i];
      n--;
      i++;
    }
  while (dest[i] != 0)
    {
      dest[i] = '\0';
      i++;
    }
  dest[i] = '\0';
  if (n <= 0)
    *dest = 0;
  return (dest);
}
