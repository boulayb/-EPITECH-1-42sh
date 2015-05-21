/*
** nmatch.c for shell_get_line in /home/cassin_f/B2/B2-Systeme_Unix/42sh_cassin
** 
** Made by François CASSIN
** Login   <cassin_f@epitech.net>
** 
** Started on  Mon May 18 19:36:41 2015 François CASSIN
** Last update Thu May 21 14:35:32 2015 Sebastien BOULOC
*/

#include "my_get_line.h"

int	nmatch(char *s1, char *s2)
{
  if (*s1 == *s2 && *s1 != 0 && *s2 != 0 && *s1 != '*')
    return (nmatch(s1 + 1, s2 + 1));
  if (*s1 == *s2 && *s1 == 0 && *s2 == 0)
    return (1);
  if (*s1 == 0 && *s2 == '*')
    return (nmatch(s1, s2 + 1));
  if (*s1 != 0 && *s2 == '*')
    return (nmatch(s1, s2 + 1) + nmatch(s1 + 1, s2));
  return (0);
}
