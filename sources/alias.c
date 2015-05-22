/*
** alias.c for 42sh in /home/boulay_b/Work/SE2/PSU/42sh/PSU_2014_42sh
**
** Made by Arnaud Boulay
** Login   <boulay_b@epitech.net>
**
** Started on  Thu May 21 21:45:34 2015 Arnaud Boulay
** Last update Fri May 22 17:45:07 2015 Sebastien BOULOC
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "my.h"

static void	remove_alias(char *str)
{
  t_alias	*alias;

  alias = g_alias->next;
  while (alias != g_alias)
    {
      if (strcmp(alias->name, str) == 0)
	rm_alias(alias);
      alias = alias->next;
    }
}

static t_alias	*get_alias(char *name)
{
  t_alias	*alias;

  alias = g_alias->next;
  while (alias != g_alias)
    {
      if (strcmp(alias->name, name) == 0)
	return (alias);
      alias = alias->next;
    }
  return (NULL);
}

static void	disp_alias(char *name)
{
  t_alias	*alias;

  alias = g_alias->next;
  while (alias != g_alias)
    {
      if (name == NULL)
	printf("%-10s %s\n", alias->name, alias->to);
      else if (strcmp(alias->name, name) == 0)
	printf("%s\n", alias->to);
      alias = alias->next;
    }
}

int		my_alias(char **tab, char **path, t_env *env_list)
{
  t_alias	*alias;

  (void)path;
  (void)env_list;
  if (tab[1] == NULL)
    disp_alias(NULL);
  else if (tab[2] == NULL)
    disp_alias(tab[1]);
  else
    if (strcmp(tab[1], "-r") == 0 || strcmp(tab[1], "--remove") == 0)
      remove_alias(tab[2]);
    else if ((alias = get_alias(tab[1])) != NULL)
      {
	free(alias->to);
	if ((alias->to = strdup(tab[2])) == NULL)
	  return (-1);
      }
    else
      if (add_alias(tab[1], tab[2]) == -1)
	return (-1);
  return (0);
}
