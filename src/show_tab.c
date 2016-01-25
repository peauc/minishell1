/*
** show_tab.c for showtab in /home/peau_c/rendu/PSU/minishell/PSU_2015_minishell1
**
** Made by Clement Peau
** Login   <peau_c@epitech.net>
**
** Started on  Mon Jan 18 23:42:20 2016 Clement Peau
** Last update Fri Jan 22 02:09:31 2016 Clement Peau
*/

#include "minishell.h"

void	showtab(char **str)
{
  int	i;

  i = -1;
  while (str[++i] != NULL)
    {
      write(1, str[i], my_strlen(str[i]));
      write(1, "\n", 1);
    }

}
