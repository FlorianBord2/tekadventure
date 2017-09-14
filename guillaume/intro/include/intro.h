/*
** intro.h for intro.h in /home/Ordrix0/GRAPH/tekadventure/guillaume/intro/include
** 
** Made by Guillaume Barthe
** Login   <Ordrix0@epitech.net>
** 
** Started on  Tue May  2 17:27:11 2017 Guillaume Barthe
** Last update Sat May 27 16:30:07 2017 Guillaume Barthe
*/

#ifndef INTRO_H_
#define INTRO_H_

typedef struct	s_my_intro
{
  sfSprite*	letter;
  sfSprite*	fondu;
}		t_my_intro;

void    last_tap(t_my_intro *intro, sfRenderWindow* window);
int     fondu(t_my_intro *intro, sfRenderWindow *window);
int     intro(t_my_intro *intro, sfRenderWindow *window, int vitesse);
void    entire(t_my_intro *intro, sfRenderWindow* window);
void    remp_pos(sfVector2f pos[12]);
void    WRSprite_window(sfSprite* sNom, int x, int y, sfRenderWindow *window);
void    WRLetter(sfVector2f pos, sfVector2f taille, sfSprite *sNom);
void    intro_remp(t_my_intro *intro);

#endif /* INTRO_H_ */
