/*
** my_strcat.c for my_strcat in /home/peau_c/rendu/PSU/minishell/PSU_2015_minishell1
**
** Made by Clement Peau
** Login   <peau_c@epitech.net>
**
** Started on  Mon Jan 18 20:34:51 2016 Clement Peau
** Last update Mon Jan 18 23:21:27 2016 Clement Peau
*/

void	my_strcat(char *dest, char *src)
{
  int	i;
  int	j;

  i = -1;
  j = 0;
  while (dest[++i] != 0);
  while (src[j] != 0)
    dest[i++] = src[j++];
  dest[i] = 0;
}
