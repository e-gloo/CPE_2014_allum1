/*
** allum1.c for allum1 in /home/coodie_d/rendu/C_Prog/B2/Allum1
** 
** Made by Dylan Coodien
** Login   <coodie_d@epitech.net>
** 
** Started on  Fri Feb  6 13:54:59 2015 Dylan Coodien
** Last update Sun Feb 15 15:29:08 2015 Dylan Coodien
*/

#include <unistd.h>
#include <stdlib.h>
#include "my.h"
#include "alum1.h"

t_vars		*init(void)
{
  t_vars	*vars;

  if ((vars = malloc(sizeof(*vars))) == NULL)
    return (NULL);
  vars->buffer[0] = '\0';
  return (vars);
}

int		action(t_list *list)
{
  t_vars	*vars;

  if ((vars = init()) == NULL)
    return (1);
  while (((my_strcmp(vars->buffer, GU)) != 0) &&
	 ((my_strcmp(vars->buffer, EXIT)) != 0))
    {
      if ((players_turn(list, vars)) != 0)
	return (1);
      algo(list, vars);
      my_free(vars->tab);
    }
  return (after_turn(vars, list));
}
