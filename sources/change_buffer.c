/*
** change_buffer.c for change_buffer in /home/coodie_d/rendu/test/B2/Allum-1
** 
** Made by Dylan Coodien
** Login   <coodie_d@epitech.net>
** 
** Started on  Tue Feb 10 16:18:20 2015 Dylan Coodien
** Last update Fri Feb 13 15:45:59 2015 Dylan Coodien
*/

#include "my.h"
#include "alum1.h"

void	change_buffer(t_vars *vars)
{
  int	i;

  i = 0;
  while (GU[i])
    {
      vars->buffer[i] = GU[i];
      i++;
    }
  vars->buffer[i] = '\0';
}
