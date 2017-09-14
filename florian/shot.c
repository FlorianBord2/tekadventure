/*
** shot.c for  in /home/Neo/Graphical/tekadventure/florian
** 
** Made by Florian BORD
** Login   <Neo@epitech.net>
** 
** Started on  Tue May  2 16:20:03 2017 Florian BORD
** Last update Fri May 26 12:26:06 2017 Florian BORD
*/

#include "../all.h"

la_struct	shot_loop(la_struct pac, t_my_all *s_all)
{
  sfMusic_stop(pac.sound.walk);
  box_err(pac.window, s_all, pac.my_ox);
  sfSprite_setPosition(pac.shot.perso, placepos(LARG / 2, 1080));
  while (pac.shot.done == 0)
    {
      sfRenderWindow_pollEvent(pac.window, &pac.shot.event);
      if (pac.six.stat_1 == 1 && pac.six.stat_2 == 0 && pac.six.stat_3 == 2)
	pac.shot.done = 1;
      pac.shot.mouse = sfMouse_getPosition(NULL);
      pac = find_color(pac);
      sfRenderWindow_clear(pac.window, sfBlack);
      sfRenderWindow_drawSprite(pac.window, pac.shot.back, NULL);
      pac = disp_switch(pac);
      sfRenderWindow_drawSprite(pac.window, pac.shot.perso, NULL);
      pac = my_switch(pac);
      if (pac.shot.where == 2)
	sfRenderWindow_drawSprite(pac.window, pac.shot.down, NULL);
      if (sfKeyboard_isKeyPressed(sfKeyDown) && pac.shot.where == 2)
	{
	  pac.cor.door_find = 0;
	  return (pac);
	}
      sfRenderWindow_display(pac.window);
    }
  pac.cor.door_find = 0;
  return (pac);
}

la_struct	disp_switch(la_struct pac)
{
  if (pac.six.stat_1 == 0)
    sfRenderWindow_drawSprite(pac.window, pac.six.off1, NULL);
  else if (pac.six.stat_1 == 1)
    sfRenderWindow_drawSprite(pac.window, pac.six.on1, NULL);
  else
    sfRenderWindow_drawSprite(pac.window, pac.six.anu1, NULL);
  if (pac.six.stat_2 == 0)
    sfRenderWindow_drawSprite(pac.window, pac.six.off2, NULL);
  else if (pac.six.stat_2 == 1)
    sfRenderWindow_drawSprite(pac.window, pac.six.on2, NULL);
  else
    sfRenderWindow_drawSprite(pac.window, pac.six.anu2, NULL);
  if (pac.six.stat_3 == 0)
    sfRenderWindow_drawSprite(pac.window, pac.six.off3, NULL);
  else if (pac.six.stat_3 == 1)
    sfRenderWindow_drawSprite(pac.window, pac.six.on3, NULL);
  else
    sfRenderWindow_drawSprite(pac.window, pac.six.anu3, NULL);
  return (pac);
}

la_struct	find_color(la_struct pac)
{
  sfColor	color;

  color = sfImage_getPixel(pac.shot.back_font, pac.shot.mouse.x,
			   pac.shot.mouse.y);
  if (color.r == 0 && color.g == 0 && color.b == 255 && pac.shot.where == 2)
    if (pac.shot.event.type == sfEvtMouseButtonPressed)
      pac = my_graph(pac, 1);
  if (color.r == 255 && color.g == 0 && color.b == 0)
    if (pac.shot.event.type == sfEvtMouseButtonPressed)
      pac = my_graph(pac, 2);
  if (color.r == 255 && color.g == 156 && color.b == 0 && pac.shot.where != 1)
    if (pac.shot.event.type == sfEvtMouseButtonPressed)
      pac = my_graph(pac, 3);
  if (color.r == 0 && color.g == 255 && color.b == 0 && pac.shot.where != 1)
    if (pac.shot.event.type == sfEvtMouseButtonPressed)
      pac = my_graph(pac, 4);
  pac.shot.perso = get_perso(pac.shot.perso);
  return (pac);
}

la_struct	my_graph(la_struct pac, int w)
{
  pac.shot.where = w;
  while ((pac.shot.ppos.x < (pac.shot.mouse.x - DPL_COR) ||
	  pac.shot.ppos.x > (pac.shot.mouse.x + DPL_COR)) ||
	 (pac.shot.ppos.y < (pac.shot.ppos.y - DPL_COR) ||
	  pac.shot.ppos.y > (pac.shot.ppos.y + DPL_COR)))
    {
      pac = dpl_graph(pac);
      sfRenderWindow_clear(pac.window, sfBlack);
      sfSprite_setPosition(pac.shot.perso, pac.shot.ppos);
      sfSprite_setScale(pac.shot.perso, pac.shot.taille);
      sfRenderWindow_drawSprite(pac.window, pac.shot.back, NULL);
      pac = disp_switch(pac);
      sfRenderWindow_drawSprite(pac.window, pac.shot.perso, NULL);
      sfRenderWindow_display(pac.window);
    }
  sfMusic_stop(pac.sound.walk);
  return (pac);
}

la_struct	dpl_graph(la_struct pac)
{
  if (sfMusic_getStatus(pac.sound.walk) != sfPlaying)
    sfMusic_play(pac.sound.walk);
  if (pac.shot.ppos.x < pac.shot.mouse.x)
    {
      pac.shot.ppos.x = pac.shot.ppos.x + DPL_COR;
      pac.shot.perso = anim_file_cor(pac.shot.perso, D, pac);
    }
  if (pac.shot.ppos.x > pac.shot.mouse.x)
    {
      pac.shot.ppos.x = pac.shot.ppos.x - DPL_COR;
      pac.shot.perso = anim_file_cor(pac.shot.perso, G, pac);
    }
  pac = dpl_graph2(pac);
  return (pac);
}
