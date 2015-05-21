/*
** history.c for shell_get_line in /home/cassin_f/B2/B2-Systeme_Unix/42sh_cassin
**
** Made by François CASSIN
** Login   <cassin_f@epitech.net>
**
** Started on  Mon May 18 04:23:19 2015 François CASSIN
** Last update Wed May 20 18:05:44 2015 danilov dimitri
*/

#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "my_get_line.h"

static int	recup_datas(t_history *history, int fd)
{
  char		*s;

  while ((s = get_next_line(fd)) && history->nb_max < 1000)
    {
      history->history_tab[history->nb_max] = s;
      ++history->nb_max;
    }
  return (0);
}

int		complete_history(t_history *history, t_env *env)
{
  char		*home;
  char		*file;
  int		fd;

  history->nb_max = 0;
  if ((home = get_env("HOME=", env)) == NULL)
    return (0);
  home = home + 5;
  if ((file = malloc(sizeof(char) * (my_strlen(home) +
				     my_strlen(HISTORY_FILE) + 2))) == NULL)
    return (0);
  strcpy(file, home);
  strcat(file, "/");
  strcat(file, HISTORY_FILE);
  if ((fd = open(file, O_RDONLY)) == -1)
    {
      free(file);
      return (0);
    }
  free(file);
  recup_datas(history, fd);
  close(fd);
  return (0);
}
