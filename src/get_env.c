/*
** get_env.c for getenv in /home/peau_c/rendu/PSU/minishell/PSU_2015_minishell1
**
** Made by
** Login   <peau_c@epitech.net>
**
** Started on  Thu Jan  7 16:32:20 2016
** Last update Sun Jan 24 22:34:25 2016 Clement Peau
*/

#include "../inc/minishell.h"

char	**get_env(char **env)
{
  char	**tmp;
  int	i;

  if ((tmp = malloc((my_arrlen(env) + 1) * sizeof(char *))) == NULL)
    exit(-1);
  i = -1;
  while (env[++i] != NULL)
    {
      if ((tmp[i] = malloc(my_strlen(env[i]) + 1)) == NULL)
	exit(-1);
      my_strcpy(tmp[i], env[i]);
    }
  tmp[i] = NULL;
  return (tmp);
}
