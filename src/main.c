/*
** main.c for main in /home/peau_c/rendu/PSU/minishell/PSU_2015_minishell1
**
** Made by
** Login   <peau_c@epitech.net>
**
** Started on  Thu Jan  7 16:29:47 2016
** Last update Fri Jan 22 16:44:49 2016 Clement Peau
*/

#include "minishell.h"

int	main(int ac, char **av, char **ae)
{
  if (ae[0] == NULL)
    {
      write (2, "May not function properly without environment\n", 47);
    }
  minishell(ac, av, ae);
  return (1);
}
