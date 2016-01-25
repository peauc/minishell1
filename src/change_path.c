/*
** change_path.c for change path in /home/peau_c/rendu/PSU/minishell/PSU_2015_minishell1
**
** Made by Clement Peau
** Login   <peau_c@epitech.net>
**
** Started on  Mon Jan 18 20:31:07 2016 Clement Peau
** Last update Sun Jan 24 22:31:20 2016 Clement Peau
*/

#include "minishell.h"

void	change_path(t_data *data)
{
  char	*str;
  int	i;

  i = 0;
  if (data->path == NULL || data->args == NULL)
      return ;
  while (data->path[i] != NULL && data->args[0] != NULL)
    {
      if ((str = malloc(my_strlen(data->args[0]) +
			my_strlen(data->path[i]) + 4)) == NULL)
	exit(-1);
      str[0] = 0;
      my_strcat(str, data->path[i]);
      my_strcat(str, "/");
      my_strcat(str, data->args[0]);
      free(data->path[i]);
      if (data->path[i] != NULL)
	data->path[i++] = str;
    }
  i = 0;
}
