/*
** my_putchar.c for my_putchar in /home/coodie_d/rendu/test/B2/Allum-1
** 
** Made by Dylan Coodien
** Login   <coodie_d@epitech.net>
** 
** Started on  Sat Feb  7 21:11:14 2015 Dylan Coodien
** Last update Fri Feb 13 15:44:16 2015 Dylan Coodien
*/

#include <unistd.h>
#include "my.h"

void	my_putchar(char c)
{
  write(1, &c, 1);
}
