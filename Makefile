##
## Makefile for Makefile in /home/jaubere/Bureau/projets/PSU_2015_minishell2
##
## Made by jauber_e
## Login   <Jaubert Elise@epitech.net>
##
## Started on  Wed Mar 30 13:07:57 2016 jauber_e
## Last update Tue Apr  5 15:06:44 2016 valentin brassart
##

NAME=		mysh

SRC=		minishell.c \
		copy_env.c \
		commands.c \
		envs.c \
		my_exit.c \
		my_cd.c \
		search_env.c \
		my_setenv.c \
		my_unsetenv.c \
		my_path.c \
		modif_pwd.c \
		my_cd_moins.c \
		my_exec.c \
		special_command.c \

LIB=		-Llib -lmy

all:		$(NAME)

$(NAME):
		gcc -o $(NAME) $(SRC) $(LIB) -g

clean:
		rm -f *~
		rm -f *#

fclean:		clean
		rm -f $(NAME)

re:		fclean all
