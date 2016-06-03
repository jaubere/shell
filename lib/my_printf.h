/*
** my_printf.h for my_printf in /home/jaubere/Bureau/projets/PSU_2015_minishell2/lib
** 
** Made by jauber_e
** Login   <Jaubert Elise@epitech.net>
** 
** Started on  Wed Mar 30 13:33:46 2016 jauber_e
** Last update Fri Apr  1 17:12:19 2016 jauber_e
*/

#ifndef MY_PRINTF_
# define MY_PRINTF_

typedef struct	s_wordtab
{
  char		**tab;
  int		i;
  int		x;
  int		y;
}		t_wordtab;

int	my_getnbr(char *nbr);
void	my_put_nbr_base(unsigned int nbr, char *base);
void	my_put_nbr_base_uli(unsigned long int nbr, char *base);
int	my_strlen(char *str);
void	my_putstr(char *str);
void	my_puterror(char *str);
int	my_putnbr(int nb);
void	my_putchar(char c);
void	my_swap(char *a, char *b);
void	my_revstr(char *str);
char	*my_malloc(int nb);
char	*my_strstrgnl(char *str, char c);
char	*my_strstr(char *str, char *to_find);
int	alphanum(char *str);
char	*my_strcpy(char *dest, char *src);

#endif
