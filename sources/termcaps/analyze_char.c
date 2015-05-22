/*
** analyze_char.c for shell_get_line in /home/cassin_f/42sh_cassin
** 
** Made by François CASSIN
** Login   <cassin_f@epitech.net>
** 
** Started on  Tue May 19 15:28:47 2015 François CASSIN
** Last update Fri May 22 14:03:28 2015 Sebastien BOULOC
*/

#include "my_get_line.h"

int		analyze_char(char c)
{
  char		save;
  int		i;

  i = 0;
  while (i < 7)
    {
      save = (c >> (7 - i));
      if ((save & 1) == 0)
	return (i);
      ++i;
    }
  return (i);
}
