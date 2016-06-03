/*
** my_putstr.c for my_putstr in /home/jauber_e/rendu/exos_simples
**
** Made by Elise Jaubert
** Login   <jauber_e@epitech.net>
**
** Started on  Thu Oct 15 14:14:06 2015 Elise Jaubert
** Last update Wed Mar 30 17:18:35 2016 jauber_e
*/

#include	<stdlib.h>
#include	<unistd.h>
#include	"my_printf.h"

void		my_putstr(char *str)
{
  write(1, str, my_strlen(str));
}

void		my_puterror(char *str)
{
  write(2, str, my_strlen(str));
}
