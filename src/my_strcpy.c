/*
** my_strcpy.c for strcpy in /home/peau_c/rendu/PSU/minishell/PSU_2015_minishel
**
** Made by
** Login   <peau_c@epitech.net>
**
** Started on  Thu Jan  7 17:13:16 2016
** Last update Thu Jan  7 17:38:07 2016 
*/

#include "../inc/minishell.h"

void	my_strcpy(char *dest, char *str)
{
  int	i;

  i = -1;
  while (str[++i] != 0)
    dest[i] = str[i];
  dest[i] = 0;
}
