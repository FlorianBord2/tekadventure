/*
** enemi.c for  in /home/Neo/zest/menu
** 
** Made by Florian BORD
** Login   <Neo@epitech.net>
** 
** Started on  Mon Apr 24 10:06:51 2017 Florian BORD
** Last update Tue May 23 13:39:52 2017 Florian BORD
*/

#include "../all.h"

la_struct       place_enem(la_struct pac)
{
  if (pac.gm.enempos.y > 1080)
    pac.gm.nb_enem = 0;
  if (pac.gm.nb_enem == 0)
    {
      pac.gm.prog = pac.gm.prog + 1;
      pac.gm.enempos =  placepos((pac.gm.ppos.x), -128);
      sfSprite_setPosition(pac.gm.enem1, pac.gm.enempos);
      pac.gm.nb_enem = pac.gm.nb_enem + 1;
      if (pac.gm.speed < 20)
	pac.gm.speed = pac.gm.speed + 0.05;
      pac.gm.pitch = pac.gm.pitch + 0.005;
      sfMusic_setPitch(pac.gm.daru, pac.gm.pitch);
    }
  else
    {
      sfSprite_setPosition(pac.gm.enem1, pac.gm.enempos);
      pac.gm.enempos.y = pac.gm.enempos.y + pac.gm.speed;
    }
  pac = place_enem_dir(pac);
  pac = deplace_back(pac);
  return (pac);
}

la_struct       place_enem_dir(la_struct pac)
{
  if (pac.gm.prog > 5)
    {
      if (pac.gm.enempos2.y > LONG + 20)
	{
	  pac.gm.enempos2.y = -220;
	  pac.gm.enempos2.x = rand() % 1420;
	}
      if (pac.gm.enempos2.x < pac.gm.ppos.x && pac.gm.enempos2.y < 300)
	pac.gm.enempos2.x = pac.gm.enempos2.x + 6;
      if (pac.gm.enempos2.x > pac.gm.ppos.x && pac.gm.enempos2.y < 300)
	pac.gm.enempos2.x = pac.gm.enempos2.x - 6;
      pac.gm.enempos2.y = pac.gm.enempos2.y + pac.gm.speed;
      sfSprite_setPosition(pac.gm.enem2, pac.gm.enempos2);
    }
  return (pac);
}

int     find_coli(la_struct pac)
{
  if (pac.gm.enempos.y + 128 > pac.gm.ppos.y)
    if (pac.gm.enempos.x > (pac.gm.ppos.x - 50))
      if (pac.gm.enempos.x - 128 < pac.gm.ppos.x + 150)
	return (1);
  if (pac.gm.enempos2.y + 128 > pac.gm.ppos.y)
    if (pac.gm.enempos2.x > (pac.gm.ppos.x - 50))
      if (pac.gm.enempos2.x - 128 < pac.gm.ppos.x + 150)
	return (1);
}
