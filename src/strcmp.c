/*
** strcmp.c for str in /home/peau_c/rendu/PSU/minishell/PSU_2015_minishell1
**
** Made by
** Login   <peau_c@epitech.net>
**
** Started on  Fri Jan  8 14:42:21 2016
** Last update Thu Jan 21 19:34:16 2016 Clement Peau
*/

#include "minishell.h"

int	my_strcmp(char *str, char *cmp)
{
  int	i;
  int	j;

  j = my_strlen(cmp);
  i = -1;
  while (str[++i] != 0)
    {
      if (str[i] != cmp[i])
	return (0);
    }
  if (i == j)
    return (1);
  return (0);
}
