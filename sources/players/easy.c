/*
** easy.c for easy in /home/coodie_d/rendu/test/B2/2allum1
** 
** Made by Dylan Coodien
** Login   <coodie_d@epitech.net>
** 
** Started on  Sat Feb 14 19:36:09 2015 Dylan Coodien
** Last update Sat Feb 14 23:03:15 2015 Dylan Coodien
*/

#include <time.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "my.h"
#include "alum1.h"
#include "perso.h"

int		part2(t_list *list, int i, int t)
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
	  while (tmp->row != (rand() % i))
	    tmp = tmp->next;
	  if (tmp->num > 0 && ((tmp->save = tmp->num) != 0))
	    {
	      tmp->num = tmp->num - ((rand() % tmp->num) + 1);
	      my_putstr("\nIA takes ");
	      my_put_nbr(tmp->save - tmp->num);
	      my_putstr(" match(es) in row ");
	      my_put_nbr(tmp->row);
	      my_putstr("\n");
	      return (0);
	    }
	}
    }
  return (0);
}

int		easy(t_list *list, t_info *info, t_algo *al, t_vars *vars)
{
  t_list	*tmp;
  int		i;
  int		t;

  t = 0;
  if (info->tips == 1)
    return (hard(list, al, info, vars));
  i = 0;
  tmp = list->next;
  while (tmp != list)
    {
      i++;
      tmp = tmp->next;
    }
  part2(list, i, t);
  if (check_game(list, vars) == 0)
    {
      my_putstr(WON);
      return (-1);
    }
  my_show_list(list);
  return (0);
}
