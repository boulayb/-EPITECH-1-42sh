/*
** get_42shrc.c for shell_get_line in /home/cassin_f/PSU_2014_42sh/sources/termcaps
** 
** Made by François CASSIN
** Login   <cassin_f@epitech.net>
** 
** Started on  Fri May 22 14:20:05 2015 François CASSIN
** Last update Fri May 22 15:23:19 2015 François CASSIN
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "my_get_line.h"

static char	*get_rcfile_name(char *home)
{
  char		*file;

  if ((file = malloc(sizeof(char) * (my_strlen(home) +
				     my_strlen(RC_FILE) + 2))) == NULL)
    return (NULL);
  strcpy(file, home);
  strcat(file, "/");
  strcat(file, RC_FILE);
  return (file);
}

static char	*get_line_rc(int *fd, int *ret, t_env *env)
{
  char		*s;

  if (*fd == -1)
    return (NULL);
  s = get_next_line(*fd);
  if (s != NULL)
    {
      *ret = 2;
      return (s);
    }
  close(*fd);
  *fd = -1;
  *ret = 0;
  disp_prompt(env);
  return (NULL);
}

char		*check_42shrc(t_env *env, int *ret)
{
  char		*home;
  char		*file;
  static int	fd;

  if (fd == 0)
    {
      if ((home = get_env("HOME=", env)) == NULL)
	return (NULL);
      if ((file = get_rcfile_name(home + 5)) == NULL)
	return (NULL);
      if ((fd = open(file, O_RDONLY)) == -1)
	{
	  *ret = 0;
	  free(file);
	  return (NULL);
	}
      free(file);
    }
  return (get_line_rc(&fd, ret, env));
}
