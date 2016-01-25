/*
** exit.c for exit in /home/peau_c/rendu/PSU/minishell/PSU_2015_minishell1
**
** Made by Clement Peau
** Login   <peau_c@epitech.net>
**
** Started on  Tue Jan 19 00:34:14 2016 Clement Peau
** Last update Sun Jan 24 17:06:08 2016 Clement Peau
*/

#include "minishell.h"

int	is_legit(char *str)
{
  int	i;

  i = -1;
  while (str[++i] != 0)
    if (str[i] > '0' && str[i] < '9')
      return (1);
  return (0);
}

void	my_exit(t_data *data)
{

  if (data->args[1] != NULL)
    {
      if (is_legit(data->args[1]) == 1)
	exit(getnbr(data->args[1]));
      else
	{
	  write(2, "exit: Expression Syntax.\n", 25);
	  return ;
	}
    }
  exit(0);
}
