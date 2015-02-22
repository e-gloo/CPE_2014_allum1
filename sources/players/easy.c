/*
** easy.c for easy in /home/coodie_d/rendu/test/B2/2allum1
** 
** Made by Dylan Coodien
** Login   <coodie_d@epitech.net>
** 
** Started on  Sat Feb 14 19:36:09 2015 Dylan Coodien
** Last update Sun Feb 22 18:20:02 2015 Dylan Coodien
*/

#include <time.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "my.h"
#include "alum1.h"
#include "perso.h"

int		last_match(t_list *list)
{
  int		check;
  int		row;
  t_list	*tmp;

  tmp = list->next;
  check = 0;
  while (tmp != list)
    {
      if (tmp->num == 1)
	{
	  check++;
	  row = tmp->row;
	}
      tmp = tmp->next;
    }
  if (check == 1)
    {
      tmp = list->next;
      while (tmp->row != row)
	tmp = tmp->next;
      tmp->save = tmp->num;
      tmp->num = 0;
      display_IA_move(tmp);
      return (0);
    }
  return (1);
}

int		part2(t_list *list)
{
  t_list	*tmp;

  tmp = list->next;
  while (tmp != list && tmp->num == 0)
    tmp = tmp->next;
  tmp->save = tmp->num;
  if (tmp != list && tmp->num == 1)
    tmp->num = tmp->num - 1;
  else if (tmp != list)
    tmp->num = tmp->num - tmp->num + 1;
  display_IA_move(tmp);
  return (0);
}

int		easy(t_list *list, t_info *info, t_algo *al, t_vars *vars)
{
  if (info->tips == 1)
    return (hard(list, al, info, vars));
  if (last_match(list) != 0)
    part2(list);
  if (check_game(list, vars) == 0)
    {
      my_putstr(WON);
      return (-1);
    }
  my_show_list(list, list->num);
  return (0);
}
