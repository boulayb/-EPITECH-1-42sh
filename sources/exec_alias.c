/*
** exec_alias.c for 42sh in /home/boulay_b/Work/SE2/PSU/42sh/PSU_2014_42sh
**
** Made by Arnaud Boulay
** Login   <boulay_b@epitech.net>
**
** Started on  Fri May 22 01:33:48 2015 Arnaud Boulay
** Last update Fri May 22 12:12:14 2015 Arnaud Boulay
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "my.h"

int		tablen(char **tab)
{
  int		i;

  i = 0;
  while (tab[i] != NULL)
    ++i;
  return (i);
}

char		**replace_with_alias(char **tab, char **rep, int nb)
{
  int		size;
  int		j;
  int		k;
  int		i;
  char		**new;

  i = -1;
  j = 0;
  k = -1;
  if (rep == NULL)
    return (tab);
  int	o = -1;
  while (tab[++o] != NULL)
    printf("%s\n", tab[o]);
  int	u = -1;
  while (rep[++u] != NULL)
    printf("%s\n", rep[u]);
  printf("done\n");
  size = tablen(tab) + tablen(rep) + 1;
  if ((new = malloc(sizeof(char *) * size)) == NULL)
    return (NULL);
  while (++i < size)
    {
      if (j != nb && tab[j] != NULL)
	{
	  if ((new[i] = malloc(sizeof(char) * (strlen(tab[j]) + 1))) == NULL)
	    return (NULL);
	  new[i] = strcpy(new[i], tab[j]);
	  ++j;
	}
      else
	{
	  while (rep[++k] != NULL)
	    {
	      if ((new[i] = malloc(sizeof(char) * (strlen(rep[k]) + 1))) == NULL)
		return (NULL);
	      new[i] = strcpy(new[i], rep[k]);
	      ++i;
	    }
	  ++j;
	}
    }
  free_tab(tab);
  free_tab(rep);
  new[++i] = NULL;
  return (new);
}

char		**is_alias(char *str)
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
  if (strcmp(tab[0], "alias") == 0)
    return (tab);
  tmp = tab;
  while (tmp[++i] != NULL)
    if ((tab = replace_with_alias(tab, is_alias(tmp[i]), i)) == NULL)
      return (NULL);
  return (tab);
}
