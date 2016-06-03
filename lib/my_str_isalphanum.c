/*
** my_str_isalphanum.c for alphanum in /home/jaubere/Bureau/projets/PSU_2015_minishell1
** 
** Made by jauber_e
** Login   <Jaubert Elise@epitech.net>
** 
** Started on  Fri Jan 15 19:15:45 2016 jauber_e
** Last update Fri Apr  1 11:33:59 2016 jauber_e
*/

int	alphanum(char *str)
{
  int	i;

  i = 0;
  while (str[i] != 0)
    {
      if (('0' <= str[i] && str[i] <= '9') || (str[i] == '-' && i == 0))
	i++;
      else if (('a' <= str[i] && str[i] <= 'z') ||
	       ('A' <= str[i] && str[i] <= 'Z'))
	i++;
      else if (str[i] == '_')
	i++;
      else
	return (0);
    }
  return (1);
}
