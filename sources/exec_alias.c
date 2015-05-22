/*
** exec_alias.c for 42sh in /home/boulay_b/Work/SE2/PSU/42sh/PSU_2014_42sh
**
** Made by Arnaud Boulay
** Login   <boulay_b@epitech.net>
**
** Started on  Fri May 22 01:33:48 2015 Arnaud Boulay
** Last update Fri May 22 17:36:54 2015 Sebastien BOULOC
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "my.h"

static char	**copy_vanilla(char **tab, char **new, int *i, int *j)
{
  if ((new[*i] = malloc(sizeof(char) * (strlen(tab[*j]) + 1))) == NULL)
    return (NULL);
  new[*i] = strcpy(new[*i], tab[*j]);
  ++(*j);
  ++(*i);
  return (new);
}

static char	**copy_alias(char **rep, char **new, int *i, int *j)
{
  int		k;

  k = -1;
  while (rep[++k] != NULL)
    {
      if ((new[*i] = malloc(sizeof(char) * (strlen(rep[k]) + 1))) == NULL)
	return (NULL);
      new[*i] = strcpy(new[*i], rep[k]);
      ++(*i);
    }
  ++(*j);
  return (new);
}

static char	**replace_with_alias(char **tab, char **rep, int nb)
{
  int		size;
  int		j;
  int		i;
  char		**new;

  i = 0;
  j = 0;
  if (rep == NULL)
    return (tab);
  size = tablen(tab) + tablen(rep);
  if ((new = malloc(sizeof(char *) * size)) == NULL)
    return (NULL);
  while (i < size - 1)
    if (j != nb && tab[j] != NULL)
      {
	if (copy_vanilla(tab, new, &i, &j) == NULL)
	  return (NULL);
      }
    else
      if (copy_alias(rep, new, &i, &j) == NULL)
	return (NULL);
  free_tab(tab);
  free_tab(rep);
  new[i] = NULL;
  return (new);
}

static char	**is_alias(char *str)
{
  char		**tab;
  t_alias	*alias;

  alias = g_alias->next;
  while (alias != g_alias)
    {
      if (strcmp(alias->name, str) == 0)
	{
	  if ((tab = my_quotetowordtab(alias->to, " ")) == NULL)
	    return (NULL);
	  return (tab);
	}
      alias = alias->next;
    }
  return (NULL);
}

char		**exec_alias(char *str)
{
  int		i;
  char		**tab;
  char		**tmp;

  i = -1;
  if ((tab = my_quotetowordtab(str, " ")) == NULL)
    return (NULL);
  if (tab[0] == NULL)
    return (tab);
  if (strcmp(tab[0], "alias") == 0)
    return (tab);
  if ((tmp = my_quotetowordtab(str, " ")) == NULL)
    return (NULL);
  while (tmp[++i] != NULL)
    if ((tab = replace_with_alias(tab, is_alias(tmp[i]), i)) == NULL)
      return (NULL);
  return (tab);
}
