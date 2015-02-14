/*
** my_revstr.c for my_revstr in /home/coodie_d/rendu/test/B2/Allum-1
** 
** Made by Dylan Coodien
** Login   <coodie_d@epitech.net>
** 
** Started on  Sun Feb  8 16:19:51 2015 Dylan Coodien
** Last update Fri Feb 13 15:44:40 2015 Dylan Coodien
*/

#include "my.h"

void	my_revstr(char *str)
{
  int	i;
  int	n;
  char	x;

  i = 0;
  n = 0;
  while (str[i])
    i++;
  i--;
  while (i > n)
    {
      x = str[n];
      str[n] = str[i];
      str[i] = x;
      i--;
      n++;
    }
}
