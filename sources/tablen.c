/*
** tablen.c for 42sh in /home/boulay_b/Work/SE2/PSU/42sh/PSU_2014_42sh
**
** Made by Arnaud Boulay
** Login   <boulay_b@epitech.net>
**
** Started on  Fri May 22 13:55:38 2015 Arnaud Boulay
** Last update Fri May 22 13:56:30 2015 Arnaud Boulay
*/

#include <stdlib.h>

int	tablen(char **tab)
{
  int	i;

  i = 0;
  while (tab[i] != NULL)
    ++i;
  return (i);
}
