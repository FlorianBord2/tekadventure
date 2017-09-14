/*
** salle.h for salle.h in /home/Ordrix0/GRAPH/tekadventure/guillaume/cop_nfc/include
** 
** Made by Guillaume Barthe
** Login   <Ordrix0@epitech.net>
** 
** Started on  Mon May  1 11:51:31 2017 Guillaume Barthe
** Last update Sat May 27 16:26:44 2017 Guillaume Barthe
*/

#ifndef NFC_H_
#define NFC_H_

typedef struct	s_my_salle
{
  sfSprite*	my_pc;
  sfSprite*	rond;
  sfSprite*	s_rond;
  sfSprite*	cycle;
  sfSprite*	gilda;
  sfSprite*	tala;
  sfSprite*	sprite;
  sfSprite*	porte_o;
  sfSprite*	my_card;
  sfSprite*	exit;
  sfImage*	img_rond;
  sfImage*	img_exit;
  sfMusic*	fort_sound;
}		t_my_salle;

#endif /* NFC_H_ */
