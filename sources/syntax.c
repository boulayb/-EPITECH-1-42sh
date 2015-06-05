/*
** syntax.c for 42sh in /home/boulay_b/Work/SE2/PSU/42sh/PSU_2014_42sh
**
** Made by Arnaud Boulay
** Login   <boulay_b@epitech.net>
**
** Started on  Wed May 20 16:04:45 2015 Arnaud Boulay
** Last update Fri Jun  5 18:00:04 2015 Dylan Coodien
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

static int	check_ambigious_out(int *redir_right, char **line,
				    int i, t_env *env_list)
{
  if (strcmp(line[i], ">>") == 0 || strcmp(line[i], ">") == 0)
    {
      if (*redir_right == 1)
	{
	  printf("Ambiguous output redirect.\n");
	  disp_prompt(env_list);
	  free_tab(line);
	  return (1);
	}
      else
	*redir_right = 1;
    }
  else if (strcmp(line[i], ";") == 0 && *redir_right == 1)
    *redir_right = 0;
  return (0);
}

static int	check_syntax_core(char **line, int i, t_env *env_list)
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
      return (1);
    }
  return (0);
}

static int	check_ambigious_in(int *redir_left, char **line,
				   int i, t_env *env_list)
{
  if (strcmp(line[i], "<<") == 0 || strcmp(line[i], "<") == 0)
    {
      if (*redir_left == 1)
	{
	  printf("Ambiguous input redirect.\n");
	  disp_prompt(env_list);
	  free_tab(line);
	  return (1);
	}
      else
	*redir_left = 1;
    }
  else if (strcmp(line[i], ";") == 0 && *redir_left == 1)
    *redir_left = 0;
  return (0);
}

int		check_syntax(char **line, t_env *env_list)
{
  int		redir_right;
  int		redir_left;
  int		i;

  i = -1;
  redir_right = 0;
  redir_left = 0;
  while (line[++i] != NULL)
    if (check_syntax_core(line, i, env_list) == 1 ||
	check_ambigious_in(&redir_left, line, i, env_list) == 1 ||
	check_ambigious_out(&redir_right, line, i, env_list) == 1)
      {
	check_status(g_env, 1);
	return (-1);
      }
  free_tab(line);
  return (0);
}
