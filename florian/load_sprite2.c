/*
** load_sprite2.c for  in /home/Neo/Graphical/tekadventure/florian
** 
** Made by Florian BORD
** Login   <Neo@epitech.net>
** 
** Started on  Tue May  2 16:15:44 2017 Florian BORD
** Last update Sun May 28 15:19:19 2017 Florian BORD
*/

#include "../all.h"

la_struct       init_shot(la_struct pac, t_data *data)
{
  pac.shot.done = 0;
  pac.shot.back_font = sfImage_create(1920, 1080);
  pac.shot.back_font = sfImage_createFromFile("florian/src/shot/back_font.png");
  pac.shot.back = load_texture(get_name("back_shot", data));
  pac.shot.perso = load_texture(get_name("perso", data));
  pac.shot.down = load_texture(get_name("down", data));
  pac.shot.perso = get_perso(pac.shot.perso);
  sfSprite_setOrigin(pac.shot.perso, placepos(16, 42));
  pac.shot.taille.x = 10;
  pac.shot.taille.y = 10;
  pac.shot.ppos = placepos(LARG / 2, 1080);
  sfSprite_setPosition(pac.shot.perso, placepos(0, 0));
  sfSprite_setScale(pac.shot.perso, pac.shot.taille);
  sfSprite_setPosition(pac.shot.down, placepos(985, 1020));
  sfSprite_setScale(pac.shot.down, placepos(0.2, 0.2));
  sfSprite_setRotation(pac.shot.down, 180);
  pac.shot.where = 2;
  pac.cor.hub_find = 1;
  pac = init_texture3(pac, data);
  pac = init_shot2(pac, data);
  return (pac);
}

la_struct	init_shot2(la_struct pac, t_data *data)
{
  pac.six.stat_1 = 0;
  pac.six.stat_2 = 0;
  pac.six.stat_3 = 0;
  pac.six.s_1 = placepos(50, 480);
  pac.six.s_2 = placepos(1000, 420);
  pac.six.s_3 = placepos(1600, 400);
  sfSprite_setPosition(pac.six.on1, pac.six.s_1);
  sfSprite_setPosition(pac.six.on2, pac.six.s_2);
  sfSprite_setPosition(pac.six.on3, pac.six.s_3);
  sfSprite_setPosition(pac.six.off1, pac.six.s_1);
  sfSprite_setPosition(pac.six.off2, pac.six.s_2);
  sfSprite_setPosition(pac.six.off3, pac.six.s_3);
  sfSprite_setPosition(pac.six.anu1, pac.six.s_1);
  sfSprite_setPosition(pac.six.anu2, pac.six.s_2);
  sfSprite_setPosition(pac.six.anu3, pac.six.s_3);
  pac.cor.check = load_texture(get_name("check", data));
  sfSprite_setScale(pac.cor.check, placepos(0.5, 0.5));
  pac.hud.pc = load_texture(get_name("pc", data));
  pac.hud.cle = load_texture(get_name("cle", data));
  pac.hud.cle2 = load_texture(get_name("cle2", data));
  sfSprite_setPosition(pac.hud.pc, placepos(200, 0));
  pac = init_elevator(pac, data);
  pac.cor.noir = load_texture(get_name("noir", data));
  pac.cor.noirpos = placepos(4500, 245);
  return (pac);
}

la_struct	init_elevator(la_struct pac, t_data *data)
{
  pac.elev.door1 = load_texture(get_name("elevadoor1", data));
  pac.elev.door2 = load_texture(get_name("elevadoor2", data));
  pac.sound.gmover = sfMusic_createFromFile("florian/src/sound/gameover.ogg");
  pac.sound.menu = sfMusic_createFromFile("florian/src/sound/menu.ogg");
  pac.sound.door = sfMusic_createFromFile("florian/src/sound/door.ogg");
  pac.sound.corridor = sfMusic_createFromFile("florian/src/sound/corridor.ogg");
  pac.sound.walk = sfMusic_createFromFile("florian/src/sound/walk.ogg");
  sfMusic_setLoop(pac.sound.walk, sfTrue);
  sfMusic_setLoop(pac.sound.corridor, sfTrue);
  pac.cred.ttf = sfFont_createFromFile("florian/src/credit/jedi.ttf");
  pac.cred.back = load_texture(get_name("back_credit", data));
  pac.cred.fpos = placepos(600, 1100);
  pac.cred.gpos = placepos(500, 1300);
  pac.cred.lpos = placepos(680, 1500);
  pac.cred.hpos = placepos(600, 1700);
  pac.cred.L = 1;
  pac.cred.l = 1;
  sfSprite_setPosition(pac.gm.go, placepos(300, 400));
  return (pac);
}

sfSprite        *get_perso(sfSprite *sprite)
{
  sfIntRect             box;

  box.left = 0;
  box.top = 0;
  box.width = 32;
  box.height = 42;
  sfSprite_setTextureRect(sprite, box);
  return (sprite);
}
