/*
** env.c for minishell1 in /home/boulay_b/Rendu/PSU/PSU_2014_minishell1
**
** Made by arnaud boulay
** Login   <boulay_b@epitech.net>
**
** Started on  Tue Jan 20 17:23:44 2015 arnaud boulay
** Last update Fri Jun  5 17:42:27 2015 Arnaud Boulay
*/

#include <stdlib.h>
#include "my.h"

int	check_env(t_env *env_list)
{
  if (get_env("PATH=", env_list) == NULL)
    if (add_chain(env_list, MY_PATH) == -1)
      return (-1);
  if (get_env("PWD=", env_list) == NULL)
    if (add_chain(env_list, "PWD=") == -1)
      return (-1);
  if (get_env("?=", env_list) == NULL)
    if (add_chain(env_list, "?=0") == -1)
      return (-1);
  return (0);
}

char	*get_env(char *str, t_env *env_list)
{
  t_env	*tmp;

  tmp = env_list->next;
  while (tmp != env_list)
    {
      if (my_strcmp(str, tmp->str) == 2 || my_strcmp(str, tmp->str) == 1)
	return (tmp->str);
      tmp = tmp->next;
    }
  return (NULL);
}

int	remove_env(t_env *env_list, char *str)
{
  t_env	*tmp;

  tmp = env_list->next;
  while (tmp != env_list)
    {
      if (my_strcmp(str, tmp->str) == 2 || my_strcmp(str, tmp->str) == 1)
	{
	  rm_chain(tmp);
	  return (0);
	}
      tmp = tmp->next;
    }
  return (-1);
}
