/*
** personalize.c for personalize in /home/coodie_d/rendu/test/B2/2allum1
** 
** Made by Dylan Coodien
** Login   <coodie_d@epitech.net>
** 
** Started on  Fri Feb 13 14:47:04 2015 Dylan Coodien
** Last update Sat Feb 21 11:58:53 2015 Dylan Coodien
*/

#include <stdlib.h>
#include "my.h"
#include "perso.h"
#include "alum1.h"

int		perso(void)
{
  t_list	*list;
  t_info	*info;

  if ((info = malloc(sizeof(*info))) == NULL)
    return (1);
  if ((list = malloc(sizeof(*list))) == NULL)
    return (1);
  list->next = list;
  list->prev = list;
  if (choose_display(info, list) != 0)
    return (0);
  my_show_list(list, list->num);
  if (choose_mode(info) != 0)
    return (0);
  if (choose_first(info, list) != 0)
    return (1);
  my_show_list(list, list->num);
  turn(list, info);
  if (info != NULL)
    free(info);
  return (1);
}
