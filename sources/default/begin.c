/*
** begin.c for begin in /home/coodie_d/rendu/test/B2/Allum-1
** 
** Made by Dylan Coodien
** Login   <coodie_d@epitech.net>
** 
** Started on  Tue Feb 10 15:09:47 2015 Dylan Coodien
** Last update Fri Feb 13 15:45:50 2015 Dylan Coodien
*/

#include <unistd.h>
#include <stdlib.h>
#include "my.h"
#include "alum1.h"

int		try_again(void)
{
  int		n;
  char		buff[SIZE];

  my_putstr(TRY);
  buff[0] = '\0';
  while (((my_strcmp(buff, YES)) != 0) && ((my_strcmp(buff, NO)) != 0))
    {
      my_putstr(CHOOSE);
      if ((n = read(0, buff, SIZE - 1)) == -1)
	return (-1);
      buff[n] = '\0';
    }
  if ((my_strcmp(buff, YES)) == 0)
    begin_game();
  return (0);
}

int		begin_game(void)
{
  t_list	*list;

  if ((list = malloc(sizeof(*list))) == NULL)
    return (1);
  list->next = list;
  list->prev = list;
  my_put_in_list(list);
  my_show_list(list);
  action(list);
  free_list(list);
  try_again();
  return (0);
}
