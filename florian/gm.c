/*
** gm.c for  in /home/Neo/zest/menu
** 
** Made by Florian BORD
** Login   <Neo@epitech.net>
** 
** Started on  Tue Apr 18 15:39:15 2017 Florian BORD
** Last update Fri May 26 11:54:52 2017 Florian BORD
*/

#include "../all.h"

la_struct		gm(la_struct pac, t_my_all *s_all)
{
  if (pac.lvl1done == 0)
    my_scene(pac);
  if (pac.lvl1done == 0)
    {
      sfMusic_stop(pac.mu_menu);
      sfMusic_play(pac.gm.daru);
      sfMusic_setVolume(pac.gm.daru, pac.stparam.vol);
      sfMusic_setVolume(pac.sound.gmover, pac.stparam.vol);
      my_degu(pac);
      pac.done = 0;
      pac = gm_loop(pac);
      if (pac.lvl1done == 1)
	{
	  sfMusic_stop(pac.gm.daru);
	  my_deg(pac);
	  my_scene2(pac);
	  my_corridor(pac, s_all);
	}
      sfMusic_play(pac.mu_menu);
    }
  return (pac);
}

la_struct	gm_loop(la_struct pac)
{
  sfEvent	event;

  while (pac.done != 1)
    {
      sfRenderWindow_pollEvent(pac.window, &event);
      pac.gm.anim = anim_file(pac.gm.perso);
      pac = place_enem(pac);
      pac = my_key(pac);
      if (pac.gm.prog >= VIC1)
	{
	  pac.lvl1done = 1;
	  pac.done = 1;
	}
      else if (find_coli(pac) == 1)
	{
	  if (pac.lvl1done == 1)
	    return (pac);
	  sfMusic_play(pac.sound.gmover);
	  pac = my_reset(pac);
	  sfMusic_play(pac.gm.daru);
	  my_sleep(2);
	}
      sfSprite_setScale(pac.gm.anim, pac.gm.scale);
      sfSprite_setPosition(pac.gm.anim, pac.gm.ppos);
      pac = scrol_log(pac);
      disp_gm(pac);
    }
  return (pac);
}

la_struct	my_key(la_struct pac)
{
  if (sfKeyboard_isKeyPressed(sfKeyRight) && pac.gm.ppos.x < 1420 - 285)
    pac.gm.ppos.x = pac.gm.ppos.x + 30;
  if (sfKeyboard_isKeyPressed(sfKeyLeft) && pac.gm.ppos.x > -50)
    pac.gm.ppos.x = pac.gm.ppos.x - 30;
  return (pac);
}

la_struct	my_reset(la_struct pac)
{
  pac.gm.nb_enem = 0;
  pac.gm.ppos = placepos(LARG / 2 - 160, LONG - 400);
  pac.gm.prog = 0;
  pac.gm.scale2.y = 820;
  pac.gm.enempos2.y = -220;
  sfSprite_setPosition(pac.gm.enem2, pac.gm.enempos2);
  pac.gm.pitch = 1;
  pac.gm.speed = 10;
  sfMusic_stop(pac.gm.daru);
  return (pac);
}

la_struct	deplace_back(la_struct pac)
{
  if (pac.gm.back_pos.y >= 2500)
    {
      pac.gm.back_pos.y = 0;
      pac.gm.back_pos2.y = -2500;
    }
  else
    {
      pac.gm.back_pos.y = pac.gm.back_pos.y + pac.gm.speed;
      pac.gm.back_pos2.y = pac.gm.back_pos2.y + pac.gm.speed;
    }
  sfSprite_setPosition(pac.gm.back, pac.gm.back_pos);
  sfSprite_setPosition(pac.gm.back2, pac.gm.back_pos2);
  return (pac);
}
