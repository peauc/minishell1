/*
** arrlen.c for arllen in /home/peau_c/rendu/PSU/minishell/PSU_2015_minishell1
**
** Made by Clement Peau
** Login   <peau_c@epitech.net>
**
** Started on  Tue Jan 19 17:36:19 2016 Clement Peau
** Last update Tue Jan 19 17:38:01 2016 Clement Peau
*/

#include "minishell.h"

int	arrlen(char **str)
{
  int	i;

  i = 0;
  while (str[++i] != NULL);
  return (i);
}
