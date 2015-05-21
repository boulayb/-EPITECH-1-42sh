/*
** syntax.c for 42sh in /home/boulay_b/Work/SE2/PSU/42sh/PSU_2014_42sh
**
** Made by Arnaud Boulay
** Login   <boulay_b@epitech.net>
**
** Started on  Wed May 20 16:04:45 2015 Arnaud Boulay
** Last update Thu May 21 13:09:42 2015 Arnaud Boulay
*/

#include <stdio.h>
#include <string.h>

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

int		check_syntax(char **line)
{
  int		i;

  i = -1;
  while (line[++i] != NULL)
    {
      if (i == 0 && is_operator(line[i]) == 1)
	{
	  printf("Invalid null command.\n");
	  return (-1);
	}
      else if (i != 0 && is_operator(line[i - 1]) == 1 &&
	       is_operator(line[i]) == 1)
	{
	  printf("Invalid null command.\n");
	  return (-1);
	}
      else if (is_operator(line[i]) == 1 && is_operator(line[i + 1]) == 1)
	{
	  printf("Invalid null command.\n");
	  return (-1);
	}
    }
  return (0);
}
