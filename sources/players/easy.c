/*
** easy.c for easy in /home/coodie_d/rendu/test/B2/2allum1
** 
** Made by Dylan Coodien
** Login   <coodie_d@epitech.net>
** 
** Started on  Sat Feb 14 19:36:09 2015 Dylan Coodien
** Last update Sun Feb 22 21:40:00 2015 Dylan Coodien
*/

#include <time.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "my.h"
#include "alum1.h"
#include "perso.h"

int		part2(t_list *list)
{
  t_list	*tmp;
  int		len;

  len = 0;
  tmp = list->next;
  while (tmp != list)
    {
      if (tmp->num > len)
	len = tmp->num;
      tmp = tmp->next;
    }
  tmp = tmp->next;
  while (tmp != list && tmp->num != len)
    tmp = tmp->next;
  tmp->save = tmp->num;
  if (tmp != list && tmp->num > 1)
    tmp->num = tmp->num - tmp->num + 1;
  else if (tmp != list && tmp->num == 1)
    tmp->num = 0;
  display_IA_move(tmp);
  return (0);
}

int		easy(t_list *list, t_info *info, t_algo *al, t_vars *vars)
{
  if (info->tips == 1)
    return (hard(list, al, info, vars));
  part2(list);
  if (check_game(list, vars) == 0)
    {
      my_putstr(WON);
      return (-1);
    }
  my_show_list(list, list->num);
  return (0);
}
