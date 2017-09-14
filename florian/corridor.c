/*
** corridor.c for  in /home/Neo/zest/menu
** 
** Made by Florian BORD
** Login   <Neo@epitech.net>
** 
** Started on  Thu Apr 27 10:59:03 2017 Florian BORD
** Last update Sun May 28 18:26:51 2017 Florian BORD
*/

#include "../all.h"

int		my_corridor(la_struct pac, t_my_all *s_all)
{
  sfMusic_setVolume(pac.sound.corridor, pac.stparam.vol);
  sfMusic_setVolume(pac.sound.walk, pac.stparam.vol);
  sfMusic_play(pac.sound.corridor);
  while (pac.ddone == 0)
    {
      pac.cor.hub_find = 1;
      pac = find_door(pac);
      pac = gain_hub(pac, s_all);
      pac = if_corridor(pac, s_all);
      pac.cor.door_find = 0;
    }
  return (0);
}

la_struct	find_door(la_struct pac)
{
  sfEvent	event;

  while (pac.cor.door_find == 0 && pac.ddone != 1)
    {
      sfRenderWindow_pollEvent(pac.window, &event);
      sfRenderWindow_clear(pac.window, sfWhite);
      sfSprite_setPosition(pac.cor.back, pac.cor.cor_pos);
      sfSprite_setPosition(pac.cor.parallax, pac.cor.para_pos);
      sfRenderWindow_drawSprite(pac.window, pac.cor.parallax, NULL);
      sfRenderWindow_drawSprite(pac.window, pac.cor.back, NULL);
      pac = plc_door(pac);
      pac = dpl(pac, event);
      pac = colidoor(pac, event);
      sfSprite_setScale(pac.cor.perso, pac.gm.scale);
      sfSprite_setPosition(pac.cor.perso, placepos(800, 600));
      disp_check(pac);
      sfRenderWindow_drawSprite(pac.window, pac.cor.perso, NULL);
      sfRenderWindow_drawSprite(pac.window, pac.cor.Dr, NULL);
      sfRenderWindow_drawSprite(pac.window, pac.cor.Ga, NULL);
      sfRenderWindow_display(pac.window);
      printf("Chneck\n");
    }
  return (pac);
}

la_struct	colidoor(la_struct pac, sfEvent event)
{
  if (pac.cor.door1_pos.x > ((LARG / 2) - 350) &&
      pac.cor.door1_pos.x < ((LARG / 2) + 350))
    if (pac.cor.door1_pos.x > ((LONG / 2) - 350) &&
	pac.cor.door1_pos.x < ((LONG / 2) + 350) && pac.cor.hubdone != 1)
      {
	sfRenderWindow_drawSprite(pac.window, pac.cor.up, NULL);
	if (sfKeyboard_isKeyPressed(sfKeyUp))
	  pac.cor.door_find = 1;
      }
  if (pac.cor.door2_pos.x > ((LARG / 2) - 350) &&
      pac.cor.door2_pos.x < ((LARG / 2) + 350))
    if (pac.cor.door2_pos.x > ((LONG / 2) - 350) &&
	pac.cor.door2_pos.x < ((LONG / 2) + 350) && pac.shot.done != 1)
      {
	sfRenderWindow_drawSprite(pac.window, pac.cor.up, NULL);
	if (sfKeyboard_isKeyPressed(sfKeyUp))
	  pac.cor.door_find = 2;
      }
  pac = colidoor2(pac, event);
  if (pac.cor.door_find != 0)
    {
      sfMusic_play(pac.sound.door);
      my_sleep(1);
    }
  return (pac);
}

la_struct	dpl(la_struct pac, sfEvent event)
{
  sfVector2i	mouse;

  mouse = sfMouse_getPosition(NULL);
  if (sfMusic_getStatus(pac.sound.walk) != sfPlaying)
    sfMusic_play(pac.sound.walk);
  if (mouse.x < 200 && pac.cor.cor_pos.x < 1)
      pac = dpl2(pac, event);
  else if (mouse.x > 1720  && pac.cor.cor_pos.x > -5080)
    {
      pac.cor.perso = anim_file_cor(pac.gm.perso, D, pac);
      pac.cor.cor_pos.x = pac.cor.cor_pos.x - DPL_COR;
      pac.cor.para_pos.x = pac.cor.para_pos.x - 2;
      pac.cor.door1_pos.x = pac.cor.door1_pos.x - DPL_COR;
      pac.cor.door2_pos.x = pac.cor.door2_pos.x - DPL_COR;
      pac.cor.door3_pos.x = pac.cor.door3_pos.x - DPL_COR;
      pac.elev.door1_pos.x = pac.elev.door1_pos.x - DPL_COR;
      pac.elev.door2_pos.x = pac.elev.door2_pos.x - DPL_COR;
      pac.cor.noirpos.x = pac.cor.noirpos.x - DPL_COR;
    }
  else
    {
      sfMusic_stop(pac.sound.walk);
      pac.cor.perso = anim_file_cor(pac.gm.perso, 0, pac);
    }
  return (pac);
}

la_struct	plc_door(la_struct pac)
{
  sfSprite_setPosition(pac.cor.door, pac.cor.door1_pos);
  sfRenderWindow_drawSprite(pac.window, pac.cor.door, NULL);
  sfSprite_setPosition(pac.cor.door2, pac.cor.door2_pos);
  sfRenderWindow_drawSprite(pac.window, pac.cor.door2, NULL);
  sfSprite_setPosition(pac.cor.door3, pac.cor.door3_pos);
  sfRenderWindow_drawSprite(pac.window, pac.cor.door3, NULL);
  sfSprite_setPosition(pac.elev.door1, pac.elev.door1_pos);
  sfSprite_setPosition(pac.elev.door2, pac.elev.door2_pos);
  sfSprite_setPosition(pac.cor.noir, pac.cor.noirpos);
  sfRenderWindow_drawSprite(pac.window, pac.cor.noir, NULL);
  sfRenderWindow_drawSprite(pac.window, pac.elev.door1, NULL);
  sfRenderWindow_drawSprite(pac.window, pac.elev.door2, NULL);
  return (pac);
}
