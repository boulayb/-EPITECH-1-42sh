/*
** history.c for 42sh in /home/boulay_b/Work/SE2/PSU/42sh/PSU_2014_42sh
**
** Made by Arnaud Boulay
** Login   <boulay_b@epitech.net>
**
** Started on  Fri May 22 14:29:01 2015 Arnaud Boulay
** Last update Fri May 22 15:03:08 2015 Arnaud Boulay
*/

#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include "my.h"

int	my_history(char **tab, char **path, t_env *env_list)
{
  char	*str;
  char	*file;
  char	*home;
  int	fd;

  (void)tab;
  (void)path;
  if ((home = get_env("HOME=", env_list)) == NULL)
    return (0);
  home += 5;
  if ((file = get_history_name(home)) == NULL)
    return (-1);
  if ((fd = open(file, O_RDONLY)) == -1)
    {
      printf("Error: Can't open history file.\n");
      return (0);
    }
  while ((str = get_next_line(fd)) != NULL)
    {
      printf("%s\n", str);
      free(str);
    }
  free(file);
  close(fd);
  return (0);
}
