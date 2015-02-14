/*
** help.c for help in /home/coodie_d/rendu/test/B2/2allum1
** 
** Made by Dylan Coodien
** Login   <coodie_d@epitech.net>
** 
** Started on  Fri Feb 13 14:48:03 2015 Dylan Coodien
** Last update Sat Feb 14 14:42:09 2015 Dylan Coodien
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "my.h"
#include "alum1.h"

int		help()
{
  int		fd;
  int		n;
  char		buff[SIZE];

  if ((fd = open("./sources/help/help.txt", O_RDONLY)) == -1)
    return (-1);
  while ((n = read(fd, buff, SIZE - 1)) != 0)
    {
      buff[n] = '\0';
      if (write(1, buff, n) == -1)
	return (-1);
    }
  my_putstr("Here it begins\n");
  return (0);
}
