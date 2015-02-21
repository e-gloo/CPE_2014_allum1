/*
** algo.c for algo in /home/coodie_d/rendu/test/B2/Allum-1
** 
** Made by Dylan Coodien
** Login   <coodie_d@epitech.net>
** 
** Started on  Sat Feb  7 17:44:08 2015 Dylan Coodien
** Last update Fri Feb 20 10:07:11 2015 Dylan Coodien
*/

#include <stdlib.h>
#include <stdio.h>
#include "my.h"
#include "alum1.h"

int		check_longer(t_list *list)
{
  t_list	*tmp;
  int		i;
  int		len;

  tmp = list->next;
  i = 0;
  len = 0;
  while (tmp != list)
    {
      i = my_putnbr_base_rev_i(tmp->num, BASE, 0);
      if (i > len)
	len = i;
      tmp = tmp->next;
    }
  return (len);
}

int		turn_in(t_list *list, t_algo *al)
{
  t_list	*tmp;

  while (al->n <= (al->len - 1))
    {
      al->count = 0;
      tmp = list->next;
      while (tmp != list)
	{
	  if (((tmp->num & my_power_it(2, al->n))
	       / (my_power_it(2, al->n))) == 1)
	    al->count++;
	  tmp = tmp->next;
	}
      if (al->len == 1 && ((al->count % 2) == 1))
	return (0);
      else if (al->n == (al->len - 1) &&
	       ((al->count % 2) == 0) && al->len > 1)
	return (0);
      else if (((al->count % 2) == 1))
	return (-1);
      al->n++;
    }
  return (-1);
}

int		marienbad(t_list *list, t_algo *al)
{
  t_list	*tmp;

  tmp = list->next;
  while (tmp != list)
    {
      tmp->save = tmp->num;
      tmp->num = 0;
      while (tmp->num != tmp->save)
	{
	  al->n = 0;
	  al->len = check_longer(list);
	  if ((turn_in(list, al)) == 0)
	    {
	      display_IA_move(tmp);
	      return (0);
	    }
	  tmp->num++;
	}
      tmp = tmp->next;
    }
  return (-1);
}

char		*algo(t_list *list, t_vars *vars)
{
  t_algo	*al;

  if ((al = malloc(sizeof(*al))) == NULL)
    return (NULL);
  marienbad(list, al);
  if (al != NULL)
    free(al);
  if (check_game(list, vars) != 0)
    my_show_list(list, list->num);
  return (NULL);
}
