/*
** epur_str.c for Lemin in /home/cassin_f/B2/B2-CPE/Lemin/lib/my
** 
** Made by François CASSIN
** Login   <cassin_f@epitech.net>
** 
** Started on  Tue Apr 14 13:58:00 2015 François CASSIN
** Last update Wed Apr 29 13:07:32 2015 Sebastien BOULOC
*/

#include <stdlib.h>

static int	last_word(char *str, int i)
{
  while (str[i])
    {
      if (str[i] != ' ' && str[i] != '\t')
	return (1);
      ++i;
    }
  return (0);
}

int		epur_str(char *str)
{
  int		i;
  int		j;

  if (str == NULL)
    return (-1);
  i = 0;
  j = 0;
  while (str[i])
    {
      while (str[i] && (str[i] == ' ' || str[i] == '\t'))
	++i;
      while (str[i] != ' ' && str[i] != '\t' && str[i])
	str[j++] = str[i++];
      if (str[i] && last_word(str, i) == 1)
	str[j++] = ' ';
    }
  str[j] = 0;
  return (0);
}
