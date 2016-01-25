/*
** free.c for make free in /home/peau_c/rendu/PSU/minishell/PSU_2015_minishell1
**
** Made by Clement Peau
** Login   <peau_c@epitech.net>
**
** Started on  Thu Jan 21 22:39:58 2016 Clement Peau
** Last update Sun Jan 24 20:21:02 2016 Clement Peau
*/

#include "minishell.h"

void	free_args(t_data *data)
{
  int	i;

  i = -1;
  if (data->args != NULL)
    while (data->args[++i] != NULL)
      free(data->args[i]);
}

void	free_it(t_data *data)
{
  int	i;

  i = -1;
  while (data->envcpy[++i] != NULL)
    free(data->envcpy[i]);
  if (data->get_next != NULL)
    free(data->get_next);
  i = -1;
  if (data->path != NULL)
    while (data->path[++i] != NULL)
      free(data->path[i]);
}
