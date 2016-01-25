/*
** main.c for main in /home/peau_c/rendu/PSU/minishell/PSU_2015_minishell1
**
** Made by
** Login   <peau_c@epitech.net>
**
** Started on  Thu Jan  7 16:29:47 2016
** Last update Sun Jan 24 22:35:20 2016 Clement Peau
*/

#include "minishell.h"

char		*read_it(t_data *data)
{
  int		i;
  int		readed;

  if ((data->get_next = malloc(4096 * sizeof(char))) == NULL)
    exit(-1);
  if (((readed = read(0, data->get_next, 4096)) <= 0))
    {
      write(1, "exit\n", 5);
      /* free_it(data); */
    }
  i = -1;
  while (data->get_next[++i] != 0 && data->get_next[i] != 10)
    {
      if (data->get_next[i] == 10)
	data->get_next[i] = 0;
      if (data->get_next[i] == '\t')
	data->get_next[i] = ' ';
    }
  if (data->get_next[0] == 0)
    return (NULL);
  return (data->get_next);
}

int		minishell(int ac, char **av, char **env)
{
  t_data	data;

  (void)ac;
  (void)av;
  signal(SIGINT, SIG_IGN);
  data.path = NULL;
  if ((data.envcpy = get_env(env)) == NULL)
    return (1);
  while (42)
    {
      get_path(&data);
      write(1, "$> ", 3);
	if ((read_it(&data)) == NULL)
      	return (1);
      if ((data.get_next = main_calc(&data)) == NULL)
	return (1);
      if (data.args[0] != NULL)
	if (is_builtin(&data) != 0)
	  main_fork(&data);
     }
}
