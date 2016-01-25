/*
** my_strlen.c for strlen in /home/peau_c/rendu/PSU/shell1
**
** Made by
** Login   <peau_c@epitech.net>
**
** Started on  Thu Jan  7 16:45:50 2016
** Last update Thu Jan  7 16:59:53 2016 
*/

#include "../inc/minishell.h"

int	my_strlen(char *str)
{
  int	i;

  i = -1;
  while (str[++i] != 0);
  return (i);
}

int	my_arrlen(char	**str)
{
  int	i;

  i = -1;
  while (str[++i] != NULL);
  return (i);
}
