/*
** remp_zon.c for remp_zon.c in /home/Ordrix0/GRAPH/tekadventure/guillaume/zombie
** 
** Made by Guillaume Barthe
** Login   <Ordrix0@epitech.net>
** 
** Started on  Fri May  5 12:09:58 2017 Guillaume Barthe
** Last update Sat May 27 16:49:58 2017 Guillaume Barthe
*/

#include "../../all.h"

void	next(t_my_zon *s_zon)
{
  s_zon->pos->font.x = 0;
  s_zon->pos->font.y = 0;
  s_zon->pos->perso.x = _WIDTH/2;
  s_zon->pos->perso.y = _HEIGHT/2 + 165;
  s_zon->pos->taille_perso.x = 32;
  s_zon->pos->taille_perso.y = 48;
  s_zon->pos->taille_zon.x = 49;
  s_zon->pos->taille_zon.y = 74;
  s_zon->spawn = 0;
  s_zon->pos->x_zon = 1700;
  s_zon->life = 100;
  s_zon->hit = 0;
  s_zon->pos->taille_epee_n.x = 105;
  s_zon->pos->taille_epee_n.y = 102;
  s_zon->pos->taille_epee_h.x = 127;
  s_zon->pos->taille_epee_h.y = 64;
  s_zon->pos->direction_epee = 0;
  s_zon->direction = 3;
}

int	my_zon(t_my_zon *s_zon, t_data *data)
{
  if (!(s_zon->pos = malloc(sizeof (t_my_pos))))
    return (84);
  s_zon->instruc = LdTxt("Deplace-toi avec les fleches \
directionelles\net attaque avec E", "./guillaume/yes.ttf");
  s_zon->zombie = LdSprite(get_name("zombie", data), 0);
  s_zon->perso = LdSprite(get_name("perso", data), 0);
  s_zon->font = LdSprite(get_name("font", data), 0);
  s_zon->sun = LdSprite(get_name("sun", data), 0);
  s_zon->terre = LdSprite(get_name("terre", data), 0);
  s_zon->building = LdSprite(get_name("building", data), 0);
  s_zon->s_build = LdSprite(get_name("s_build", data), 0);
  s_zon->f_build = LdSprite(get_name("f_build", data), 0);
  s_zon->t_build = LdSprite(get_name("t_build", data), 0);
  s_zon->epee_n = LdSprite(get_name("epee_n", data), 0);
  s_zon->epee_h = LdSprite(get_name("epee_h", data), 0);
  s_zon->pise = LdSprite(get_name("pise", data), 0);
  s_zon->ruit = sfMusic_createFromFile("./guillaume/zombie/img/ambiance.ogg");
  s_zon->b_life = LdSprite(get_name("b_life", data), 0);
  s_zon->nb_zon = 3;
  s_zon->pos->pos_spawn.x = 77;
  s_zon->pos->pos_spawn.y = 210;
  s_zon->epee_count = 0;
  next(s_zon);
}

t_all_zon *add_zon(t_all_zon *i_back)
{
  t_all_zon *i;

  if (!(i = malloc(sizeof (t_all_zon))))
    return (NULL);
  i->spawn = 0;
  i->hit = 0;
  i->x_zon = rand()%3500;
  i->zon = 0;
  i->direction = 3;
  i->pos_spawn.x = 77;
  i->pos_spawn.y = 210;
  i->next = i_back;
  return (i);
}

t_all_zon    *my_list(t_all_zon *i, int nb)
{
  while (nb > 0)
    {
      i = add_zon(i);
      nb = nb - 1;
    }
  return (i);
}
