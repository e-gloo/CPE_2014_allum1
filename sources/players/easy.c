/*
** easy.c for easy in /home/coodie_d/rendu/test/B2/2allum1
** 
** Made by Dylan Coodien
** Login   <coodie_d@epitech.net>
** 
** Started on  Sat Feb 14 19:36:09 2015 Dylan Coodien
** Last update Sun Feb 15 15:22:18 2015 Dylan Coodien
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
      tmp->num = 0;
      display_IA_move(tmp);
      return (0);
    }
  return (1);
}

int		part2(t_list *list, int t)
{
  t_list	*tmp;

  tmp = list->next;
  while (42)
    {
      if ((t = time(0)) == -1)
	tmp = list->next;
      else
	{
	  srand(t * getpid());
	  while (tmp->row != (rand() % (list->prev->row + 1)))
	    tmp = tmp->next;
	  if (tmp->num > 0 && ((tmp->save = tmp->num) != 0))
	    {
	      tmp->num = tmp->num - ((rand() % tmp->num) + 1);
	      display_IA_move(tmp);
	      return (0);
	    }
	}
    }
  return (0);
}

int		easy(t_list *list, t_info *info, t_algo *al, t_vars *vars)
{
  int		t;

  t = 0;
  if (info->tips == 1)
    return (hard(list, al, info, vars));
  if (last_match(list) != 0)
    part2(list, t);
  if (check_game(list, vars) == 0)
    {
      my_putstr(WON);
      return (-1);
    }
  my_show_list(list);
  return (0);
}
