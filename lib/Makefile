##
## Makefile for Makefile in /home/jauber_e/Piscine_C_workshoplib
## 
## Made by Elise Jaubert
## Login   <jauber_e@epitech.net>
## 
## Started on  Sun Oct 18 19:22:46 2015 Elise Jaubert
## Last update Fri Apr  1 17:22:42 2016 jauber_e
##

NAME=			libmy.a

SRC=			get_next_line.c \
			my_getnbr.c \
			my_malloc.c \
			my_printf.c \
			my_putchar.c \
			my_put_nbr_base.c \
			my_put_nbr_base_uli.c \
			my_putnbr.c \
			my_putstr.c \
			my_revstr.c \
			my_strcat.c \
			my_strcmp.c \
			my_strcpy.c \
			my_str_isnum.c \
			my_strlen.c \
			my_strncmp.c \
			my_strncmp2.c \
			my_strstr.c \
			my_strstrdupgnl.c \
			wordtab.c \
			my_swap.c \
			my_strncpy.c \
			my_str_isalphanum.c

OBJ=			$(SRC:.c=.o)

all:			$(NAME)

$(NAME):		$(OBJ)
			ar rc $(NAME) $(OBJ)
			ranlib $(NAME)
			rm -f $(OBJ)

clean:
			rm -f *~
			rm -f *#

fclean:			clean
			rm -f $(NAME)

re:			fclean all
