/*
** epur_str.c for epur_str in /home/exam/rendu/ex_3
** 
** Made by Exam User
** Login   <exam@epitech.net>
** 
** Started on  Mon Apr  4 07:59:19 2016 Exam User
** Last update Mon Apr  4 08:09:38 2016 Exam User
*/

int	epur_str(char *str)
{
  int	i;
  int	tmp;

  i = 0;
  while (str[i] == ' ' || str[i] == '\t')
    i++;
  while (str[i] != 0)
    {
      tmp = 0;
      while (str[i] == ' ' || str[i] == '\t')
	{
	  if (str[i + 1] == 0)
	    return (0);
	  i++;
	  tmp = 1;
	}
      if (tmp == 1)
	my_putchar(' ');
      my_putchar(str[i]);
      i++;
    }
  return (0);
}

int	main(int ac, char **av)
{
  if (ac == 2)
    epur_str(av[1]);
  my_putchar('\n');
  return (0);
}
