/*
** my_strcmp.c for my_strmcp.c in /home/coodie_d/rendu/Piscine_C_J06/ex_05
** 
** Made by dylan coodien
** Login   <coodie_d@epitech.net>
** 
** Started on  Mon Oct  6 18:28:47 2014 dylan coodien
** Last update Fri Feb 13 15:44:49 2015 Dylan Coodien
*/

#include "my.h"

int	my_strcmp(char *s1, char *s2)
{
  int	i;
  int	diff;

  i = 0;
  diff = 0;
  while (s1[i] != '\0' && s1[i] == s2[i])
    i++;
  if (s1[i] == '\0')
    return (diff = s2[i] * -1);
  if (s2[i] == '\0')
    return (diff = s1[i]);
  diff = s1[i] - s2[i];
  return (diff);
}
