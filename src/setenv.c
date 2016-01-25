/*
** setenv.c for setenv in /home/peau_c/rendu/PSU/minishell/PSU_2015_minishell1
**
** Made by Clement Peau
** Login   <peau_c@epitech.net>
**
** Started on  Tue Jan 19 00:35:06 2016 Clement Peau
** Last update Sun Jan 24 22:59:15 2016 Clement Peau
*/

#include "minishell.h"

char	*get_name(char *str)
{
  int	i;
  char	*tmp;
  int	j;

  j = -1;
  i = env_length(str);
  if ((tmp = malloc(i + 1)) == NULL)
    exit(-1);
  while (++j < i)
    tmp[j] = str[j];
  tmp[j] = 0;
  return (tmp);
}

char	**make_new(t_data *data)
{
  int	j;
  char	**tmp;

  j = -1;
  if ((tmp = malloc((arrlen(data->envcpy) + 2) * sizeof(char *))) == NULL)
    exit(-1);
  while (data->envcpy[++j] != NULL)
    {
      if ((tmp[j] = malloc(my_strlen(data->envcpy[j]))) == NULL)
	exit(-1);
      my_strcpy(tmp[j], data->envcpy[j]);
    }
  if ((tmp[j] = malloc(my_strlen(data->args[1]) + 1)) == NULL)
    exit(-1);
  my_strcpy(tmp[j], data->args[1]);
  tmp[j + 1] = NULL;
  free(data->envcpy);
  return (tmp);
}

char	*prepare_setenv(t_data *data)
{
  char	*tmp;
  int	i;

  i = 0;
  if (data->args[2] != NULL)
    i = my_strlen(data->args[2]);
  if ((tmp = malloc((my_strlen(data->args[1]) + i + 2) *
		    sizeof(char))) == NULL)
    exit(-1);
  tmp[0] = 0;
  my_strcat(tmp, data->args[1]);
  my_strcat(tmp, "=");
  if (data->args[2] != NULL)
    my_strcat(tmp, data->args[2]);
  data->args[1] = tmp;
  return (tmp);
}

void	my_setenv(t_data *data)
{
  char	*info;
  char	*env;
  int	i;

  i = 0;
  if (data->args[1] == NULL)
    {
      showtab(data->envcpy);
      return ;
    }
  prepare_setenv(data);
  info = get_name(data->args[1]);
  if  ((env = seek_env(data->envcpy, info)) != NULL)
    {
      while (my_strcmp(data->envcpy[i], env) != 1)
	i++;
      data->envcpy[i] = data->args[1];
    }
  else
    data->envcpy = make_new(data);
}
