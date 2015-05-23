/*
** alias_done.c for 42sh in /home/boulay_b/Work/SE2/PSU/42sh/PSU_2014_42sh
**
** Made by Arnaud Boulay
** Login   <boulay_b@epitech.net>
**
** Started on  Sat May 23 16:12:44 2015 Arnaud Boulay
** Last update Sat May 23 16:36:41 2015 Arnaud Boulay
*/

#include <stdlib.h>
#include <string.h>
#include "my.h"

int		alias_done(char **done, char *name)
{
  int		i;

  i = -1;
  while (done != NULL && done[++i] != NULL)
    if (strcmp(done[i], name) == 0)
      return (1);
  return (0);
}

char		**done_alias(char **done, char *name)
{
  char		**new;
  int		i;
  int		size;

  i = -1;
  if ((size = tablen(done)) == 0)
    size = 1;
  if ((new = malloc(sizeof(char *) * (size + 2))) == NULL)
    return (NULL);
  while (done != NULL && done[++i] != NULL)
    {
      if ((new[i] = malloc(sizeof(char) * (strlen(done[i]) + 1))) == NULL)
	return (NULL);
      new[i] = strcpy(new[i], done[i]);
    }
  if (done == NULL)
    ++i;
  if ((new[i] = malloc(sizeof(char) * (strlen(name) + 1))) == NULL)
    return (NULL);
  new[i] = strcpy(new[i], name);
  new[++i] = NULL;
  if (done != NULL)
    free_tab(done);
  return (new);
}
