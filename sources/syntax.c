/*
** syntax.c for 42sh in /home/boulay_b/Work/SE2/PSU/42sh/PSU_2014_42sh
**
** Made by Arnaud Boulay
** Login   <boulay_b@epitech.net>
**
** Started on  Wed May 20 16:04:45 2015 Arnaud Boulay
** Last update Thu May 21 16:33:11 2015 danilov dimitri
*/

#include <stdio.h>
#include <string.h>
#include "my.h"

int		is_operator(char *str)
{
  if (str == NULL)
    return (0);
  else if (strcmp(str, "|") == 0 || strcmp(str, "||") == 0 ||
	   strcmp(str, "&&") == 0 || strcmp(str, "<<") == 0 ||
	   strcmp(str, ">>") == 0 || strcmp(str, "<") == 0 ||
	   strcmp(str, ">") == 0)
    return (1);
  else
    return (0);
}

int		check_syntax(char **line, t_env *env_list)
{
  int		i;

  i = -1;
  while (line[++i] != NULL)
    {
      if ((i == 0 && is_operator(line[i]) == 1) ||
	  (i != 0 && is_operator(line[i - 1]) == 1 && is_operator(line[i]) == 1) ||
	  (is_operator(line[i]) == 1 && is_operator(line[i + 1]) == 1))
	{
	  printf("Invalid null command.\n");
	  disp_prompt(env_list);
	  return (-1);
	}
    }
  return (0);
}
