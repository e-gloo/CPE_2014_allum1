/*
** players.c for players in /home/coodie_d/rendu/test/B2/2allum1
** 
** Made by Dylan Coodien
** Login   <coodie_d@epitech.net>
** 
** Started on  Sat Feb 14 17:37:11 2015 Dylan Coodien
** Last update Sat Feb 14 23:01:08 2015 Dylan Coodien
*/

#include <unistd.h>
#include "my.h"
#include "alum1.h"
#include "perso.h"

int		verif_buffer(t_vars *vars, t_list *list)
{
  if (vars->tab[1] == NULL || vars->tab[2] != NULL)
    {
      my_puterror(NUM);
      return (1);
    }
  if (((vars->row = my_get_nbr(vars->tab[0])) <= 0) ||
      ((vars->row > list->prev->row)))
    {
      my_puterror(VALIDE);
      return (1);
    }
  if ((vars->num = my_get_nbr(vars->tab[1])) <= 0)
    {
      my_puterror(MATCH);
      return (1);
    }
  return (0);
}

int		apply_move(t_list *list, t_vars *vars)
{
  t_list	*tmp;

  tmp = list->next;
  while ((tmp != list) && (vars->row != tmp->row))
    tmp = tmp->next;
  if ((tmp->num - vars->num) < 0)
    {
      my_puterror(MANY);
      tmp = list->next;
    }
  else
    {
      tmp->num = tmp->num - vars->num;
      tmp = list;
    }
  if (check_game(list, vars) == 0)
    my_putstr(LOST);
  else
    my_show_list(list);
  return (0);
}

int		players_turn(t_list *list, t_vars *vars)
{
  int		n;

  while (42)
    {
      my_putstr(TURN);
      if ((n = read(0, vars->buffer, SIZE - 1)) == -1)
	return (-1);
      if (n == SIZE - 1 && ((my_puterror(BUG)) == 0))
	return (1);
      vars->buffer[n] = '\0';
      if (((my_strcmp(vars->buffer, GU)) == 0) ||
	  ((my_strcmp(vars->buffer, EXIT)) == 0) ||
	  ((my_strcmp(vars->buffer, TIPS)) == 0))
	return (0);
      else if (((my_strcmp(vars->buffer, GU)) != 0) &&
	       ((my_strcmp(vars->buffer, EXIT)) != 0))
	{
	  if ((vars->tab = my_str_to_word_tab(vars->buffer)) == NULL)
	    return (-1);
	  if (verif_buffer(vars, list) == 0)
	    return (apply_move(list, vars));
	  my_free(vars->tab);
	}
    }
  return (0);
}
