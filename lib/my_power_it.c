/*
** my_power_it.c for my_power_it.c in /home/coodie_d
** 
** Made by dylan coodien
** Login   <coodie_d@epitech.net>
** 
** Started on  Wed Oct  8 19:16:59 2014 dylan coodien
** Last update Fri Feb 13 15:44:08 2015 Dylan Coodien
*/

#include "my.h"

int	my_power_it(int nb, int power)
{
  int	n;

  n = nb;
  if (power == 0)
    nb = 1;
  while (power > 1)
    {
      nb = nb * n;
      power = power - 1;
    }
  return (nb);
}
