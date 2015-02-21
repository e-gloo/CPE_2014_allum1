/*
** check_arguments.c for check_arguments in /home/coodie_d/rendu/test/B2/2allum1
** 
** Made by Dylan Coodien
** Login   <coodie_d@epitech.net>
** 
** Started on  Fri Feb 13 14:36:11 2015 Dylan Coodien
** Last update Sat Feb 21 11:51:36 2015 Dylan Coodien
*/

#include <stdlib.h>
#include "my.h"
#include "alum1.h"

char		**opt(void)
{
  char		**tab;

  if ((tab = malloc(sizeof(char *) *4)) == NULL)
    return (NULL);
  tab[0] = "--help";
  tab[1] = "-h";
  tab[2] = "--personalize";
  tab[3] = "-p";
  return (tab);
}

int		check_arg(int ac, char **av)
{
  int		(*fptr[4])();
  char		**tab;
  int		i;
  int		n;

  fptr[0] = (&help);
  fptr[1] = (&help);
  fptr[2] = (&perso);
  fptr[3] = (&perso);
  if ((tab = opt()) == NULL)
    return (ac);
  i = 0;
  while (tab[i] != NULL && (my_strcmp(av[1], tab[i]) != 0))
    i++;
  if (tab[i] != NULL)
    n = (fptr[i])();
  if (tab != NULL)
    free(tab);
  return (n);
}
