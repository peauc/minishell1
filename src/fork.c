/*
** fork.c for mainfork in /home/peau_c/rendu/PSU/minishell/PSU_2015_minishell1
**
** Made by Clement Peau
** Login   <peau_c@epitech.net>
**
** Started on  Mon Jan 18 18:58:52 2016 Clement Peau
** Last update Sun Jan 24 20:30:25 2016 Clement Peau
*/

#include "minishell.h"

void	write_error(t_data *data)
{
  if (data->args[0][0] != 10)
    {
      write(2, data->args[0], my_strlen(data->args[0]));
      write(2, ": Command not found.\n", 21);
    }
  exit (0);
}

int	child(t_data *data)
{
  int	i;

  i = -1;
  if ((access(data->args[0], X_OK)) == 0)
    execve(data->args[0], data->args, data->envcpy);
  if (data->path == NULL || data->path[0] == NULL)
    write_error(data);
  while (data->path[++i] != NULL && access(data->path[i], X_OK) == -1)
    if (data->path[i + 1] == NULL)
      write_error(data);
  if (execve(data->path[i], data->args, data->envcpy) == -1 &&
      data->args[0][0] != 32)
    return (-1);
  return (0);
}

int	main_fork(t_data *data)
{
  pid_t	child_pid;
  int	status;

  child_pid = fork();
  if (child_pid != 0)
    wait(&status);
  if (child_pid == 0)
    {
      child(data);
      free_it(data);
      exit(0);
    }
  if (WIFSIGNALED(status))
    write(2, "Segmentation fault\n", 34);
  return (0);
}
