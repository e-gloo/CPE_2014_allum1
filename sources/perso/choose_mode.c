/*
** choose_mode.c for choose_mode in /home/coodie_d/rendu/test/B2/2allum1
** 
** Made by Dylan Coodien
** Login   <coodie_d@epitech.net>
** 
** Started on  Sat Feb 14 14:20:51 2015 Dylan Coodien
** Last update Sat Feb 14 16:37:25 2015 Dylan Coodien
*/

#include <unistd.h>
#include "my.h"
#include "perso.h"

int	choose_level(t_info *info)
{
  int	n;
  char	buff[SIZE];

  my_putstr(LEVEL);
  buff[0] = '\0';
  while (((my_strcmp(buff, EASY)) != 0) &&
	 ((my_strcmp(buff, HARD)) != 0))
    {
      my_putstr(SELECT);
      if ((n = read(0, buff, SIZE - 1)) == -1)
	return (-1);
      buff[n] = '\0';
    }
  if ((my_strcmp(buff, EASY)) == 0)
    info->level = 0;
  else
    info->level = 1;
  return (0);
}

int	choose_mode(t_info *info)
{
  int	n;
  char	buff[SIZE];

  my_putstr(MODE);
  buff[0] = '\0';
  while (((my_strcmp(buff, VSIA)) != 0) &&
	 ((my_strcmp(buff, OVO)) != 0))
    {
      my_putstr(WMODE);
      if ((n = read(0, buff, SIZE - 1)) == -1)
	return (-1);
      buff[n] = '\0';
    }
  if ((my_strcmp(buff, VSIA)) == 0)
    {
      choose_level(info);
      info->mode = 0;
    }
  else
    info->mode = 1;
  return (0);
}
