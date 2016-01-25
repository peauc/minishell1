/*
** my_getnbr.c for lol in /home/peau_c/my
**
** Made by clement peau
** Login   <peau_c@epitech.net>
**
** Started on  Sat Oct 17 15:22:36 2015 clement peau
** Last update Fri Nov 20 17:22:18 2015 clement peau
*/

int	checkneg(char *str, int neg)
{
  if (str[0] == '-' && neg == 0)
    return (-1);
  if (str[0] != '-' && neg == 0)
    return (1);
  if (neg != 0)
    return (neg);
  return (0);
}

int	calculnumber(int i, int nbr, char *str)
{
  int	neg;

  neg = 0;
  while (str[i] >= 48 && str[i] <= 57)
    {
      neg = checkneg(str, neg);
      nbr = nbr * 10;
      nbr = nbr + (str[i] - 48);
      i++;
    }
  return (nbr * neg);
}


int	getnbr(char *str)
{
  int	i;
  int	nbr;
  int	ret;

  nbr = 0;
  i = 0;
  ret = calculnumber(i, nbr, str);
  return (ret);
}
