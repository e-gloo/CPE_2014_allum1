/*
** my_strlen.c for my_strlen in /home/coodie_d/rendu/test/B2/Allum-1
** 
** Made by Dylan Coodien
** Login   <coodie_d@epitech.net>
** 
** Started on  Sat Feb  7 19:00:22 2015 Dylan Coodien
** Last update Fri Feb 13 15:44:55 2015 Dylan Coodien
*/

#include "my.h"

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    i++;
  return (i);
}
