/*
** seek_env.c for getpath in /home/peau_c/rendu/PSU/minishell/PSU_2015_minishell1
**
** Made by
** Login   <peau_c@epitech.net>
**
** Started on  Wed Jan 13 14:27:25 2016
** Last update Sun Jan 24 20:16:42 2016 Clement Peau
*/

#include "minishell.h"

int	env_length(char *str)
{
  int	i;

  i = 0;
  while (str[i] != 0 && str[i++] != '=');
  return (i);
}

int	check_name(char *env, char *info, int length)
{
  int	i;

  i = 0;
  if (my_strlen(info) != length)
    return (0);
  while (i < length)
    {
      if (env[i] != info[i])
	return (0);
      i++;
    }
  return (1);
}

char	*seek_env(char **env, char *info)
{
  int	i;

  i = 0;
  while (env[i] != NULL)
    {
      if (check_name(env[i], info, env_length(env[i])) == 1)
      	return (env[i]);
      i++;
    }
  return (NULL);
}

int	get_envnbr(char *str, char **env)
{
  int   i;
  char  *info;

  i = 0;
  info = seek_env(env, str);
  while (env[i] != NULL && my_strcmp(env[i], info) != 1)
    i++;
  return (i);
}
