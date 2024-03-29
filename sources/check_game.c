/*
** check_game.c for check_game in /home/coodie_d/rendu/test/B2/2allum1
** 
** Made by Dylan Coodien
** Login   <coodie_d@epitech.net>
** 
** Started on  Sat Feb 14 18:42:09 2015 Dylan Coodien
** Last update Sat Feb 14 21:31:56 2015 Dylan Coodien
*/

#include "my.h"
#include "alum1.h"
#include "perso.h"

int		check_game(t_list *list, t_vars *vars)
{
  t_list	*tmp;

  tmp = list->next;
  while (tmp != list && tmp->num == 0)
    tmp = tmp->next;
  if (tmp != list)
    return (1);
  change_buffer(vars);
  return (0);
}
