/*
** begin.c for begin in /home/coodie_d/rendu/test/B2/Allum-1
** 
** Made by Dylan Coodien
** Login   <coodie_d@epitech.net>
** 
** Started on  Tue Feb 10 15:09:47 2015 Dylan Coodien
** Last update Sun Feb 22 18:35:02 2015 Dylan Coodien
*/

#include <unistd.h>
#include <stdlib.h>
#include "my.h"
#include "alum1.h"

int		begin_game(void)
{
  t_list	*list;

  my_putstr(OPTION);
  if ((list = malloc(sizeof(*list))) == NULL)
    return (1);
  list->next = list;
  list->prev = list;
  my_put_in_list(list);
  list->num = list->prev->num;
  my_show_list(list, list->num);
  action(list);
  return (0);
}
