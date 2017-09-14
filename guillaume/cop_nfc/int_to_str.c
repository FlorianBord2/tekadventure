/*
** int_to_str.c for int_to_str.c in /home/Ordrix0/GRAPH/tekadventure/guillaume/cop_nfc
** 
** Made by Guillaume Barthe
** Login   <Ordrix0@epitech.net>
** 
** Started on  Mon May  1 14:03:42 2017 Guillaume Barthe
** Last update Sat May 27 16:49:01 2017 Guillaume Barthe
*/

#include "../../all.h"

char	*nb_to_char(int to_f)
{
  int	x;
  int	g;
  char	*nb;

  if (!(nb = malloc(sizeof (char) * to_f)))
    return (NULL);
  g = 0;
  x = 1;
  while (to_f / x  > 9)
    x = x * 10;
  while (x >= 10)
    {
      nb[g] = to_f / x + 48;
      to_f = to_f % x;
      x = x / 10;
      g = g + 1;
    }
  nb[g] = to_f + 48;
  nb[g + 1] = '\0';
  return (nb);
}
