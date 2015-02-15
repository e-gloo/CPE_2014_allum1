/*
** choose_first.c for choose_first in /home/coodie_d/rendu/test/B2/2allum1
** 
** Made by Dylan Coodien
** Login   <coodie_d@epitech.net>
** 
** Started on  Sat Feb 14 14:46:27 2015 Dylan Coodien
** Last update Sun Feb 15 16:10:45 2015 Dylan Coodien
*/

#include <unistd.h>
#include "my.h"
#include "perso.h"

int	first_player(t_info *info, t_list *list)
{
  int	n;
  char	buff[SIZE];

  my_putstr(FIRST);
  buff[0] = '\0';
  while (((my_strcmp(buff, ONE)) != 0) &&
	 ((my_strcmp(buff, TWO)) != 0))
    {
      my_putstr(PLAYER);
      if ((n = read(0, buff, SIZE - 1)) == -1)
	return (-1);
      buff[n] = '\0';
    }
  if ((my_strcmp(buff, ONE)) == 0)
    info->first = 0;
  else
    info->first = 1;
  return (one_versus_one(list, info));
}

int	who(t_info *info)
{
  int	n;
  char	buff[SIZE];

  my_putstr(WHO);
  buff[0] = '\0';
  while (((my_strcmp(buff, ME)) != 0) &&
	 ((my_strcmp(buff, IA)) != 0))
    {
      my_putstr(IAORME);
      if ((n = read(0, buff, SIZE - 1)) == -1)
	return (-1);
      buff[n] = '\0';
    }
  if ((my_strcmp(buff, ME)) == 0)
    info->first = 0;
  else
    info->first = 1;
  return (0);
}

int	choose_first(t_info *info, t_list *list)
{
  if (info->mode == 1)
    return (first_player(info, list));
  else
    return (who(info));
  return (0);
}
