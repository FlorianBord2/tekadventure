/*
** my.h for  in /home/Neo/zest/menu
** 
** Made by Florian BORD
** Login   <Neo@epitech.net>
** 
** Started on  Wed Apr 12 14:48:45 2017 Florian BORD
** Last update Sun May 28 14:07:38 2017 Florian BORD
*/

#ifndef FLO_H_
#define FLO_H_

#include "struct.h"

sfSprite        *load_texture(char *str);
int		menu(la_struct pac);
sfVector2f      placepos(float x, float y);
int		find_mouse_jouer(la_struct pac, sfEvent event);
int             find_mouse_param(la_struct pac, sfEvent event);
int             find_mouse_credit(la_struct pac, sfEvent event);
int             find_mouse_quit(la_struct pac, sfEvent event);
int             find_mouse_quit_p(la_struct pac, sfEvent event);
la_struct	my_param(la_struct pac);
la_struct       my_param2(la_struct pac, sfEvent event);
sfSprite        *anim_file(sfSprite *sprite);
la_struct       place_enem(la_struct pac);
la_struct       place_enem_dir(la_struct pac);
char            *my_conv_char(int nbr);
la_struct       my_prog(la_struct pac);
la_struct       scrol_log(la_struct pac);
int		find_coli(la_struct pac);
void		disp_gm(la_struct pac);
la_struct	my_pause(la_struct pac);
la_struct       my_reset(la_struct pac);
la_struct       deplace_back(la_struct pac);
void            my_degu(la_struct pac);
void            my_degu_scene(la_struct pac);
void            my_deg(la_struct pac);
void		my_destroy(la_struct pac);
la_struct       my_key(la_struct pac);
la_struct       gm_loop(la_struct pac);
void		my_scene(la_struct pac);
void            my_degu_scene2(la_struct pac);
void		my_scene2(la_struct pac);
la_struct	find_door(la_struct pac);
la_struct       plc_door(la_struct pac);
sfSprite        *anim_file_cor(sfSprite *sprite, int dir, la_struct pac);
la_struct       dpl(la_struct pac, sfEvent event);
la_struct	colidoor(la_struct pac, sfEvent event);
sfSprite        *get_perso(sfSprite *sprite);
la_struct       my_graph(la_struct pac, int w);
la_struct       dpl_graph(la_struct pac);
la_struct       find_color(la_struct pac);
la_struct       colidoor2(la_struct pac, sfEvent event);
sfSprite        *anim_switch(sfSprite *sprite, int dir);
la_struct       disp_switch(la_struct pac);
sfText          *my_text(char *str, sfFont *font, sfText *text);
la_struct       my_switch(la_struct pac);
void		disp_check(la_struct pac);
void		draw_hud(la_struct pac);
la_struct	in_elevator(la_struct pac);
void		elevator_disp(la_struct pac);
la_struct       my_param3(la_struct pac, sfEvent event, sfVector2f posc);
void		my_credit(la_struct pac);
credit		my_anim_text(credit cred);
la_struct       dpl_graph2(la_struct pac);
la_struct       dpl2(la_struct pac, sfEvent event);

#endif /* FLO_H_ */
