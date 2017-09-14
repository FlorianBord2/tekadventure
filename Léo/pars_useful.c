/*
** pars_useful.c for Tekadventure in /home/Poulard/delivery/tekadventure/Léo
** 
** Made by Léo Pechin
** Login   <Poulard@epitech.net>
** 
** Started on  Wed May  3 11:33:52 2017 Léo Pechin
** Last update Sat May 27 12:20:26 2017 Guillaume Barthe
*/
#include "Tek.h"

t_data		*main_liste_conf()
{
  char		*buff;
  t_data	*data;
  int		my_len;

  if ((my_len = car_y("./my.conf")) == -1)
    return (NULL);
  if (!(buff = malloc(sizeof (char) * 100000)) ||
      open_file("./my.conf", buff) == -1)
    return (NULL);
  data = init_pars(buff);
  return (data);
}

int     copy_while(char *av, char *to, int i, char c)
{
  int   k;

  k = 0;
  while (av[i] == ' ')
    i = i + 1;
  while (av[i] != c && av[i] != '\0')
    {
      to[k] = av[i];
      i = i + 1;
      k = k + 1;
    }
  to[k] = '\0';
  return (i);
}

int     open_file(char *av, char *buff)
{
  int   fd;

  if ((fd = open(av, O_RDONLY)) == -1)
    return (0);
  if (read(fd, buff, 10000) == -1)
    return (0);
  return (1);
}

int             car_y(char *path)
{
  struct stat   *s;
  int           block;

  if (!(s = malloc(sizeof (struct stat))) || (stat(path, s) == -1))
    return (-1);
  block = s->st_size;
  return (block);
}
