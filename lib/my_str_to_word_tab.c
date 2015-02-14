/*
** my_str_to_word_tab.c for my_str_to_word_tab in /home/coodie_d/rendu/SysUnix/PSU_2014_minishell1/sources
** 
** Made by Dylan Coodien
** Login   <coodie_d@epitech.net>
** 
** Started on  Thu Jan 29 11:29:27 2015 Dylan Coodien
** Last update Fri Feb 13 15:45:02 2015 Dylan Coodien
*/

#include <stdlib.h>
#include "my.h"

int	count_words(char *str, int *i)
{
  int	n;

  n = 0;
  if (str[*i] == '\0')
    return (0);
  while (str[*i] != '\0')
    {
      while ((str[*i] == ' ' || str[*i] == '\t') && str[*i] != '\0')
	(*i)++;
      if (str[*i] != '\0')
	{
	  n++;
	  while (str[*i] != ' ' && str[*i] != '\t' && str[*i] != '\0')
	    (*i)++;
	}
      if (str[*i] != '\0')
	(*i)++;
    }
  return (n);
}

char	**fill_word_tab(char **range, char *str, int *i, int n)
{
  int	x;
  int	size;

  size = *i;
  *i = 0;
  while (str[*i] != '\0')
    {
      x = 0;
      if ((range[n] = malloc(size + 1)) == NULL)
	return (NULL);
      while ((str[*i] == ' ' || str[*i] == '\t') && str[*i] != '\0')
	(*i)++;
      while (str[*i] != ' ' && str[*i] != '\t' && str[*i] != '\0')
	{
	  range[n][x] = str[*i];
	  (*i)++;
	  x++;
	}
      range[n][x] = '\0';
      if (x != 0)
	n++;
    }
  range[n] = NULL;
  return (range);
}

char	**my_str_to_word_tab(char *str)
{
  char	**range;
  int	i;
  int	n;

  i = 0;
  n = count_words(str, &i);
  if ((range = malloc(sizeof(char*) * (n + 1))) == NULL)
    return (NULL);
  n = 0;
  if ((range = fill_word_tab(range, str, &i, n)) == NULL)
    return (NULL);
  return (range);
}
