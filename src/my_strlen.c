/*
** my_strlen.c for strlen in /home/peau_c/rendu/PSU/minishell/PSU_2015_minishell1
**
** Made by Clement Peau
** Login   <peau_c@epitech.net>
**
** Started on  Mon Jan 18 22:54:57 2016 Clement Peau
** Last update Tue Jan 19 17:36:13 2016 Clement Peau
*/

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[++i] != 0);
  return (i);
}
