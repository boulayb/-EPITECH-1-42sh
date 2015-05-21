/*
** count_moves.c for count_moves in /home/dcoodien/rendu/SysUnix/B2/coodie/src
** 
** Made by Dylan Coodien
** Login   <coodie_d@epitech.eu>
** 
** Started on  Mon May  4 12:14:05 2015 Dylan Coodien
** Last update Thu May 21 12:49:58 2015 Sebastien BOULOC
*/

#include <string.h>

int		count_av(char **av, int *i)
{
  int		n;

  n = *i;
  while (av[*i] != NULL && ((strcmp("|", av[*i])) != 0)
	 && ((strcmp(">", av[*i])) != 0)
	 && ((strcmp(">>", av[*i])) != 0) && ((strcmp("<", av[*i])) != 0)
	 && ((strcmp("<<", av[*i])) != 0))
    ++(*i);
  ++(*i);
  return (*i - n - 1);
}

int		count_moves(char **av)
{
  int		i;
  int		n;

  i = 0;
  n = 0;
  if (av[0] == NULL)
    return (-1);
  while (av[i] != NULL)
    {
      if (((strcmp("|", av[i])) == 0) || ((strcmp(">", av[i])) == 0)
	  || ((strcmp(">>", av[i])) == 0) ||
	  ((strcmp("<", av[i])) == 0) || ((strcmp("<<", av[i])) == 0))
	++n;
      ++i;
    }
  if (n == 0)
    return (n);
  return (n);
}
