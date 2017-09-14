/*
** perso_depla.c for perso_depla.c in /home/Ordrix0/GRAPH/tekadventure/guillaume/cop_nfc
** 
** Made by Guillaume Barthe
** Login   <Ordrix0@epitech.net>
** 
** Started on  Thu May  4 13:10:03 2017 Guillaume Barthe
** Last update Fri May 26 11:38:14 2017 Guillaume Barthe
*/

#include "../../all.h"

void	print_img(float x, t_my_all *s_all, int count)
{
  if (count == 0)
    WRSprite(s_all->salle->gilda, x, 350, s_all->ati);
  if (count == 1)
    WRSprite(s_all->salle->sprite, x, 350, s_all->ati);
  if (count == 2)
    WRSprite(s_all->salle->tala, x - 50, 350, s_all->ati);
}

float		bouteille_depla(t_my_all *s_all)
{
  static float	x = 200;
  static int	temps = 0;
  static int	ava = 0;
  static int	val = 0;
  static int	count = 0;

  if (val == 0)
    val = rand() % 1000;
  if (x > 540)
    {
      val = rand() % 700;
      x = rand()%300;
      temps = 0;
      count = rand()%3;
    }
  if (x > 440 && temps != val)
    ava = 1;
  if (ava == 1)
    temps++;
  if (temps == val)
    ava = 0;
  if (temps == 100 || ava == 0)
    x = x + 0.1;
  print_img(x, s_all, count);
  return (x);
}
