/*
** my_putint.c for shell_get_line.c in /home/cassin_f/B2/B2-Systeme_Unix/42sh_cassin
** 
** Made by François CASSIN
** Login   <cassin_f@epitech.net>
** 
** Started on  Mon May 18 01:02:29 2015 François CASSIN
** Last update Mon May 18 01:02:58 2015 François CASSIN
*/

#include <unistd.h>

int		my_putint(int i)
{
  if (write(1, &i, 1) == -1)
    return (-1);
  return (0);
}
