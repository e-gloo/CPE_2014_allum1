/*
** check_arguments.c for check_arguments in /home/coodie_d/rendu/test/B2/2allum1
** 
** Made by Dylan Coodien
** Login   <coodie_d@epitech.net>
** 
** Started on  Fri Feb 13 14:36:11 2015 Dylan Coodien
** Last update Sat Feb 14 14:02:57 2015 Dylan Coodien
*/

#include <stdlib.h>
#include "my.h"
#include "alum1.h"

char		**opt(void)
{
  char		**tab;

  if ((tab = malloc(sizeof(char *) * 6)) == NULL)
    return (NULL);
  tab[0] = "--help";
  tab[1] = "-h";
  tab[2] = "--personalize";
  tab[3] = "-p";
  tab[4] = "--term";
  tab[5] = "-t";
  return (tab);
}

int		check_arg(int ac, char **av)
{
  int		(*fptr[6])();
  char		**tab;
  int		i;
  int		n;

  fptr[0] = (&help);
  fptr[1] = (&help);
  fptr[2] = (&perso);
  fptr[3] = (&perso);
  fptr[4] = (&term);
  fptr[5] = (&term);
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
