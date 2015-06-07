/*
** syntax.c for 42sh in /home/boulay_b/Work/SE2/PSU/42sh/PSU_2014_42sh
**
** Made by Arnaud Boulay
** Login   <boulay_b@epitech.net>
**
** Started on  Wed May 20 16:04:45 2015 Arnaud Boulay
** Last update Sun Jun  7 17:03:13 2015 Arnaud Boulay
*/

#include <stdio.h>
#include <string.h>
#include "my.h"

extern t_env		*g_env;

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

static int	check_ambigious_out(int *redir_right, char *str, char *last)
{
  if (strcmp(str, ">>") == 0 || strcmp(str, ">") == 0 ||
      (last != NULL && (strcmp(last, ">>") == 0 || strcmp(last, ">") == 0)
       && strcmp(str, "|") == 0))
    {
      if (*redir_right == 1 || strcmp(str, "|") == 0)
	{
	  printf("Ambiguous output redirect.\n");
	  return (1);
	}
      else
	*redir_right = 1;
    }
  else if (strcmp(str, ";") == 0 && *redir_right == 1)
    *redir_right = 0;
  return (0);
}

static int	check_syntax_core(char **line, int i)
{
  if ((i == 0 && is_op(line[i]) == 1) ||
      (i != 0 && is_op(line[i - 1]) == 1 && is_op(line[i]) == 1) ||
      (i != 0 && is_op(line[i - 1]) == 1 && strcmp(line[i], ";") == 0) ||
      (strcmp(line[i], ";") == 0 && is_op(line[i + 1]) == 1) ||
      (is_op(line[i]) == 1 && is_op(line[i + 1]) == 1))
    {
      printf("Invalid null command.\n");
      return (1);
    }
  return (0);
}

static int	check_ambigious_in(int *redir_left, char *str, char *last)
{
  if (strcmp(str, "<<") == 0 || strcmp(str, "<") == 0)
    {
      if (*redir_left == 1 || (last != NULL && strcmp(last, "|") == 0))
	{
	  printf("Ambiguous input redirect.\n");
	  return (1);
	}
      else
	*redir_left = 1;
    }
  else if (strcmp(str, ";") == 0 && *redir_left == 1)
    *redir_left = 0;
  return (0);
}

int		check_syntax(char **line, t_env *env_list)
{
  char		*last;
  int		redir_right;
  int		redir_left;
  int		i;

  i = -1;
  redir_right = 0;
  redir_left = 0;
  last = NULL;
  while (line[++i] != NULL)
    {
      if (check_syntax_core(line, i) == 1 ||
	  check_ambigious_in(&redir_left, line[i], last) == 1 ||
	  check_ambigious_out(&redir_right, line[i], last) == 1)
	{
	  disp_prompt(env_list);
	  free_tab(line);
	  return (-1);
	}
      if (is_op(line[i]) == 1 || strcmp(line[i], ";") == 0)
	last = line[i];
    }
  free_tab(line);
  return (0);
}
