/*
** count_quotes.c for 42sh in /home/boulay_b/Work/SE2/PSU/42sh/PSU_2014_42sh
**
** Made by Arnaud Boulay
** Login   <boulay_b@epitech.net>
**
** Started on  Fri May 22 21:24:55 2015 Arnaud Boulay
** Last update Fri May 22 21:24:55 2015 Arnaud Boulay
*/

#include <stdio.h>

int		count_quotes(char *str)
{
  int		quote;
  int		i;

  i = -1;
  quote = 0;
  while (str[++i] != '\0')
    if (str[i] == '"')
      ++quote;
  if (quote % 2 != 0)
    {
      printf("Unmatched \".\n");
      return (-1);
    }
  return (quote);
}
