/*
** main.c for main in /home/coodie_d/rendu/C_Prog/B2/Allum1/sources
** 
** Made by Dylan Coodien
** Login   <coodie_d@epitech.net>
** 
** Started on  Fri Feb  6 13:12:48 2015 Dylan Coodien
** Last update Fri Feb 13 15:45:30 2015 Dylan Coodien
*/

#include "my.h"
#include "alum1.h"

int		main(int ac, char **av)
{
  if (ac != 1)
    {
      if (check_arg(ac, av) == 0)
	begin_game();
    }
  else
    begin_game();
  return (0);
}
