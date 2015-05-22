/*
** my_putint.c for shell_get_line.c in /home/cassin_f/B2/B2-Systeme_Unix/42sh_cassin
** 
** Made by François CASSIN
** Login   <cassin_f@epitech.net>
** 
** Started on  Mon May 18 01:02:29 2015 François CASSIN
** Last update Fri May 22 13:45:11 2015 Sebastien BOULOC
*/

#include <unistd.h>

int	my_putint(int i)
{
  if (write(1, &i, 1) == -1)
    return (-1);
  return (0);
}
