/*
** my_put_nbr.c for my_put_nbr in /home/coodie_d/rendu/test/B2/Allum-1
** 
** Made by Dylan Coodien
** Login   <coodie_d@epitech.net>
** 
** Started on  Sun Feb  8 15:48:27 2015 Dylan Coodien
** Last update Fri Feb 13 15:44:22 2015 Dylan Coodien
*/

#include "my.h"

void	my_put_nbr(int nb)
{
  int	i;

  i = 1;
  if (nb < 0)
    my_putchar('-');
  else
    nb = -nb;
  while ((nb / i) < -9)
    i = i * 10;
  while (i > 0)
    {
      my_putchar('0' + ((nb / i) * -1));
      nb = nb % i;
      i = i / 10;
    }
}
