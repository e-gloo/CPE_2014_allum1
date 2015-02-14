/*
** IA_turn.c for IA_turn in /home/coodie_d/rendu/test/B2/2allum1
** 
** Made by Dylan Coodien
** Login   <coodie_d@epitech.net>
** 
** Started on  Sat Feb 14 19:02:50 2015 Dylan Coodien
** Last update Sat Feb 14 21:45:32 2015 Dylan Coodien
*/

#include <stdlib.h>
#include "my.h"
#include "alum1.h"
#include "perso.h"

int		IA_turn(t_list *list, t_info *info, t_vars *vars)
{
  t_algo	*al;

  if ((al = malloc(sizeof(*al))) == NULL)
    return (-1);
  if ((my_strcmp(vars->buffer, TIPS)) == 0)
    info->tips = 1;
  else
    info->tips = 0;
  if (info->level == 0)
    easy(list, info, al, vars);
  else
    hard(list, al, info, vars);
  return (0);
}
