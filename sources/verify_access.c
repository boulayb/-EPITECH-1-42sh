/*
** verify_acess.c for verify_acess in /home/danilo_d/semestre2/PSU_2014_minishell2
**
** Made by danilov dimitri
** Login   <danilo_d@epitech.net>
**
** Started on  Tue Mar 10 14:02:36 2015 danilov dimitri
** Last update Thu May 21 17:57:03 2015 danilov dimitri
*/

#define _GNU_SOURCE

#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include "sh42.h"

int		error(char **argv, char **path, int ret, int i)
{
  if (ret == -1 && path[i] == NULL
      && access(argv[0], X_OK) == -1)
    {
      printf("%s: ", argv[0]);
      return (127);
    }
  return (0);
}

char		*concat_string(char *command, char *path)
{
  char		*str;

  if ((str = xmalloc(strlen(path) + strlen(command) + 2)) == NULL)
      return (NULL);
  str[0] = 0;
  strcat(str, path);
  strcat(str, "/");
  strcat(str, command);
  return (str);
}

int		help(int *ret, int *i, t_list *tmp)
{
  *ret = 1;
  *i = -1;
  if (tmp->back->act == PIPE || tmp->back->act == ENDACT || tmp->back->act == -1)
    return (0);
  return (-1);
}

int		verify_access(t_list *comm, char **path)
{
  t_list	*tmp;
  char		*command;
  int		i;
  int		ret;

  tmp = comm->next;
  while (tmp != comm)
    {
      if (help(&ret, &i, tmp) == 0)
	{
	  while (ret != 0 && path[++i] != NULL)
	    {
	      if ((command = concat_string(tmp->av[0], path[i])) == NULL)
		return (-1);
	      if ((ret = access(command, X_OK)) == 0)
		if ((tmp->av[0] = strdup(command)) == NULL)
		  return (-1);
	      free(command);
	    }
	  if (error(tmp->av, path, ret, i) != 0)
	    return (127);
	}
      tmp = tmp->next;
    }
  return (0);
}
