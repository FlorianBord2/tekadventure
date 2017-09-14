/*
** fouretout.c for  in /home/Neo/Graphical/tekadventure/florian
** 
** Made by Florian BORD
** Login   <Neo@epitech.net>
** 
** Started on  Wed May 17 14:46:25 2017 Florian BORD
** Last update Sun May 28 18:31:53 2017 Florian BORD
*/

#include "../all.h"

la_struct	dpl2(la_struct pac, sfEvent event)
{
  pac.cor.perso = anim_file_cor(pac.gm.perso, G, pac);
  pac.cor.cor_pos.x = pac.cor.cor_pos.x + DPL_COR;
  pac.cor.para_pos.x = pac.cor.para_pos.x + 2;
  pac.cor.door1_pos.x = pac.cor.door1_pos.x + DPL_COR;
  pac.cor.door2_pos.x = pac.cor.door2_pos.x + DPL_COR;
  pac.cor.door3_pos.x = pac.cor.door3_pos.x + DPL_COR;
  pac.elev.door1_pos.x = pac.elev.door1_pos.x + DPL_COR;
  pac.elev.door2_pos.x = pac.elev.door2_pos.x + DPL_COR;
  pac.cor.noirpos.x = pac.cor.noirpos.x + DPL_COR;
  return (pac);
}

la_struct	if_corridor(la_struct pac, t_my_all *s_all)
{
  if (pac.cor.door_find == 2)
    {
      sfMusic_stop(pac.sound.walk);
      pac = shot_loop(pac, s_all);
    }
  else if (pac.cor.door_find == 3 && pac.shot.done == 1 &&
	   pac.cor.hubdone == 1 && pac.lvlcledone == 0)
    {
      sfMusic_stop(pac.sound.corridor);
      sfMusic_stop(pac.sound.walk);
      pac.lvlcledone = main_nfc(pac.window, s_all);
      sfMusic_stop(s_all->salle->fort_sound);
      sfMusic_play(pac.sound.corridor);
    }
  else if (pac.cor.door_find == 4)
    {
      sfMusic_stop(pac.sound.walk);
      in_elevator(pac);
      my_deg(pac);
      sfMusic_stop(pac.sound.corridor);
      main_d_zon(pac.window, s_all, pac);
      pac.ddone = 1;
      return (pac);
    }
  return (pac);
}
