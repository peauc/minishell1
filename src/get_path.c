/*
** get_path.c for getpath in /home/peau_c/rendu/PSU/minishell/PSU_2015_minishell1
**
** Made by
** Login   <peau_c@epitech.net>
**
** Started on  Wed Jan 13 14:27:25 2016
** Last update Sun Jan 24 16:14:15 2016 Clement Peau
*/

#include "minishell.h"

int	count_char(char *str, char character)
{
  int	i;
  int	count;

  count = 0;
  i = 0;
  while (str[i++] != 0)
    if (str[i] == character)
      count++;
  return (count + 1);
}

void	get_path(t_data *data)
{
  char	*str;

  str = seek_env(data->envcpy, "PATH=");
  if (str != NULL)
    data->path = my_wordtab(&str[5], ':');
}
