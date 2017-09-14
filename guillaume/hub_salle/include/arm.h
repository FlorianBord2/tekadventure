/*
** hub.h for hub.h in /home/Ordrix0/techadventure
** 
** Made by Guillaume Barthe
** Login   <Ordrix0@epitech.net>
** 
** Started on  Thu Apr 20 16:57:44 2017 Guillaume Barthe
** Last update Sat May 27 16:27:40 2017 Guillaume Barthe
*/

#ifndef HUB_H_
#define HUB_H_

typedef struct s_my_hub
{
  sfSprite*	table;
  sfSprite*     wall;
  sfSprite*     f_block;
  sfSprite*     armoire;
  sfSprite*     armory;
  sfSprite*     s_armory;
  sfSprite*	bin;
  sfSprite*	s_bin;
  sfSprite*	canap;
  sfSprite*	logo;
  sfImage*      img;
}		t_my_hub;

#endif /* HUB_H_ */
