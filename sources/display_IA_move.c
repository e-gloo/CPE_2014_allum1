/*
** display_IA_move.c for display_IA_move in /home/coodie_d/rendu/test/B2/2allum1
** 
** Made by Dylan Coodien
** Login   <coodie_d@epitech.net>
** 
** Started on  Sun Feb 15 15:21:13 2015 Dylan Coodien
** Last update Tue Feb 17 11:36:16 2015 Dylan Coodien
*/

#include "my.h"
#include "alum1.h"
#include "perso.h"

void	display_IA_move(t_list *tmp)
{
  my_putstr("\nIA takes ");
  if (tmp->save - tmp->num > 0)
    my_put_nbr(tmp->save - tmp->num);
  else
    my_put_nbr(tmp->save);
  my_putstr(" match(es) in row ");
  my_put_nbr(tmp->row);
  my_putstr("\n");
}
