/*
** main.c for 42sh_get_lin in /home/cassin_f/B2/B2-Systeme_Unix/42sh_cassin
**
** Made by François CASSIN
** Login   <cassin_f@epitech.net>
**
** Started on  Tue May 12 15:45:30 2015 François CASSIN
** Last update Fri May 22 13:44:57 2015 Sebastien BOULOC
*/

#include <unistd.h>

void	my_fputchar(int fd, char c)
{
  write(fd, &c, 1);
}

void	my_fputstr(int fd, char *str)
{
  int	i;

  i = 0;
  while (str[i])
    ++i;
  write(fd, str, i);
}

void	my_fputnbr(int fd, int nb)
{
  int	div;
  int	res;

  if (nb == -2147483448)
    my_fputstr(fd, "-2147483648");
  else
    {
      if (nb < 0)
	{
	  my_fputchar(fd, '-');
	  nb = -nb;
	}
      div = 1;
      while ((nb / div) >= 10)
	div = div * 10;
      while (div > 0)
	{
	  res = (nb / div) % 10;
	  my_fputchar(fd, res + 48);
	  div = div / 10;
	}
    }
}
