/*
** main.c for 42sh_get_lin in /home/cassin_f/B2/B2-Systeme_Unix/42sh_cassin
** 
** Made by François CASSIN
** Login   <cassin_f@epitech.net>
** 
** Started on  Tue May 12 15:45:30 2015 François CASSIN
** Last update Wed May 20 14:24:02 2015 François CASSIN
*/

#include <stdlib.h>
#include <unistd.h>
#include "my_get_line.h"

void	my_fputchar(int fd, char c)
{
  write(fd, &c, 1);
}

void	my_fputstr(int fd, char *str)
{
  int	i;

  i = 0;
  while (str[i])
    i = i + 1;
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

void	my_show_tab(char **tab)
{
  int	i;

  i = 0;
  while (tab[i])
    {
      my_fputstr(1, tab[i]);
      my_fputchar(1, '\n');
      i = i + 1;
    }
}

int	main(int ac, char **av, char **env)
{
  char	**tab;
  t_env	*env_list;
  int	stop;

  (void)ac;
  (void)av;
  stop = 0;
  env_list = create_list(env);
  if ((tab = shell_get_line(env_list, &stop)) != NULL)
    my_show_tab(tab);
  return (0);
}
