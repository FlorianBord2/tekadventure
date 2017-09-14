/*
** all.h for all.h in /home/Ordrix0/GRAPH/tekadventure
** 
** Made by Guillaume Barthe
** Login   <Ordrix0@epitech.net>
** 
** Started on  Thu May  4 15:14:04 2017 Guillaume Barthe
** Last update Sun May 28 15:23:14 2017 Florian BORD
*/

#ifndef ALL_H_
#define ALL_H_

#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <unistd.h>
#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/Audio.h>
#include <time.h>
#include "./florian/my.h"
#include "./guillaume/my.h"
#include "./Léo/Tek.h"

#define LARG 1920
#define LONG 1080
#define _HEIGHT 1080
#define _WIDTH 1920
#define VIC1 15
#define D 96
#define G 48
#define DPL_COR 5

typedef struct	s_my_tek
{
  t_my_all	*s_all;
  la_struct	pac;
}		t_my_tek;

int		my_corridor(la_struct pac, t_my_all *s_all);
la_struct	gm(la_struct pac, t_my_all *s_all);
la_struct       gain_hub(la_struct pac, t_my_all *s_all);
int		hit_menu(t_my_tek *tek);
int             main_nfc(sfRenderWindow *window, t_my_all *s_all);
int		hit_my_exit(t_my_all *s_all);
int             main_d_zon(sfRenderWindow *window, t_my_all *s_all, la_struct pac);
void		my_sleep(int delay);
la_struct       shot_loop(la_struct pac, t_my_all *s_all);
void		hub_rp(t_my_all *s_all, t_data *data);
void		txt_rp(t_my_all *s_all);
void		elem_rp(t_my_all *s_all, t_data *data);
void		trash_rp(t_my_all *s_all, t_data *data);
int		remp(t_my_all *s_all, t_data *data);
int		my_salle(t_my_all *s_all, t_data *data);
la_struct       init_texture(la_struct struc, t_data *data);
la_struct       init_texture2(la_struct struc, t_data *data);
la_struct       init_gm_texture(la_struct pac, t_data *data);
la_struct       init_elevator(la_struct pac, t_data *data);
la_struct       init_texture3(la_struct pac, t_data *data);
la_struct       init_shot(la_struct pac, t_data *data);
la_struct       init_shot2(la_struct pac, t_data *data);
la_struct       init_music(la_struct struc, t_data *data);
la_struct       if_corridor(la_struct pac, t_my_all *s_all);
int		my_zon(t_my_zon *s_zon, t_data *data);
int		o_part(sfRenderWindow *window, t_my_intro *intro);
int		set_zombie(t_my_zon *s_zon, sfRenderWindow *window, int zon);
void		set_font(sfRenderWindow* window, t_my_zon *s_zon);
void            walk_perso(t_my_zon *s_zon, sfRenderWindow *window);

#endif /* ALL_H_ */
