/*
** list_perso.c for list_perso in /home/coodie_d/rendu/test/B2/2allum1
** 
** Made by Dylan Coodien
** Login   <coodie_d@epitech.net>
** 
** Started on  Fri Feb 13 15:55:10 2015 Dylan Coodien
** Last update Fri Feb 13 17:03:15 2015 Dylan Coodien
*/

#include <stdlib.h>
#include "my.h"
#include "alum1.h"
#include "perso.h"

int		put_all_row(t_info *info, t_list *list)
{
  t_list	*elem;
  int		row;
  int		num;

  row = 1;
  num = 1;
  while (row <= info->nb_row)
    {
      if ((elem = malloc(sizeof(*elem))) == NULL)
	return (1);
      elem->num = num;
      elem->row = row;
      elem->prev = list->prev;
      elem->next = list;
      list->prev->next = elem;
      list->prev = elem;
      row++;
      num += 2;
    }
  return (0);
}

int		put_matches_in_row(t_info *info, t_list *list)
{
  t_list	*elem;

  if ((elem = malloc(sizeof(*elem))) == NULL)
    return (1);
  elem->num = info->num;
  elem->row = info->nb_row;
  elem->prev = list->prev;
  elem->next = list;
  list->prev->next = elem;
  list->prev = elem;
  return (0);
}
