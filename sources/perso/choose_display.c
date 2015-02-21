/*
** nb_row.c for nb_row in /home/coodie_d/rendu/test/B2/2allum1
** 
** Made by Dylan Coodien
** Login   <coodie_d@epitech.net>
** 
** Started on  Fri Feb 13 15:15:40 2015 Dylan Coodien
** Last update Sat Feb 21 11:58:47 2015 Dylan Coodien
*/

#include <unistd.h>
#include "alum1.h"
#include "my.h"
#include "perso.h"

int	nb_row(t_info *info, t_list *list)
{
  int	n;
  char	buff[SIZE];

  buff[0] = '\0';
  while (42)
    {
      my_putstr(ROW);
      if ((n = read(0, buff, SIZE - 1)) == -1)
	return (1);
      buff[n] = '\0';
      if (((my_get_nbr(buff)) >= 1) && ((my_get_nbr(buff) <= 25)))
	{
	  info->nb_row = my_get_nbr(buff);
	  return (put_all_row(info, list));
	}
    }
  return (0);
}

int		both(t_info *info, t_list *list)
{
  int		n;
  char		buff[SIZE];

  info->nb_row = 1;
  buff[0] = '\0';
  my_putstr(POS);
  while ((my_strcmp(buff, STOP)) != 0)
    {
      my_putstr(HM);
      my_put_nbr(info->nb_row);
      my_putstr(": ");
      if ((n = read(0, buff, SIZE - 1)) == -1)
	return (1);
      buff[n] = '\0';
      if (((my_strcmp(buff, STOP)) != 0) &&
	  (((info->num = my_get_nbr(buff)) <= 0)
	   || (info->num > 50)))
	my_puterror(POS);
      else if ((my_strcmp(buff, STOP)) != 0)
	{
	  put_matches_in_row(info, list);
	  info->nb_row++;
	}
    }
  return (0);
}

int		choose_display(t_info *info, t_list *list)
{
  int		n;
  char		buff[SIZE];

  my_putstr(ROB);
  buff[0] = '\0';
  while ((my_strcmp(buff, ONLY)) != 0 && ((my_strcmp(buff, BOTH)) != 0))
    {
      my_putstr(WHAT);
      if ((n = read(0, buff, SIZE - 1)) == -1)
	return (-1);
      buff[n] = '\0';
    }
  if ((my_strcmp(buff, BOTH)) == 0)
    {
      while ((both(info, list)) == 0 && list->next->num <= 0)
	my_puterror(AGAIN);
      list->num = 0;
      return (0);
    }
  nb_row(info, list);
  list->num = list->prev->num;
  return (0);
}
