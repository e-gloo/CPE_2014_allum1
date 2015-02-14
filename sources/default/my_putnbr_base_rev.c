/*
** my_putnbr_base_rev.c for my_putnbr_base_rev in /home/coodie_d/rendu/test/B2/Allum-1
** 
** Made by Dylan Coodien
** Login   <coodie_d@epitech.net>
** 
** Started on  Sat Feb  7 18:10:54 2015 Dylan Coodien
** Last update Fri Feb 13 15:46:20 2015 Dylan Coodien
*/

#include "my.h"
#include "alum1.h"

int		my_putnbr_base_rev_i(int nb, char *base, int i)
{
  int		base_len;
  static int	n;

  if (i != 1)
    n = 0;
  n++;
  base_len = my_strlen(base);
  if (nb >= base_len)
    my_putnbr_base_rev_i(nb / base_len, base, 1);
  return (n);
}
