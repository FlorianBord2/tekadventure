/*
** load_sprite.c for  in /home/Neo/zest/menu
** 
** Made by Florian BORD
** Login   <Neo@epitech.net>
** 
** Started on  Wed Apr 12 14:46:33 2017 Florian BORD
** Last update Sun May 28 14:54:56 2017 Florian BORD
*/

#include "../all.h"

la_struct	init_texture(la_struct struc, t_data *data)
{
  struc.cor.hubdone = 0;
  struc.jouer = load_texture(get_name("jouer", data));
  struc.param = load_texture(get_name("param", data));
  struc.credit = load_texture(get_name("credit", data));
  struc.planet = load_texture(get_name("planet", data));
  struc.jouer2 = load_texture(get_name("jouer2", data));
  struc.param2 = load_texture(get_name("param2", data));
  struc.credit2 = load_texture(get_name("credit2", data));
  struc.scene2 = load_texture(get_name("scene2", data));
  struc.gm.go = load_texture(get_name("go", data));
  struc.cor.parallax = load_texture(get_name("parallax", data));
  sfSprite_setPosition(struc.jouer, placepos((LARG / 2 - 200), (100)));
  sfSprite_setPosition(struc.param, placepos((LARG / 2 - 200), (250)));
  sfSprite_setPosition(struc.credit, placepos((LARG / 2 - 200), (400)));
  sfSprite_setPosition(struc.jouer2, placepos((LARG / 2 - 200), (100)));
  sfSprite_setPosition(struc.param2, placepos((LARG / 2 - 200), (250)));
  sfSprite_setPosition(struc.credit2, placepos((LARG / 2 - 200), (400)));
  sfSprite_setOrigin(struc.planet, placepos(511, 413));
  sfSprite_setPosition(struc.planet, placepos(LARG / 2, LONG / 2));
  sfSprite_setScale(struc.planet, placepos(1.5, 1.5));
  struc.stparam.vol = 50;
  struc.last = 0;
  struc.lvl1done = 0;
  struc = init_texture2(struc, data);
  struc.lvlcledone = 0;
  return (struc);
}

la_struct	init_texture2(la_struct struc, t_data *data)
{
  sfVideoMode           mode = {LARG, LONG, 32};

  struc.stparam.plus = load_texture(get_name("plus", data));
  struc.stparam.plus2 = load_texture(get_name("plus2", data));
  struc.stparam.moins = load_texture(get_name("moins", data));
  struc.stparam.moins2 = load_texture(get_name("moins2", data));
  struc.stparam.volume = load_texture(get_name("volume", data));
  struc.quit = load_texture(get_name("quit", data));
  struc.scene1 = load_texture(get_name("scene1", data));
  struc.quit2 = load_texture(get_name("quit2", data));
  sfSprite_setPosition(struc.quit2, placepos((LARG / 2 - 200), (550)));
  sfSprite_setPosition(struc.quit, placepos((LARG / 2 - 200), (550)));
  sfSprite_setPosition(struc.stparam.moins, placepos(710, 700));
  sfSprite_setPosition(struc.stparam.plus, placepos(1110, 700));
  sfSprite_setPosition(struc.stparam.moins2, placepos(710, 700));
  sfSprite_setPosition(struc.stparam.plus2, placepos(1110, 700));
  sfSprite_setPosition(struc.stparam.volume, placepos(860, 750));
  struc.window = sfRenderWindow_create(mode, "EpiJeux", sfFullscreen | sfClose
				       , NULL);
  sfRenderWindow_setFramerateLimit(struc.window, 60);
  struc = init_gm_texture(struc, data);
  struc.degre = 0;
  struc = init_music(struc, data);
  struc.res = 0;
  return (struc);
}

