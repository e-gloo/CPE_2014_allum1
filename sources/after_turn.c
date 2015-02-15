/*
** after_turn.c for after_turn in /home/coodie_d/rendu/test/B2/2allum1
** 
** Made by Dylan Coodien
** Login   <coodie_d@epitech.net>
** 
** Started on  Sun Feb 15 14:52:07 2015 Dylan Coodien
** Last update Sun Feb 15 14:58:34 2015 Dylan Coodien
*/

#include <stdlib.h>
#include <unistd.h>
#include "my.h"
#include "alum1.h"
#include "perso.h"

int		after_turn(t_vars *vars, t_list *list)
{
  int		n;
  char		buff[SIZE];

  free_list(list);
  if ((my_strcmp(vars->buffer, EXIT)) == 0)
    {
      if (vars != NULL)
	free(vars);
      return (0);
    }
  if (vars != NULL)
    free(vars);
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
    perso();
  return (0);
}
