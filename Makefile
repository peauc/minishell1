##
## Makefile for make in /home/peau_c/rendu/PSU/minishell/PSU_2015_minishell1
##
## Made by Clement Peau
## Login   <peau_c@epitech.net>
##
## Started on  Thu Jan  7 16:17:02 2016 Clement Peau
## Last update Sun Jan 24 23:04:37 2016 Clement Peau
##

SRC=	src/main.c \
	src/get_env.c \
	src/strlen.c \
	src/my_strcpy.c \
	src/strcmp.c \
	src/epur.c \
	src/str_wordtab.c \
	src/minishell.c \
	src/get_path.c \
	src/seek_env.c \
	src/fork.c \
	src/change_path.c \
	src/my_strcat.c \
	src/show_tab.c \
	src/setenv.c \
	src/unsetenv.c \
	src/cd.c \
	src/env.c \
	src/exit.c \
	src/builtin.c \
	src/arrlen.c \
	src/my_getnbr.c \
	src/free.c \

OBJ=	$(SRC:.c=.o)

RM=	rm -f

CC=	@ gcc

NAME=	mysh

CFLAGS=	-Wall -W -Wextra -I ./inc/ -pedantic

$(NAME):	$(OBJ)
		@ gcc -o $(NAME) $(OBJ)
		@ echo "$(NAME) compiled sucessfully"

all:		$(NAME)

clean:
	@ $(RM) $(OBJ)
	@ echo "clean sucessfull"
fclean: clean
	@ $(RM) $(NAME)
	@ echo "fclean succesfull"

re:	fclean all
