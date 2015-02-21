/*
** hard.c for hard in /home/coodie_d/rendu/test/B2/2allum1
** 
** Made by Dylan Coodien
** Login   <coodie_d@epitech.net>
** 
** Started on  Sat Feb 14 19:12:55 2015 Dylan Coodien
** Last update Fri Feb 20 10:05:36 2015 Dylan Coodien
*/

#include "my.h"
#include "alum1.h"
#include "perso.h"

int		check_tips(t_list *list, t_list *tmp, t_info *info, t_vars *vars)
{
  if (info->tips == 1)
    {
      info->keep = tmp->num;
      tmp->num = tmp->save;
      my_putstr("\nYou can take ");
      my_put_nbr(tmp->save - info->keep);
      my_putstr(" match(es) in row ");
      my_put_nbr(tmp->row);
      my_putstr("\n");
    }
  else
    {
      display_IA_move(tmp);
      if (check_game(list, vars) == 0)
	{
	  my_putstr(WON);
	  return (-1);
	}
      my_show_list(list, list->num);
    }
  return (0);
}

int		check_bit(t_list *list, t_algo *al)
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

int		hard(t_list *list, t_algo *al, t_info *info, t_vars *vars)
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
	  if ((check_bit(list, al)) == 0)
	    return (check_tips(list, tmp, info, vars));
	  tmp->num++;
	}
      tmp = tmp->next;
    }
  if (info->tips == 1)
    my_putstr(LOOSER);
  else
    easy(list, info, al, vars);
  return (0);
}
