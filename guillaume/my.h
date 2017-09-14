/*
** my.h for my.h in /home/Ordrix0/techadventure
** 
** Made by Guillaume Barthe
** Login   <Ordrix0@epitech.net>
** 
** Started on  Tue Apr 11 15:03:55 2017 Guillaume Barthe
** Last update Sat May 27 16:25:48 2017 Guillaume Barthe
*/

#ifndef GUILLAUME_MY_H_
#define GUILLAUME_MY_H_

#include "./hub_salle/include/arm.h"
#include "./hub_salle/include/hub.h"
#include "./hub_salle/include/trash.h"
#include "./cop_nfc/include/text_salle.h"
#include "./cop_nfc/include/salle.h"
#include "./intro/include/intro.h"
#include "./zombie/include/zon.h"

typedef struct          ati
{
  sfColor               color;
  float			scale_x;
  float			scale_y;
  sfRenderWindow*	window;
  int                   i;
}                       t_my_ati;

typedef struct	s_my_txt
{
  sfText*       txt;
  sfText*       s_txt;
  sfText*	err_box;
  sfText*	find_comp;
  sfText*	mdp;
  sfText*	unlock;
  sfText*	bin;
  sfText*	code_win;
  sfText*	code_found;
}		t_my_txt;

typedef struct	s_my_all
{
  sfText*	bt_y;
  sfText*	bt_n;
  sfText*	ok;
  float		vol;
  sfSprite*	my_last;
  t_my_txt	*txt;
  t_my_hub	*hub;
  t_my_elem	*elem;
  t_my_ati	*ati;
  t_my_trash	*trash;
  t_my_salle	*salle;
  t_my_s_txt	*salle_txt;
}		t_my_all;

int		move_pers(t_my_all *s_all, sfRenderWindow* window);
void		WRSprite(sfSprite* sNom, int x, int y, t_my_ati *ati);
sfSprite*	LdSprite(char* sNom, int repeat);
sfImage*	img(char *path);
void		WRtexte(sfText* txt, int x, int y, sfRenderWindow* window);
sfText*		LdTxt(char *str, char *t_font);
void		WRRectangle(sfVector2f pos, sfVector2f len, \
			    sfRenderWindow* window, sfColor color);
int		box_hub(sfRenderWindow* window, t_my_all *s_all, sfText* txt);
int		hitbox_armory(sfRenderWindow* window, t_my_all *s_all);
int		fct_code(t_my_all *s_all, sfRenderWindow* window, int time);
void		ini_key(int i[4]);
int		box_err(sfRenderWindow* window, t_my_all *s_all, sfText* txt);
int		hit_box_bin(sfRenderWindow* window, t_my_all *s_all);
char		*nb_to_char(int to_f);
float		bouteille_depla(t_my_all *s_all);
void		set_clavier(t_my_all* s_all, int img);
int		disp_code(t_my_all *s_all, sfRenderWindow* window, int img, int i);
int             answer(int key, sfRenderWindow* window);
int		main_intro(sfRenderWindow *window);

#endif /* GUILLAUME_MY_H_ */
