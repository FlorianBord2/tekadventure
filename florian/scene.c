/*
** scene.c for  in /home/Neo/zest/menu
** 
** Made by Florian BORD
** Login   <Neo@epitech.net>
** 
** Started on  Wed Apr 26 11:09:23 2017 Florian BORD
** Last update Wed May 24 11:46:11 2017 Florian BORD
*/

#include "../all.h"

void    my_scene(la_struct pac)
{
  my_deg(pac);
  my_degu_scene(pac);
  my_sleep(5);
  my_deg(pac);
}

void    my_scene2(la_struct pac)
{
  my_deg(pac);
  my_degu_scene2(pac);
  my_sleep(8);
  my_deg(pac);
}
