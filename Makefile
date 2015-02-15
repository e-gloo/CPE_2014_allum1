##
## Makefile for Makefile in /home/coodie_d/rendu/C_Prog/B2/Allum1
## 
## Made by Dylan Coodien
## Login   <coodie_d@epitech.net>
## 
## Started on  Fri Feb  6 12:58:14 2015 Dylan Coodien
## Last update Sun Feb 15 15:56:08 2015 Dylan Coodien
##

NAME	= allum1

SRC1	= ./sources/main.c \
	  ./sources/after_turn.c \
	  ./sources/change_buffer.c \
	  ./sources/check_arguments.c \
	  ./sources/check_game.c \
	  ./sources/display_IA_move.c \
	  ./sources/my_free.c \
	  ./sources/default/begin.c \
	  ./sources/default/allum1.c \
	  ./sources/default/manip_list.c \
	  ./sources/default/my_putnbr_base_rev.c \
	  ./sources/default/algo.c \
	  ./sources/help/help.c \
	  ./sources/term/term.c \
	  ./sources/perso/choose_display.c \
	  ./sources/perso/choose_first.c \
	  ./sources/perso/choose_mode.c \
	  ./sources/perso/IA_turn.c \
	  ./sources/perso/list_perso.c \
	  ./sources/perso/turn.c \
	  ./sources/perso/personalize.c \
	  ./sources/players/easy.c \
	  ./sources/players/hard.c \
	  ./sources/players/one_vs_one.c \
	  ./sources/players/players.c

SRC2	= ./lib/my_putstr.c \
	  ./lib/my_putchar.c \
	  ./lib/my_power_it.c \
	  ./lib/my_put_nbr.c \
	  ./lib/my_get_nbr.c \
	  ./lib/my_strlen.c \
	  ./lib/my_strcmp.c \
	  ./lib/my_str_to_word_tab.c

OBJ1	= $(SRC1:.c=.o)

OBJ2	= $(SRC2:.c=.o)

CFLAGS	+= -Wall -Wextra -Werror
CFLAGS	+= -ansi -pedantic
CFLAGS	+= -I./includes/

LDFLAGS	+=

all:	$(NAME)

$(NAME):	$(OBJ1) $(OBJ2)
	ar rc ./lib/libmy.a $(OBJ2)
	ranlib ./lib/libmy.a
	$(CC) -o $(NAME) $(OBJ1) -L./lib/ -lmy

clean:
	$(RM) $(OBJ1) $(OBJ2) ./lib/libmy.a

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

.PHONY:	all clean fclean re