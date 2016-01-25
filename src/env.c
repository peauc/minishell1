/*
** env.c for env in /home/peau_c/rendu/PSU/minishell/PSU_2015_minishell1
**
** Made by Clement Peau
** Login   <peau_c@epitech.net>
**
** Started on  Tue Jan 19 00:41:39 2016 Clement Peau
** Last update Tue Jan 19 12:06:07 2016 Clement Peau
*/

#include "minishell.h"

void	my_env(t_data *data)
{
  showtab(data->envcpy);
}
