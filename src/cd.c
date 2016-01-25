/*
** cd.c for cd in /home/peau_c/rendu/PSU/minishell/PSU_2015_minishell1
**
** Made by Clement Peau
** Login   <peau_c@epitech.net>
**
** Started on  Tue Jan 19 00:41:01 2016 Clement Peau
** Last update Sun Jan 24 22:59:27 2016 Clement Peau
*/

#include "minishell.h"

char	*check_home(t_data *data)
{
  char	*str;

  if ((str = seek_env(data->envcpy, "HOME=")) == NULL)
    return ("/");
  else
    return (str + 5);
}

char	*old_path(t_data *data)
{
  char	*str;

  if ((str = seek_env(data->envcpy, "OLDPWD=")) == NULL)
    return (NULL);
  else
    return (str + 7);
}

void	actualise(t_data *data)
{
  char	*str;
  char	*pwd;

  str = getcwd(NULL, 0);
  if ((pwd = malloc((my_strlen(seek_env(data->envcpy, "PWD=")) +
		     my_strlen("OLDPWD=") + 2) * sizeof(char))) == NULL)
    exit(-1);
    pwd[0] = 0;
  my_strcat(pwd, "OLDPWD=");
  my_strcat(pwd, seek_env(data->envcpy, "PWD=") + 4);
  data->envcpy[get_envnbr("OLDPWD=", data->envcpy)] = pwd;
  if ((pwd = malloc((my_strlen(str) + my_strlen("PWD=") + 2)
		    * sizeof(char))) == NULL)
    exit(-1);
  pwd[0] = 0;
  my_strcat(pwd, "PWD=");
  my_strcat(pwd, getcwd(NULL, 0));
  data->envcpy[get_envnbr("PWD=", data->envcpy)] = pwd;
}

void	my_cd(t_data *data)
{
  if (data->args[1] == NULL)
      chdir(check_home(data));
  else if (my_strcmp(data->args[1], "-") == 1)
    {
      if (old_path(data) != NULL)
	chdir(old_path(data));
    }
  else
    if (chdir(data->args[1]) == -1)
      {
	write(2, data->args[1], my_strlen(data->args[1]));
	write(2, ": Not a directory.\n", 20);
      }
  if (seek_env(data->envcpy, "PWD=") != NULL &&
      seek_env(data->envcpy, "OLDPWD=") != NULL)
    actualise(data);
}
