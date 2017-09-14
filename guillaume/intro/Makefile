##
## Makefile for Makefile in /home/Ordrix0/PSU_2016_my_printf_bootstrap
## Made by Guillaume Barthe
## Login   <Ordrix0@epitech.net>
##
## Started on  Tue Nov  8 16:54:50 2016 Guillaume Barthe
## Last update Tue May  2 17:34:20 2017 Guillaume Barthe
##

CC	= gcc

RM	= rm -f

CFLAGS	= -Wall -Wextra

SRCS     = main.c	\
	   sprite_set.c	\
	   intro_r.c

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