la_struct	init_gm_texture(la_struct pac, t_data *data)
{
  pac.gm.scale = placepos(10, 10);
  pac.gm.ppos = placepos(LARG / 2 - 160, LONG - 400);
  pac.gm.scale2 = placepos(1460, 800);
  pac.gm.nb_enem = 0;
  pac.gm.prog = 0;
  pac.gm.score = sfText_create();
  pac.gm.enem2 = load_texture(get_name("enem2", data));
  pac.gm.inlog = load_texture(get_name("inlog", data));
  pac.gm.perso = load_texture(get_name("perso", data));
  pac.gm.enem1 = load_texture(get_name("enem1", data));
  pac.gm.back = load_texture(get_name("back_escalier", data));
  pac.gm.back2 =load_texture(get_name("back_escalier", data));
  pac.gm.log = load_texture(get_name("log", data));
  pac.gm.flou = load_texture(get_name("flou", data));
  pac.gm.font = sfFont_createFromFile("florian/src/police.ttf");
  sfSprite_setPosition(pac.gm.log, placepos(1420, 0));
  sfSprite_setPosition(pac.gm.enem2, placepos(rand() % 1420, -220));
  sfSprite_setScale(pac.gm.inlog, placepos(0.8, 1));
  pac.gm.speed = 10;
  pac.gm.back_pos = placepos(0, 0);
  pac.gm.back_pos2 = placepos(0, -2500);
  sfSprite_setPosition(pac.gm.back, pac.gm.back_pos);
  sfSprite_setPosition(pac.gm.back2, pac.gm.back_pos2);
  pac.done = 0;
  return (pac);
}

la_struct	init_music(la_struct struc, t_data *data)
{
  struc.mu_menu = sfMusic_createFromFile("florian/src/menu.ogg");
  struc.gm.daru = sfMusic_createFromFile("florian/src/daru.ogg");
  struc.gm.pitch = 1;
  struc.cor.door = load_texture(get_name("door", data));
  struc.cor.back = load_texture(get_name("back", data));
  struc.cor.up = load_texture(get_name("up", data));
  struc.cor.Dr = load_texture(get_name("Dr", data));
  struc.cor.Ga = load_texture(get_name("Ga", data));
  struc.cor.door2 = load_texture(get_name("door2", data));
  struc.cor.door3 = load_texture(get_name("door3", data));
  sfSprite_setRotation(struc.cor.Ga, 180);
  sfSprite_setScale(struc.cor.Ga, placepos(0.2, 0.2));
  sfSprite_setScale(struc.cor.Dr, placepos(0.2, 0.2));
  sfSprite_setPosition(struc.cor.Ga, placepos(100, 500));
  sfSprite_setPosition(struc.cor.Dr, placepos(1800, 400));
  sfSprite_setScale(struc.cor.up, placepos(0.2, 0.2));
  sfSprite_setPosition(struc.cor.up, placepos(885, 400));
  struc.cor.door_find = 0;
  struc.cor.door1_pos = placepos(2500, 245);
  struc.cor.door2_pos = placepos(1000, 245);
  struc.cor.door3_pos = placepos(3500, 245);
  struc.elev.door1_pos = placepos(4500, 245);
  struc.elev.door2_pos = placepos(4700, 245);
  struc.cor.cor_pos = placepos(0, 0);
  struc.cor.para_pos = placepos(0, 0);
  struc = init_shot(struc, data);
  return (struc);
}

la_struct	init_texture3(la_struct pac, t_data *data)
{
  pac.six.on1 = load_texture(get_name("on1", data));
  pac.six.on2 = load_texture(get_name("on2", data));
  pac.six.on3 = load_texture(get_name("on3", data));
  pac.six.off1 = load_texture(get_name("off1", data));
  pac.six.off2 = load_texture(get_name("off2", data));
  pac.six.off3 = load_texture(get_name("off3", data));
  pac.six.anu1 = load_texture(get_name("anu1", data));
  pac.six.anu2 = load_texture(get_name("anu2", data));
  pac.six.anu3 = load_texture(get_name("anu3", data));
  pac.my_ox = LdTxt("Appuies sur E pour interagir\navec les symboles et cliques sur \nles zones pour te deplacer", "./guillaume/yes.ttf");
  sfSprite_setScale(pac.six.on1, placepos(0.5, 0.5));
  sfSprite_setScale(pac.six.on2, placepos(0.5, 0.5));
  sfSprite_setScale(pac.six.on3, placepos(0.5, 0.5));
  sfSprite_setScale(pac.six.off1, placepos(0.5, 0.5));
  sfSprite_setScale(pac.six.off2, placepos(0.5, 0.5));
  sfSprite_setScale(pac.six.off3, placepos(0.5, 0.5));
  sfSprite_setScale(pac.six.anu1, placepos(0.5, 0.5));
  sfSprite_setScale(pac.six.anu2, placepos(0.5, 0.5));
  sfSprite_setScale(pac.six.anu3, placepos(0.5, 0.5));
  pac.ddone = 0;
  return (pac);
}
