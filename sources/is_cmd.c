/*
** is_cmd.c for 42sh in /home/boulay_b/Work/SE2/PSU/42sh/PSU_2014_42sh
**
** Made by Arnaud Boulay
** Login   <boulay_b@epitech.net>
**
** Started on  Sat May 23 15:05:49 2015 Arnaud Boulay
** Last update Sat May 23 15:08:40 2015 Arnaud Boulay
*/

#include <stdlib.h>
#include <string.h>

int	is_cmd(char *str)
{
  if (str == NULL)
    return (1);
  if (strcmp(str, "|") != 0 || strcmp(str, "<") != 0 || strcmp(str, ">") != 0 ||
      strcmp(str, ">>") != 0 || strcmp(str, "<<") != 0)
    return (1);
  return (0);
}
