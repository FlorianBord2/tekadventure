/*
** salle_remp.c for salle_remp.c in /home/Ordrix0/GRAPH/tekadventure/guillaume/cop_nfc
** 
** Made by Guillaume Barthe
** Login   <Ordrix0@epitech.net>
** 
** Started on  Mon May  1 12:02:13 2017 Guillaume Barthe
** Last update Sat May 27 15:44:41 2017 Guillaume Barthe
*/

#include "../../all.h"

int	my_salle(t_my_all *s_all, t_data *data)
{
  if ((!(s_all->salle = malloc(sizeof (t_my_salle)))) ||	\
      (!(s_all->salle_txt = malloc(sizeof (t_my_s_txt)))))
    return (84);
  s_all->ati->scale_x = 1;
  s_all->ati->scale_y = 1;
  s_all->salle->my_pc = LdSprite(get_name("my_pc", data), 0);
  s_all->salle->rond = LdSprite(get_name("rond", data), 0);
  s_all->salle->s_rond = LdSprite(get_name("s_rond", data), 0);
  s_all->bt_y = LdTxt("Oui", "./guillaume/yes.ttf");
  s_all->bt_n = LdTxt("Non", "./guillaume/yes.ttf");
  s_all->ok = LdTxt("Ok", "./guillaume/yes.ttf");
  s_all->salle_txt->my_intro = LdTxt("Mets ton badge sur le capteur nfc\nquand\
personne ne te regarde...", "./guillaume/yes.ttf");
  s_all->salle->img_rond = img(get_name("img_rond", data));
  s_all->salle->cycle = LdSprite(get_name("cycle", data), 0);
  s_all->salle->porte_o = LdSprite(get_name("porte_o", data), 0);
  s_all->salle->sprite = LdSprite(get_name("sprite", data), 0);
  s_all->salle->gilda = LdSprite(get_name("gilda", data), 0);
  s_all->salle->tala = LdSprite(get_name("tala", data), 0);
  s_all->salle_txt->font = sfFont_createFromFile("./guillaume/yes.ttf");
  s_all->salle->exit = LdSprite(get_name("exit", data), 0);
  s_all->salle->img_exit = img(get_name("img_exit", data));
  s_all->salle->my_card = LdSprite(get_name("my_card", data), 0);
  s_all->salle->fort_sound = \
    sfMusic_createFromFile("./guillaume/cop_nfc/salle/boyard.ogg");
}
