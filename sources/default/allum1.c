/*
** allum1.c for allum1 in /home/coodie_d/rendu/C_Prog/B2/Allum1
** 
** Made by Dylan Coodien
** Login   <coodie_d@epitech.net>
** 
** Started on  Fri Feb  6 13:54:59 2015 Dylan Coodien
** Last update Sat Feb 14 15:06:03 2015 Dylan Coodien
*/

#include <unistd.h>
#include <stdlib.h>
#include "my.h"
#include "alum1.h"

int		check_read(t_vars *vars, t_list *list)
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

int		right_buffer(t_list *list, t_list *tmp, t_vars *vars)
{
  if (check_read(vars, list) == 1)
    return (1);
  while ((tmp != list) && (vars->row != tmp->row))
    tmp = tmp->next;
  if ((tmp != list) && ((tmp->num - vars->num) >= 0))
    {
      tmp->num = tmp->num - vars->num;
      tmp = list->next;
      vars->count = 0;
      while (tmp != list && tmp->num == 0)
	tmp = tmp->next;
      if (tmp != list)
	vars->count = 1;
      if (vars->count != 0)
	my_show_list(list);
      return (0);
    }
  my_puterror(MANY);
  return (1);
}

t_vars		*init(void)
{
  t_vars	*vars;

  if ((vars = malloc(sizeof(*vars))) == NULL)
    return (NULL);
  vars->buffer[0] = '\0';
  vars->count = 1;
  return (vars);
}

int		read_part(t_vars *vars)
{
  int		n;

  my_putstr(TURN);
  if ((n = read(0, vars->buffer, SIZE - 1)) == -1)
    return (1);
  if (n == SIZE - 1)
    {
      my_puterror("\nToo many arguments\n");
      return (1);
    }
  vars->buffer[n] = '\0';
  return (0);
}

int		action(t_list *list)
{
  t_list	*tmp;
  t_vars	*vars;

  tmp = list->next;
  if ((vars = init()) == NULL)
    return (1);
  while ((my_strcmp(vars->buffer, GU)) != 0)
    {
      if (read_part(vars) == 1)
	return (1);
      else if ((my_strcmp(vars->buffer, GU)) != 0)
	{
	  if ((vars->tab = my_str_to_word_tab(vars->buffer)) == NULL)
	    return (1);
	  if ((right_buffer(list, tmp, vars)) == 0)
	    algo(list);
	  if (vars->count == 0)
	    change_buffer(vars);
	  my_free(vars->tab);
	}
    }
  return (0);
}
