/*
** zon.h for zon.h in /home/Ordrix0/GRAPH/tekadventure/guillaume/zombie/include
** 
** Made by Guillaume Barthe
** Login   <Ordrix0@epitech.net>
** 
** Started on  Fri May  5 12:08:17 2017 Guillaume Barthe
** Last update Sat May 27 16:29:34 2017 Guillaume Barthe
*/

#ifndef ZOMBIE_H_
#define ZOMBIE_H_

typedef struct		all_zon
{
  float			x_zon;
  int			hit;
  int			direction;
  int			zon;
  int			spawn;
  sfVector2i		pos_spawn;
  struct all_zon	*next;
}			t_all_zon;

typedef struct	s_my_pos
{
  sfVector2f	perso;
  sfVector2f	font;
  sfVector2f	taille_perso;
  sfVector2f	taille_zon;
  sfVector2f	taille_epee_h;
  sfVector2f	taille_epee_n;
  int		direction_epee;
  float		x_zon;
  sfVector2i	pos_spawn;
}		t_my_pos;

typedef struct	s_my_zon
{
  sfSprite*	zombie;
  sfSprite*	perso;
  sfSprite*	font;
  sfSprite*	terre;
  sfSprite*	building;
  sfSprite*     sun;
  sfSprite*	s_build;
  sfSprite*     f_build;
  sfSprite*     t_build;
  sfSprite*	epee_n;
  sfSprite*     epee_h;
  sfSprite*	pise;
  sfSprite*	b_life;
  int		nb_zon;
  int		spawn;
  float		life;
  int		hit;
  int		direction;
  sfText*	instruc;
  int		epee_count;
  sfMusic*	ruit;
  t_my_pos	*pos;
}		t_my_zon;

void             draw_epee_h(t_my_zon *s_zon, sfRenderWindow *window);
void		draw_epee_n(t_my_zon *s_zon, sfRenderWindow *window);
int             zombie_death(t_my_zon *s_zon, sfRenderWindow* window);
int             zombie_depla(t_my_zon *s_zon, sfRenderWindow *window);
int             zombie_spawn(t_my_zon *s_zon, sfRenderWindow *window);
sfSprite        *my_z_death(sfSprite *sprite, int dir, t_my_zon *s_zon);
sfSprite        *z_get_depla(sfSprite *sprite, int dir, t_my_zon *s_zon);
sfSprite        *z_get_sprite(sfSprite *sprite, int dir, t_my_zon *s_zon);
sfSprite        *anim_perso(sfSprite *sprite, int dir, int depla);
int             my_life(t_my_zon *s_zon, sfRenderWindow *window);
void            anim_car(sfSprite* perso, int dir, int depla);
int		left_walk(t_my_zon *s_zon, int dir);
int		right_walk(t_my_zon *s_zon, int dir);
t_all_zon	*my_list(t_all_zon *i, int nb);

#endif /* ZOMBIE_H_ */
