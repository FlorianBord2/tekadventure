/*
** text.c for  in /home/Neo/zest/menu
** 
** Made by Florian BORD
** Login   <Neo@epitech.net>
** 
** Started on  Thu Apr 20 13:29:37 2017 Florian BORD
** Last update Sun May 28 15:21:09 2017 Florian BORD
*/

#include "../all.h"

sfText		*my_text(char *str, sfFont *font, sfText *text)
{
  text = sfText_create();
  sfText_setString(text, str);
  sfText_setFont(text, font);
  sfText_setCharacterSize(text, 100);
  sfText_setColor(text, sfColor_fromRGBA(255, 255, 0, 200));
  return (text);
}

la_struct	my_prog(la_struct pac)
{
  char	*val;

  val = my_conv_char(pac.gm.prog);
  pac.gm.score = my_text(val, pac.gm.font, pac.gm.score);
  free(val);
  sfRenderWindow_drawText(pac.window, pac.gm.score, NULL);
  return (pac);
}

char             *my_conv_char(int nb)
{
  float         j;
  double        r;
  int           a;
  char          *nbr;
  int           i;

  i = 0;
  if (!(nbr = malloc(sizeof (char) * nb + 1)))
    return (NULL);
  r = nb;
  a = 0;
  if (nb > 0)
    {
      while (r >= 1)
	r = r / 10;
      while (r * 10 <= nb)
	{
	  r = r * 10;
	  a = r;
	  nbr[i] = (48 + (a % 10));
	  i++;
	}
    }
  nbr[i] = '\0';
  return (nbr);
}
