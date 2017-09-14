##
## Makefile for Makefile in /home/Ordrix0/PSU_2016_my_printf_bootstrap
## Made by Guillaume Barthe
## Login   <Ordrix0@epitech.net>
##
## Started on  Tue Nov  8 16:54:50 2016 Guillaume Barthe
## Last update Thu May  4 14:48:36 2017 Guillaume Barthe
##

CC	= gcc

RM	= rm -f

CFLAGS	= -Wall -Wextra

SRCS     = font.c	\
	   hub_case.c	\
	   bin.c	\
	   t_set.c	\
	   code.c	\
	   armory_hit.c	\
	   box_dial.c	\
	   sprite_set.c	\
	   remp.c	\
	   form_set.c	\

OBJS     = $(SRCS:.c=.o)

NAME    = scroller

CFLAGS	= -I./include/
CFLAGS	+= -W -Wall -Wextra

LDFLAGS	= -lc_graph_prog_full -lm

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(OBJS) -o $(NAME) $(LDFLAGS) $(CFLAGS)

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re : fclean all
