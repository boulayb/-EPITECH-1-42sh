/*
** echo.c for 42sh in /home/boulay_b/Work/SE2/PSU/42sh/PSU_2014_minishell2
**
** Made by Arnaud Boulay
** Login   <boulay_b@epitech.net>
**
** Started on  Fri May 15 01:31:42 2015 Arnaud Boulay
** Last update Fri May 15 02:05:07 2015 Arnaud Boulay
*/

#include <stdlib.h>
#include <stdio.h>
#include "my.h"

int		my_echo(char **tab, char **path, char **tabsep, t_env *env_list)
{
  char		*str;

  (void)path;
  (void)tabsep;
  if (tab[1] != NULL)
    {
      if (my_strcmp("$", tab[1]) == 2)
	{
	  if ((str = get_env(tab[1] + 1, env_list)) != NULL)
	    printf("%s", str + my_strlen(tab[1]));
	}
      else
	printf("%s", tab[1]);
    }
  printf("\n");
  return (0);
}
