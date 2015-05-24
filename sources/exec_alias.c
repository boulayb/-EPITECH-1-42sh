/*
** exec_alias.c for 42sh in /home/boulay_b/Work/SE2/PSU/42sh/PSU_2014_42sh
**
** Made by Arnaud Boulay
** Login   <boulay_b@epitech.net>
**
** Started on  Fri May 22 01:33:48 2015 Arnaud Boulay
** Last update Sun May 24 02:58:31 2015 Arnaud Boulay
*/

#include <stdlib.h>
#include <string.h>
#include "my_get_line.h"
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

static char	**replace_with_alias(char **tab, char **rep, int *nb)
{
  int		j;
  int		i;
  char		**new;

  i = 0;
  j = 0;
  if (rep == NULL)
    return (tab);
  if ((new = malloc(sizeof(char *) * (tablen(tab) + tablen(rep)))) == NULL)
    return (NULL);
  while (i < (tablen(tab) + tablen(rep) - 1))
    if (j != *nb && tab[j] != NULL)
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
  *nb = -1;
  return (new);
}

static int	exec_alias_redo(char **tab, char **done, char **path,
				t_env *env_list)
{
  if (done != NULL)
    {
      if (my_prompt(my_tabtostr(tab), path, env_list, 2) == -1)
	return (-1);
      free_tab(done);
      tab[0] = NULL;
    }
  return (0);
}

char		**exec_alias(char *str, char **path, t_env *env_list)
{
  int		i;
  char		**done;
  char		**tab;
  char		**tmp;

  i = -1;
  done = NULL;
  if ((tab = my_str_to_cmdtab(str)) == NULL)
    return (NULL);
  if (tab[0] == NULL)
    return (tab);
  if (strcmp(tab[0], "alias") == 0)
    return (tab);
  if ((tmp = my_str_to_cmdtab(str)) == NULL)
    return (NULL);
  while (tab[++i] != NULL)
    if (i == 0 || is_cmd(tab[i - 1]) == 0)
      if ((done = is_alias_done(tab[i], done)) != NULL)
	if ((tab = replace_with_alias(tab, is_alias(tab[i]), &i)) == NULL)
	  return (NULL);
  if (exec_alias_redo(tab, done, path, env_list) == -1)
    return (NULL);
  return (tab);
}
