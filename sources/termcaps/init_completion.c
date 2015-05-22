/*
** init_completion.c for shell_get_line in /home/cassin_f/B2/B2-Systeme_Unix/42sh_cassin
** 
** Made by François CASSIN
** Login   <cassin_f@epitech.net>
** 
** Started on  Sun May 17 23:40:02 2015 François CASSIN
** Last update Fri May 22 13:40:26 2015 Sebastien BOULOC
*/

#include <stdlib.h>
#include "my_get_line.h"

int	init_completion(t_completion *complet, t_env *env)
{
  if ((complet->path = malloc(sizeof(t_complet))) == NULL)
    return (-1);
  complet->path->name = NULL;
  complet->path->next = complet->path;
  complet->path->prev = complet->path;
  if ((complet->local = malloc(sizeof(t_complet))) == NULL)
    return (-1);
  complet->local->name = NULL;
  complet->local->next = complet->local;
  complet->local->prev = complet->local;
  if (init_path(complet->path, env) == -1)
    return (-1);
  if (init_local(complet->local) == -1)
    return (-1);
  return (0);
}
