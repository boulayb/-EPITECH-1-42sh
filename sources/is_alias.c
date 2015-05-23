/*
** is_alias.c for 42sh in /home/boulay_b/Work/SE2/PSU/42sh/PSU_2014_42sh
**
** Made by Arnaud Boulay
** Login   <boulay_b@epitech.net>
**
** Started on  Sat May 23 17:20:09 2015 Arnaud Boulay
** Last update Sat May 23 17:22:42 2015 Arnaud Boulay
*/

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "my_get_line.h"
#include "my.h"

char		**is_alias(char *str)
{
  char		**tab;
  t_alias	*alias;

  alias = g_alias->next;
  while (alias != g_alias)
    {
      if (strcmp(alias->name, str) == 0)
	{
	  if ((tab = my_str_to_cmdtab(alias->to)) == NULL)
	    return (NULL);
	  return (tab);
	}
      alias = alias->next;
    }
  return (NULL);
}

char		**is_alias_done(char *str, char **done)
{
  t_alias	*alias;

  alias = g_alias->next;
  while (alias != g_alias)
    {
      if (strcmp(alias->name, str) == 0)
	{
	  if (alias_done(done, alias->name) == 1)
	    {
	      printf("Ignoring alias %s : Alias loop.\n", alias->name);
	      return (NULL);
	    }
	  if ((done = done_alias(done, alias->name)) == NULL)
	    return (NULL);
	  return (done);
	}
      alias = alias->next;
    }
  return (NULL);
}
