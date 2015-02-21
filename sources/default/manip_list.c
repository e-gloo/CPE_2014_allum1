/*
** manip_list.c for manip_list in /home/coodie_d/rendu/C_Prog/B2/Allum1
** 
** Made by Dylan Coodien
** Login   <coodie_d@epitech.net>
** 
** Started on  Fri Feb  6 13:30:46 2015 Dylan Coodien
** Last update Thu Feb 19 18:00:27 2015 Dylan Coodien
*/

#include <stdlib.h>
#include "my.h"
#include "alum1.h"

int		my_put_in_list(t_list *list)
{
  int		i;
  int		row;
  t_list	*elem;

  i = 1;
  row = 1;
  while (row <= 4)
    {
      if ((elem = malloc(sizeof(*elem))) == NULL)
	return (0);
      elem->num = i;
      elem->row = row;
      elem->prev = list->prev;
      elem->next = list;
      list->prev->next = elem;
      list->prev = elem;
      row++;
      i += 2;
    }
  return (0);
}

void		display_info(t_list *tmp)
{
  my_put_nbr(tmp->row);
  if (tmp->row < 10)
    my_putchar(' ');
  my_putstr(" : ");
  if (tmp->num < 10)
    my_putchar(' ');
  my_put_nbr(tmp->num);
  my_putchar(' ');
}

void		my_show_list(t_list *list, int space)
{
  t_list	*tmp;
  int		num;
  int		i;

  tmp = list->next;
  my_putstr("\n");
  while (tmp != list)
    {
      num = 0;
      display_info(tmp);
      i = 0;
      while ((space != 0) && i != (((space - tmp->num) / 2) + 1))
	{
	  my_putchar(' ');
	  i++;
	}
      while (num != tmp->num)
	{
	  my_putstr("|");
	  num++;
	}
      my_putstr("\n");
      tmp = tmp->next;
    }
}
