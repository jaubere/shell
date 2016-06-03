/*
** my_str_to_wordtab.c for wordtab in /home/exam/rendu/ex_4
**
** Made by Exam User
** Login   <exam@epitech.net>
**
** Started on  Wed Mar 23 08:47:27 2016 Exam User
** Last update Tue Apr  5 15:06:11 2016 valentin brassart
*/

#include <unistd.h>
#include <stdlib.h>
#include "my_printf.h"

char	**init(t_wordtab *data)
{
  data->i = 0;
  data->tab = malloc(sizeof(char *) * (data->x + 2));
  while (data->i != data->x)
    {
      data->tab[data->i] = my_malloc(data->x + 2);
      data->i += 1;
    }
  data->i = 0;
  data->x = 0;
  data->y = 0;
  return (data->tab);
}

void	condition(char *str, t_wordtab *data, char c, char cc)
{
  if (str[data->i - 1] != c && str[data->i - 1] != cc)
    {
      data->y = 0;
      data->x += 1;
    }
}

char	**my_str_to_wordtab(char *str, char c, char cc)
{
  t_wordtab	data;

  data.x = my_strlen(str);
  if (data.x == 0)
    return (NULL);
  data.tab = init(&data);
  if (str == NULL)
    return (NULL);
  while (str[data.i] == c || str[data.i] == cc)
    data.i++;
  while (str[data.i] != 0)
    {
      data.tab[data.x][data.y] = 0;
      if (str[data.i] != c && str[data.i] != cc)
	{
	  data.tab[data.x][data.y] = str[data.i];
	  data.y++;
	}
      else if (str[data.i] == c || str[data.i] == cc)
	condition(str, &data, c, cc);
      data.i++;
    }
  if (str[data.i - 1] != c && str[data.i - 1] != cc)
    data.x++;
  data.tab[data.x] = NULL;
  return (data.tab);
}
