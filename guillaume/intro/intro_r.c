/*
** intro_r.c for intro_r.c in /home/Ordrix0/GRAPH/tekadventure/guillaume/intro
** 
** Made by Guillaume Barthe
** Login   <Ordrix0@epitech.net>
** 
** Started on  Tue May  2 17:29:03 2017 Guillaume Barthe
** Last update Tue May 23 14:16:04 2017 Guillaume Barthe
*/

#include "../../all.h"

void	intro_remp(t_my_intro *intro)
{
  intro->letter = LdSprite("./guillaume/intro/img/letter.png", 0);
  intro->fondu = LdSprite("./guillaume/intro/img/fondu.png", 0);
}
