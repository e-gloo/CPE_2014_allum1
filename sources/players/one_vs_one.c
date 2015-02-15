/*
** one_vs_one.c for one_vs_one in /home/coodie_d/rendu/test/B2/2allum1
** 
** Made by Dylan Coodien
** Login   <coodie_d@epitech.net>
** 
** Started on  Sun Feb 15 15:47:45 2015 Dylan Coodien
** Last update Sun Feb 15 16:17:02 2015 Dylan Coodien
*/

#include <stdlib.h>
#include "my.h"
#include "alum1.h"
#include "perso.h"

int		who_play_and_win(int n, int i)
{
  if (i == 0)
    {
      if ((n % 2) == 1)
	my_putstr("\nPlayer2");
      else
	my_putstr("\nPlayer1");
    }
  else
    {
      if ((n % 2) == 1)
	my_putstr("\nPLAYER2 WON !!!\n");
      else
	my_putstr("\nPLAYER1 WON !!!\n");
    }
  return (1);
}

int		one_versus_one(t_list *list, t_info *info)
{
  t_vars	*vars;
  int		n;

  n = 0;
  if ((vars = init()) == NULL)
    return (1);
  while (((my_strcmp(vars->buffer, GU)) != 0) &&
	 ((my_strcmp(vars->buffer, EXIT)) != 0))
    {
      if (info->first == 1)
	{
	  n = 1;
	  info->first = 0;
	}
      who_play_and_win(n, 0);
      if ((players_turn(list, vars)) != 0)
	return (1);
      n++;
    }
  return (who_play_and_win(n, 1));
}
