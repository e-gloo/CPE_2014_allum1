/*
** my_get_nbr.c for my_get_nbr.c in /home/coodie_d/rendu/Library
** 
** Made by dylan coodien
** Login   <coodie_d@epitech.net>
** 
** Started on  Mon Oct 20 17:09:19 2014 dylan coodien
** Last update Sat Feb 14 15:15:53 2015 Dylan Coodien
*/

#include "my.h"

char    sign(char *str, int n, int *i)
{
  *i = 0;
  if (str[n] == '-' || str[n] == '+')
    {
      while (str[n] == '-' || str[n] == '+')
        {
          if (str[n] == '-')
            (*i)++;
          n = n + 1;
        }
      *i = *i % 2;
    }
  return (n);
}

int	ex(char *str, int nb, int n, int a)
{
  if (nb > 214748364)
    return (0);
  if (nb == 214748364 && a == 0)
    {
      if ((str[n] - '0') > 7 && (str[n] - '0') <= 9)
	return (0);
    }
  if (nb == 214748364 && a == 1)
    {
      if (str[n] == '8' && str[n + 1] >= '0' && str[n + 1] <= '9')
	return (0);
      if ((str[n] - '0') > 8 && (str[n] - '0') <= 9)
	return (0);
    }
  return (1);
}

int	my_get_nbr(char *str)
{
  int	n;
  int	nb;
  int	a;

  n = 0;
  nb = 0;
  while (str[n] == ' ' || str[n] == '\t')
    n++;
  if ((str[n] < '0' || str[n] > '9') && str[n] != '-' && str[n] != '+')
    return (0);
  else
    n = sign(str, n, &a);
  while (str[n] >= '0' && str[n] <= '9')
    {
      if (ex(str, nb, n, a) == 0)
	return (0);
      nb = nb * 10;
      nb = nb + (str[n] - '0');
      n = n + 1;
    }
  if (a == 1)
    nb = - nb;
  return (nb);
}
