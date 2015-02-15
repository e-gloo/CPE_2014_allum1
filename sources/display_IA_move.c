/*
** display_IA_move.c for display_IA_move in /home/coodie_d/rendu/test/B2/2allum1
** 
** Made by Dylan Coodien
** Login   <coodie_d@epitech.net>
** 
** Started on  Sun Feb 15 15:21:13 2015 Dylan Coodien
** Last update Sun Feb 15 15:22:00 2015 Dylan Coodien
*/

#include "my.h"
#include "alum1.h"
#include "perso.h"

void	display_IA_move(t_list *tmp)
{
  my_putstr("\nIA takes ");
  my_put_nbr(tmp->save - tmp->num);
  my_putstr(" match(es) in row ");
  my_put_nbr(tmp->row);
  my_putstr("\n");
}
