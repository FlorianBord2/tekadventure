/*
** remp.c for remp.c in /home/Ordrix0/techadventure
** 
** Made by Guillaume Barthe
** Login   <Ordrix0@epitech.net>
** 
** Started on  Mon Apr 24 17:25:53 2017 Guillaume Barthe
** Last update Sat May 27 15:58:49 2017 Guillaume Barthe
*/

#include "../../all.h"

void	hub_rp(t_my_all *s_all, t_data *data)
{
  s_all->hub->wall = LdSprite(get_name("wall", data), 0);
  s_all->hub->f_block = LdSprite(get_name("f_block", data), 0);
  s_all->hub->s_armory = LdSprite(get_name("s_armory", data), 0);
  s_all->hub->bin = LdSprite(get_name("bin", data), 0);
  s_all->hub->s_bin = LdSprite(get_name("s_bin", data), 0);
  s_all->hub->img = img(get_name("img", data));
  s_all->hub->armory = LdSprite(get_name("armory", data), 0);
  s_all->hub->canap = LdSprite(get_name("canap", data), 0);
  s_all->hub->table = LdSprite(get_name("table", data), 0);
  s_all->hub->logo = LdSprite(get_name("logo", data), 0);
}

void	txt_rp(t_my_all *s_all)
{
  s_all->txt->err_box = LdTxt("Mot de passe incorrect...", \
			      "./guillaume/yes.ttf");
  s_all->txt->find_comp = LdTxt("Tu viens de rentrer dans l'armoire, \
tu dois trouver\n ton pc dans tout ce bordel\nAppuies sur \
Echap pour quitter l'armoire", "./guillaume/yes.ttf");
  s_all->txt->mdp = LdTxt("Oh non, le pc est protege par un mot \
de passe,\n tu dois le trouver...", "./guillaume/yes.ttf");
  s_all->txt->unlock = LdTxt("Bravo, tu viens de deverouiller \
ton pc,\n tu peux maintenant t'en servir", "./guillaume/yes.ttf");
  s_all->txt->bin = LdTxt("Veux-tu fouiller dans la poubelle ?", \
			  "./guillaume/yes.ttf");
  s_all->txt->code_win = LdTxt("Tu decouvres dans un des \
papiers un \ncode :<TROL>, il te sera peut-etre utile...", \
			       "./guillaume/yes.ttf");
  s_all->txt->code_found = LdTxt("Ramasse au moins 5 \
papiers\nen cliquant dessus pour pouvoir les lire", "./guillaume/yes.ttf");
  s_all->txt->txt = LdTxt("Veux-tu vraiment quitter ?", \
			  "./guillaume/yes.ttf");
  s_all->txt->s_txt = LdTxt("Veux-tu vraiment acceder a l'armoire ?", \
			    "./guillaume/yes.ttf");
}

void	elem_rp(t_my_all *s_all, t_data *data)
{
  s_all->elem->ordi = LdSprite(get_name("ordi", data), 0);
  s_all->elem->cube = LdSprite(get_name("cube", data), 0);
  s_all->elem->s_ordi = LdSprite(get_name("s_ordi", data), 0);
  s_all->elem->clavier = LdSprite(get_name("clavier", data), 0);
  s_all->elem->t_c = LdSprite(get_name("t_c", data), 0);
  s_all->elem->r_c = LdSprite(get_name("r_c", data), 0);
  s_all->elem->o_c = LdSprite(get_name("o_c", data), 0);
  s_all->elem->l_c = LdSprite(get_name("l_c", data), 0);
  s_all->elem->code_un = 0;
}

void	trash_rp(t_my_all *s_all, t_data *data)
{
  s_all->trash->b_papier = \
    sfMusic_createFromFile("./guillaume/hub_salle/trash/b_papier.ogg");
  s_all->trash->boule = LdSprite(get_name("boule", data), 0);
  s_all->trash->s_boule = LdSprite(get_name("s_boule", data), 0);
  s_all->trash->t_boule = LdSprite(get_name("t_boule", data), 0);
  s_all->trash->img = img(get_name("img_b", data));
}
