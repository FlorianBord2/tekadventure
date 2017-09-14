/*
** Tek.h for Tekadventure in /home/Poulard/delivery/tekadventure/Léo
** 
** Made by Léo Pechin
** Login   <Poulard@epitech.net>
** 
** Started on  Wed May  3 11:30:34 2017 Léo Pechin
** Last update Sat May 27 16:45:11 2017 Guillaume Barthe
*/

#ifndef LEO_H_
#define LEO_H_

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

typedef struct s_data
{
  char *name;
  char *src;
  struct s_data *suv;
}t_data;

//pars.c
int     stock_src(t_data *data, t_data *suv, char *av, int i);
int     stock_name(t_data *data, t_data *suv, char *av, int i);
int     len_lin(char *av, int i, int opt);
int     pars(char *av, t_data *data, int i);
t_data  *init_pars(char *av);

//pars_useful.c
int     copy_while(char *av, char *to, int i, char c);
int	open_file(char *av, char *buff);
int             car_y(char *path);
t_data          *main_liste_conf();

//get_name.c
char*   get_name(char *name, t_data *d);
int     count_l(t_data *d);
int     check_it(char *name, char *av);

#endif /* LEO_H_ */
