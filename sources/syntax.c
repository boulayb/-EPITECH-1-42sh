/*
** syntax.c for 42sh in /home/boulay_b/Work/SE2/PSU/42sh/PSU_2014_42sh
**
** Made by Arnaud Boulay
** Login   <boulay_b@epitech.net>
**
** Started on  Wed May 20 16:04:45 2015 Arnaud Boulay
** Last update Fri Jun  5 15:41:50 2015 Arnaud Boulay
*/

#include <stdio.h>
#include <string.h>
#include "my.h"

static int	is_op(char *str)
{
  if (str == NULL)
    return (1);
  else if (strcmp(str, "|") == 0 || strcmp(str, "||") == 0 ||
	   strcmp(str, "&&") == 0 || strcmp(str, "<<") == 0 ||
	   strcmp(str, ">>") == 0 || strcmp(str, "<") == 0 ||
	   strcmp(str, ">") == 0)
    return (1);
  else
    return (0);
}

static int	check_ambigious(char *last, char **line,
				int i, t_env *env_list)
{
  if ((strcmp(last, ">") == 0 || strcmp(last, ">>") == 0)
      && strcmp(line[i], "|") == 0)
    {
      printf("Ambiguous output redirect.\n");
      disp_prompt(env_list);
      free_tab(line);
      return (1);
    }
  return (0);
}

int		check_syntax(char **line, t_env *env_list)
{
  char		*last;
  int		i;

  i = -1;
  last = NULL;
  while (line[++i] != NULL)
    {
      if ((i == 0 && is_op(line[i]) == 1) ||
	  (i != 0 && is_op(line[i - 1]) == 1 && is_op(line[i]) == 1) ||
	  (i != 0 && is_op(line[i - 1]) == 1 && strcmp(line[i], ";") == 0) ||
	  (strcmp(line[i], ";") == 0 && is_op(line[i + 1]) == 1) ||
	  (is_op(line[i]) == 1 && is_op(line[i + 1]) == 1))
	{
	  printf("Invalid null command.\n");
	  disp_prompt(env_list);
	  free_tab(line);
	  return (-1);
	}
      if (last != NULL && check_ambigious(last, line, i, env_list) == 1)
	return (-1);
      if (is_op(line[i]) == 1)
	last = line[i];
    }
  free_tab(line);
  return (0);
}
