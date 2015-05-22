/*
** new_history_file.c for shell_get_line in /home/cassin_f/42sh_cassin
**
** Made by François CASSIN
** Login   <cassin_f@epitech.net>
**
** Started on  Thu May 21 17:11:56 2015 François CASSIN
** Last update Fri May 22 12:14:35 2015 Dylan Coodien
*/

#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "my_get_line.h"

void		write_history_into_file(t_line *line,
					t_history *history, int fd)
{
  int		i;

  if (history->nb_max == 999)
    i = 1;
  else
    i = 0;
  while (i < history->nb_max)
    {
      if (history->history_tab[i] != NULL)
	{
	  my_fputstr(fd, history->history_tab[i]);
	}
      my_fputchar(fd, '\n');
      ++i;
    }
  if ((i != 0 && (strcmp(line->buffer, history->history_tab[i - 1]) != 0)) ||
      i == 0)
    {
      if (line->buffer[0] != 0)
	{
	  my_fputstr(fd, line->buffer);
	  my_fputchar(fd, '\n');
	}
    }
}

void		rewrite_history(t_line *line, t_history *history, t_env *env)
{
  char		*home;
  char		*file;
  int		fd;

  if ((home = get_env("HOME=", env)) != NULL)
    {
      home = home + 5;
      if ((file = get_history_name(home)) != NULL)
	{
	  if ((fd = open(file, O_CREAT | O_WRONLY | O_TRUNC,
			 S_IRUSR | S_IWUSR)) == -1)
	    free(file);
	  else
	    {
	      write_history_into_file(line, history, fd);
	      free(file);
	      close(fd);
	    }
	}
    }
}
