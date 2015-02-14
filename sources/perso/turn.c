/*
** turn.c for turn in /home/coodie_d/rendu/test/B2/2allum1
** 
** Made by Dylan Coodien
** Login   <coodie_d@epitech.net>
** 
** Started on  Sat Feb 14 17:47:24 2015 Dylan Coodien
** Last update Sat Feb 14 22:23:56 2015 Dylan Coodien
*/

#include <stdlib.h>
#include <unistd.h>
#include "my.h"
#include "alum1.h"
#include "perso.h"

int		after_turn(t_vars *vars)
{
  int		n;
  char		buff[SIZE];

  if ((my_strcmp(vars->buffer, EXIT)) == 0)
    return (0);
  my_putstr(TRY);
  buff[0] = '\0';
  while (((my_strcmp(buff, YES)) != 0) && ((my_strcmp(buff, NO)) != 0))
    {
      my_putstr(CHOOSE);
      if ((n = read(0, buff, SIZE - 1)) == -1)
	return (-1);
      buff[n] = '\0';
    }
  if ((my_strcmp(buff, YES)) == 0)
    perso();
  return (0);
}

int		turn(t_list *list, t_info *info)
{
  t_vars	*vars;

  if ((vars = init()) == NULL)
    return (1);
  while (((my_strcmp(vars->buffer, GU)) != 0) &&
	 ((my_strcmp(vars->buffer, EXIT)) != 0))
    {
      if (info->first == 1)
	{
	  IA_turn(list, info, vars);
	  info->first = 0;
	}
      if ((players_turn(list, vars)) != 0)
	return (1);
      if (((my_strcmp(vars->buffer, GU)) != 0) &&
	  ((my_strcmp(vars->buffer, EXIT)) != 0))
	IA_turn(list, info, vars);
    }
  return (after_turn(vars));
}
