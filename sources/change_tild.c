/*
** change_tild.c for tild in /home/cassin_f/PSU_2014_42sh
**
** Made by François CASSIN
** Login   <cassin_f@epitech.net>
**
** Started on  Sat May 23 15:06:01 2015 François CASSIN
** Last update Sat May 23 15:32:29 2015 Dylan Coodien
*/

#include <string.h>
#include <stdlib.h>
#include "my.h"

static int	tild_is_in_str(char *str)
{
  if (str == NULL)
    return (1);
  if (str[0] == '~')
    return (0);
  return (1);
}

static void	copy_home_to_str(char *new_str, char *home, char *str)
{
  int		i;
  int		n;

  i = 0;
  n = 0;
  while (home[i])
    {
      new_str[n] = home[i];
      ++i;
      ++n;
    }
  i = 1;
  while (str[i])
    {
      new_str[n] = str[i];
      ++i;
      ++n;
    }
  new_str[n] = 0;
}

static char	*replace_tild(char *str, t_env *env)
{
  char		*home;
  char		*new_str;

  if (str == NULL)
    return (str);
  if ((home = get_env("HOME=", env)) == NULL)
    return (str);
  home = home + 5;
  if ((new_str = malloc(sizeof(char) *
			(strlen(str) + strlen(home) + 1))) == NULL)
    return (str);
  copy_home_to_str(new_str, home, str);
  free(str);
  return (new_str);
}

void		change_tild(char **tab, t_env *env)
{
  int		i;

  i = 0;
  while (tab[i])
    {
      if (tild_is_in_str(tab[i]) == 0)
	tab[i] = replace_tild(tab[i], env);
      ++i;
    }
}
