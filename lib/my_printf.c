/*
** my_printf.c for my_printf in /home/jaubere/PSU_2015_my_printf
** 
** Made by jauber_e
** Login   <Jaubert Elise@epitech.net>
** 
** Started on  Fri Nov  6 10:03:43 2015 jauber_e
** Last update Wed Mar 30 13:33:30 2016 jauber_e
*/

#include	<stdarg.h>
#include	"my_printf.h"

int		print_s(char *str, int i, va_list va)
{
  int		b;
  char		*var;

  b = 0;
  str = str;
  i = i;
  var = va_arg(va, char *);
  while (var[b] != 0)
    {
      if (var[b] <= 32 || var[b] == 127)
	{
	  if (1 <= var[b] && var[b] <= 7)
	    my_putstr("\\00");
	  else if (8 <= var[b] && var[b] <= 32)
	    my_putstr("\\0");
	  else if (var[b] == 127)
	    my_putchar('\\');
	  my_put_nbr_base(var[b], "01234567");
	}
      else
	my_putchar(var[b]);
      b++;
    }
  return (0);
}

int		print_base(char *str, int i, va_list va)
{
  if (str[i + 1] == 'p')
    {
      my_putstr("0x");
      my_put_nbr_base_uli(va_arg(va, unsigned long int), "0123456789abcdef");
    }
  else if (str[i + 1] == 'u')
    my_put_nbr_base(va_arg(va, unsigned int), "0123456789");
  else if (str[i + 1] == 'o')
    my_put_nbr_base(va_arg(va, unsigned int), "01234567");
  else if (str[i + 1] == 'x')
    my_put_nbr_base(va_arg(va, unsigned int), "0123456789abcdef");
  else if (str[i + 1] == 'X')
    my_put_nbr_base(va_arg(va, unsigned int), "0123456789ABCDEF");
  else if (str[i + 1] == 'b')
    my_put_nbr_base(va_arg(va, int), "01");
  return (i);
}

int		print_params(char *str, int i, va_list va)
{
  if (str[i + 1] == 'd' || str[i + 1] == 'i')
    my_putnbr(va_arg(va, int));
  else if (str[i + 1] == 's')
    my_putstr(va_arg(va, char *));
  else if (str[i + 1] == 'c')
    my_putchar(va_arg(va, int));
  else if (str[i + 1] == 'S')
    print_s(str, i, va);
  else if (str[i + 1] == '%')
    my_putchar('%');
  else if (str[i + 1] == 'o' || str[i + 1] == 'u' || str[i + 1] == 'p')
    i = print_base(str, i, va);
  else if (str[i + 1] == 'x' || str[i + 1] == 'X' || str[i + 1] == 'b')
    i = print_base(str, i, va);
  return (0);
}

int		my_printf(char *str, ...)
{
  va_list	va;
  int		i;

  i = 0;
  va_start(va, str);
  while (str[i] != 0)
    {
      if (str[i] != '%')
	my_putchar(str[i]);
      else
	{
	  print_params(str, i, va);
	  i++;
	}
      i++;
    }
  va_end(va);
  return (0);
}
