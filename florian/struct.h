/*
** struct.h for  in /home/Neo/zest/menu
** 
** Made by Florian BORD
** Login   <Neo@epitech.net>
** 
** Started on  Thu Apr 27 10:50:14 2017 Florian BORD
** Last update Sun May 28 14:54:36 2017 Florian BORD
*/

#ifndef FLO_ST_H_
#define FLO_ST_H_

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/Audio.h>

typedef struct
{
  sfSprite      *perso;
  sfSprite      *back;
  sfSprite      *door;
  sfSprite	*door2;
  sfSprite	*door3;
  sfSprite	*up;
  sfSprite	*Dr;
  sfSprite	*Ga;
  sfSprite	*check;
  sfSprite	*parallax;
  sfSprite	*noir;
  int		door_find;
  int		hub_find;
  int		hubdone;
  sfVector2f	para_pos;
  sfVector2f	cor_pos;
  sfVector2f	door1_pos;
  sfVector2f	door2_pos;
  sfVector2f	door3_pos;
  sfVector2f	noirpos;
}       corr;

typedef struct
{
  sfSprite      *plus;
  sfSprite      *plus2;
  sfSprite      *moins;
  sfSprite      *moins2;
  sfSprite      *volume;
  float         vol;
}       parameter;

typedef struct
{
  int           nb_enem;
  sfVector2f    enempos;
  sfVector2f    enempos2;
  sfVector2f    ppos;
  sfSprite      *anim;
  sfEvent       *event;
  sfSprite      *perso;
  sfSprite      *enem1;
  sfSprite      *enem2;
  sfVector2f    scale;
  sfVector2f    scale2;
  int           prog;
  sfText        *score;
  sfFont        *font;
  sfSprite      *log;
  sfSprite      *back;
  sfSprite      *back2;
  sfVector2f    back_pos;
  sfVector2f    back_pos2;
  sfSprite      *inlog;
  sfSprite      *flou;
  float         speed;
  sfMusic       *daru;
  float         pitch;
  sfSprite      *go;
}       game;

typedef struct
{
  sfSprite	*perso;
  sfSprite	*back;
  sfSprite	*down;
  sfSprite	*act;
  sfText	*text;
  sfFont	*font;
  sfImage	*back_font;
  sfVector2i	mouse;
  sfVector2f	ppos;
  sfVector2f	taille;
  sfEvent	event;
  int		done;
  int		where;
}	shot;

typedef struct
{
  sfSprite	*on1;
  sfSprite      *on2;
  sfSprite      *on3;
  sfSprite	*off1;
  sfSprite      *off2;
  sfSprite      *off3;
  sfSprite	*anu1;
  sfSprite	*anu2;
  sfSprite	*anu3;
  sfVector2f	s_1;
  sfVector2f	s_2;
  sfVector2f	s_3;
  int		stat_1;
  int		stat_2;
  int		stat_3;
}	six;

typedef struct
{
  sfSprite	*back;
  sfSprite	*pc;
  sfSprite	*cle;
  sfSprite	*cle2;
}	hud;

typedef struct
{
  sfSprite	*door1;
  sfSprite	*door2;
  sfVector2f	door1_pos;
  sfVector2f	door2_pos;
}	elev;

typedef struct
{
  sfMusic	*gmover;
  sfMusic	*menu;
  sfMusic	*corridor;
  sfMusic	*door;
  sfMusic	*walk;
}	sound;

typedef struct
{
  sfSprite	*back;
  sfText	*gui;
  sfText	*flo;
  sfText	*hug;
  sfText	*leo;
  sfFont	*ttf;
  sfVector2f	gpos;
  sfVector2f	fpos;
  sfVector2f	lpos;
  sfVector2f	hpos;
  float		L;
  float		l;
}	credit;

typedef struct
{
  credit		cred;
  sound			sound;
  elev			elev;
  game                  gm;
  corr                  cor;
  shot			shot;
  six			six;
  hud			hud;
  sfRenderWindow        *window;
  sfSprite              *jouer;
  sfSprite              *param;
  sfSprite              *credit;
  sfSprite              *jouer2;
  sfSprite              *param2;
  sfSprite              *credit2;
  sfSprite              *quit;
  sfSprite              *quit2;
  sfSprite              *planet;
  sfMusic               *mu_menu;
  sfVector2i            volume;
  float                 degre;
  int                   res;
  parameter             stparam;
  int                   last;
  int                   done;
  sfSprite              *scene1;
  sfSprite              *scene2;
  int                   lvl1done;
  int			lvlcledone;
  sfText*		my_ox;
  int			ddone;
}       la_struct;

#endif /* FLO_ST_H_ */
