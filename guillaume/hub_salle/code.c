/*
** code.c for code.c in /home/Ordrix0/techadventure
** 
** Made by Guillaume Barthe
** Login   <Ordrix0@epitech.net>
** 
** Started on  Fri Apr 21 16:04:41 2017 Guillaume Barthe
** Last update Sat May 27 15:55:36 2017 Guillaume Barthe
*/

#include "../../all.h"

int		answer(int key, sfRenderWindow* window)
{
  if (sfKeyboard_isKeyPressed(key))
    return (-1);
  return (0);
}

void	ini_key(int i[4])
{
  i[0] = sfKeyT;
  i[1] = sfKeyR;
  i[2] = sfKeyO;
  i[3] = sfKeyL;
}

int		my_touch(sfRenderWindow* window, int u, int ans)
{
  sfEvent	event;

  if (ans == 0)
    {
      sfRenderWindow_pollEvent(window, &event);
      if (event.type == sfEvtKeyPressed)
	if (event.key.code != sfKeyT &&			      \
	    event.key.code != sfKeyR &&			      \
	    event.key.code != sfKeyO &&			      \
	    event.key.code != sfKeyL)
	  return (-1);
    }
  if (u == 4)
    return (3);
  return (0);
}

int		fct_code(t_my_all *s_all, sfRenderWindow* window, int time)
{
  int		i[4];
  int		img;
  int		ans;
  int		u;
  int		my_recup;

  u = 0;
  ini_key(i);
  if (time == 0)
    box_err(window, s_all, s_all->txt->mdp);
  ans = 0;
  img = 0;
  while (1)
    {
      ans = disp_code(s_all, window, img, i[u]);
      if (ans == -1)
	{
	  img = img + 1;
	  u = u + 1;
	}
      if ((my_recup = my_touch(window, u, ans)) != 0)
	return (my_recup);
      sfRenderWindow_display(window);
    }
}
