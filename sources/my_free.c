/*
** my_free.c for my_free in /home/coodie_d/rendu/C_Prog/B2/Allum1
** 
** Made by Dylan Coodien
** Login   <coodie_d@epitech.net>
** 
** Started on  Sat Feb  7 14:04:14 2015 Dylan Coodien
** Last update Fri Feb 13 15:46:12 2015 Dylan Coodien
*/

#include <stdlib.h>
#include "my.h"
#include "alum1.h"

void		my_free(char **tab)
{
  int		i;

  i = 0;
  while (tab[i] != NULL)
    {
      if (tab[i] != NULL)
	free(tab[i]);
      i++;
    }
  if (tab != NULL)
    free(tab);
}

void		free_list(t_list *list)
{
  t_list	*tmp;

  tmp = list->next;
  while (tmp != list)
    {
      tmp = tmp->next;
      if (tmp->prev != NULL)
	free(tmp->prev);
    }
  if (list != NULL)
    free(list);
}
