/*
** alias_list.c for alias_list in /home/boulay_b/Work/SE2/PSU/42sh/PSU_2014_42sh
**
** Made by Arnaud Boulay
** Login   <boulay_b@epitech.net>
**
** Started on  Fri May 22 00:56:30 2015 Arnaud Boulay
** Last update Fri May 22 01:11:41 2015 Arnaud Boulay
*/

#include <stdlib.h>
#include "my.h"

t_alias		*create_alias(void)
{
  t_alias	*alias;

  if ((alias = malloc(sizeof(t_alias))) == NULL)
    {
      my_putstr("Error: Malloc failed in create_alias_list.\n");
      return (NULL);
    }
  alias->back = alias;
  alias->next = alias;
  alias->name = NULL;
  alias->to = NULL;
  return (alias);
}

int		add_alias(char *name, char *to)
{
  t_alias	*new_chain;

  if (name == NULL || to == NULL)
    {
      my_putstr("Error: add_alias: str is NULL.\n");
      return (-1);
    }
  if ((new_chain = malloc(sizeof(t_alias))) == NULL)
    {
      my_putstr("Error: Malloc failed in add_alias.\n");
      return (-1);
    }
  if ((new_chain->name = my_strdup(name)) == NULL)
    return (-1);
  if ((new_chain->to = my_strdup(to)) == NULL)
    return (-1);
  new_chain->back = g_alias->back;
  new_chain->next = g_alias;
  g_alias->back->next = new_chain;
  g_alias->back = new_chain;
  return (0);
}

void		rm_alias(t_alias *chain)
{
  free(chain->name);
  free(chain->to);
  chain->back->next = chain->next;
  chain->next->back = chain->back;
  free(chain);
}

void		rm_alias_list()
{
  t_alias	*chain;
  t_alias	*tmp;

  chain = g_alias->next;
  while (chain != g_alias)
    {
      tmp = chain->next;
      rm_alias(chain);
      chain = tmp;
    }
  free(g_alias);
}
