/*
** unsetenv.c for include in /home/peau_c/rendu/PSU/minishell/PSU_2015_
**
** Made by Clement Peau
** Login   <peau_c@epitech.net>
**
** Started on  Tue Jan 19 00:40:07 2016 Clement Peau
** Last update Sun Jan 24 22:44:32 2016 Clement Peau
*/

#include "minishell.h"

char	**unsetenv_malloc(t_data *data, char *env)
{
  int	i;
  int	j;
  char	**tmp;

  i = 0;
  j = 0;
  if ((tmp = malloc((arrlen(data->envcpy) + 2) * sizeof(char *))) == NULL)
    exit(-1);
  while (data->envcpy[++j] != NULL)
    if (my_strcmp(data->envcpy[j], env) != 1)
	{
	  if ((tmp[i] = malloc(my_strlen(data->envcpy[j]) + 1)) == NULL)
	    exit(-1);
	  my_strcpy(tmp[i++], data->envcpy[j]);
	}
  tmp[i] = NULL;
  return (tmp);
}

char	*check_equal(char *str)
{
  int	i;
  int	there;
  char	*tmp;

  i = 0;
  there = 0;
  while (str[i] != 0)
    {
      if (str[i] == '=')
	there = 1;
      i++;
    }
  if (there == 0)
    {
      if ((tmp = malloc(my_strlen(str) + 2)) == NULL)
	exit(-1);
      my_strcpy(tmp, str);
      tmp[my_strlen(str)] = '=';
      tmp[my_strlen(str) + 1] = 0;
    }
  return (tmp);
}

void	my_unsetenv(t_data *data)
{
  char	*info;
  char	*env;

  if (data->args[1] == NULL)
    return ;
  if (check_equal(data->args[1]) != NULL)
    data->args[1] = check_equal(data->args[1]);
  info = get_name(data->args[1]);
  env = seek_env(data->envcpy, info);
  if (env != NULL)
    data->envcpy = unsetenv_malloc(data, env);
}
