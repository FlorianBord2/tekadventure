##
## Makefile for  in /home/Neo/zest/menu
## 
## Made by Florian BORD
## Login   <Neo@epitech.net>
## 
## Started on  Wed Apr 12 13:23:04 2017 Florian BORD
## Last update Sat May 27 16:38:32 2017 Guillaume Barthe
##

CC	= gcc

RM	= rm -f

SRC	=	main_all.c	\
		florian/main.c \
		florian/load_sprite.c \
		florian/load_sprite2.c \
		florian/find_mouse.c \
		florian/gm.c \
		florian/text.c \
		florian/enemi.c \
		florian/sound.c \
		florian/scene.c \
		florian/disp.c \
		florian/fct.c \
		florian/corridor.c \
		florian/shot.c \
		florian/shot2.c	\
		florian/menu_menu.c	\
		florian/corridor2.c \
		florian/elevator.c \
		florian/my_credit.c \
		florian/fouretout.c \
		guillaume/hub_salle/font.c	\
		guillaume/hub_salle/hub_case.c \
		guillaume/hub_salle/bin.c \
		guillaume/hub_salle/code.c \
		guillaume/hub_salle/armory_hit.c \
		guillaume/hub_salle/box_dial.c \
		guillaume/hub_salle/sprite_set.c \
		guillaume/hub_salle/remp.c \
		guillaume/hub_salle/form_set.c \
	        guillaume/hub_salle/t_set.c	\
		guillaume/intro/intro_r.c	\
		guillaume/intro/main.c	\
		guillaume/intro/my_fondu.c	\
		guillaume/intro/sprite_set.c	\
		guillaume/cop_nfc/perso_depla.c	\
		guillaume/cop_nfc/salle_remp.c	\
		guillaume/cop_nfc/int_to_str.c	\
		guillaume/cop_nfc/main.c	\
		guillaume/cop_nfc/hit_my_exit.c	\
		guillaume/zombie/main.c	\
		guillaume/zombie/my_sp_de.c	\
		guillaume/zombie/zombie.c	\
		guillaume/zombie/my_font_set.c	\
		guillaume/zombie/epee.c	\
		guillaume/zombie/my_car.c	\
		guillaume/zombie/remp_zon.c	\
		guillaume/my_sleep.c	\
		Léo/get_name.c	\
		Léo/pars.c	\
		Léo/pars_useful.c	\

OBJ	=	$(SRC:.c=.o)

NAME	=	tekadventure

all:		$(NAME)

$(NAME):	$(OBJ)
		$(CC) $(OBJ) -o $(NAME) -lc_graph_prog_full

clean:
		$(RM) $(OBJ)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all
