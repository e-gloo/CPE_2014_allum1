/*
** my_putstr.c for my_putstr.c in /home/coodie_d/rendu/Piscine_C_J04
** 
** Made by dylan coodien
** Login   <coodie_d@epitech.net>
** 
** Started on  Thu Oct  2 20:47:30 2014 dylan coodien
** Last update Fri Feb 13 15:44:30 2015 Dylan Coodien
*/

#include <unistd.h>
#include <stdlib.h>
#include "my.h"

int	my_putstr(char *str)
{
  int	i;

  i = 0;
  if (str == NULL)
    return (-1);
  while (str[i])
    i++;
  if ((write(1, str, i)) == -1)
    return (-1);
  return (i);
}

int	my_puterror(char *str)
{
  int	i;

  i = 0;
  if (str == NULL)
    return (-1);
  while (str[i])
    i++;
  if ((write(2, str, i)) == -1)
    return (-1);
  return (i);
}
