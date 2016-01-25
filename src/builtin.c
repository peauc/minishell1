/*
** builtin.c for builtin in /home/peau_c/rendu/PSU/minishell/PSU_2015_minishell1
**
** Made by Clement Peau
** Login   <peau_c@epitech.net>
**
** Started on  Tue Jan 19 00:17:32 2016 Clement Peau
** Last update Sun Jan 24 20:02:49 2016 Clement Peau
*/

#include "minishell.h"

int	is_builtin(t_data *data)
{
  char	*builtin[5];
  void	(*fonction[5])(t_data *);
  int	i;

  i = -1;
  builtin[0] = "exit";
  builtin[1] = "setenv";
  builtin[2] = "unsetenv";
  builtin[3] = "cd";
  builtin[4] = "env";
  fonction[0] = my_exit;
  fonction[1] = my_setenv;
  fonction[2] = my_unsetenv;
  fonction[3] = my_cd;
  fonction[4] = my_env;
  while (++i < 5)
    if (data->args[0] != NULL && my_strcmp(data->args[0], builtin[i]) == 1)
      {
	fonction[i](data);
	return (0);
      }
  return (1);
}
