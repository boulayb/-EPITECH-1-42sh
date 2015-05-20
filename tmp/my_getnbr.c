/*
** my_getnbr.c for my_getnbr in /home/cassin_f/rendu/training
** 
** Made by François CASSIN
** Login   <cassin_f@epitech.net>
** 
** Started on  Fri Oct 10 19:23:34 2014 François CASSIN
** Last update Mon May 18 01:41:16 2015 François CASSIN
*/

int	neg_pos(char *str)
{
  int	i;
  int	count;

  i = 0;
  count = 0;
  while (str[i] < '0' || str[i] > '9')
    {
      if (str[i] ==  '-')
	count = count + 1;
      i = i + 1;
    }
  if (count % 2 == 0)
    return (0);
  else
    return (1);
}

int	out_limit(int nb, char c, char *str)
{
  int	i;
  int	count;

  count = 0;
  i = 0;
  while (str[i] < '0' || str[i] > '9')
    i = i + 1;
  while (str[i] >= '0' && str[i] <= '9')
    {
      i = i + 1;
      count = count + 1;
    }
  if (count >= 11)
    return (1);
  if (nb > 214748364)
      return (1);
  if (nb == 214748364)
    {
      if (neg_pos(str) == 1 && c > '8')
	return (1);
      if (neg_pos(str) == 0 && c > '7')
	return (1);
    }
  return (0);
}

int	my_getnbr(char *str)
{
  int	nb;
  int	i;

  nb = 0;
  i = 0;
  while (str[i] < '0' || str[i] > '9')
    {
      if (str[i] != '-' && str[i] != '+')
	return (0);
      i = i + 1;
    }
  while (str[i] >= '0' && str[i] <= '9')
    {
      if (out_limit(nb, str[i], str) == 1)
	return (0);
      nb = (nb * 10) + (str[i] - 48);
      i = i + 1;
    }
  if (neg_pos(str) == 1)
    nb = -nb;
  return (nb);
}
