/*
** my_putchar.c for my_putchar in /home/jauber_e/rendu/Piscine_C_J07/lib/my
** 
** Made by Elise Jaubert
** Login   <jauber_e@epitech.net>
** 
** Started on  Tue Oct  6 10:38:58 2015 Elise Jaubert
** Last update Sat Nov 14 15:31:56 2015 jauber_e
*/

#include	<unistd.h>

void		my_putchar(char c)
{
  write(1, &c, 1);
}
