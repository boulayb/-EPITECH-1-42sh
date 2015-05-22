/*
** get_tab_file.c for shell_get_line in /home/cassin_f/B2/B2-Systeme_Unix/42sh_cassin
**
** Made by François CASSIN
** Login   <cassin_f@epitech.net>
**
** Started on  Mon May 18 17:41:58 2015 François CASSIN
** Last update Fri May 22 12:24:43 2015 Dylan Coodien
*/

#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include "my.h"
#include "my_get_line.h"

int		char_is_in_str(char *str, char c)
{
  int		i;

  i = 0;
  while (str[i])
    {
      if (str[i] == c)
	return (0);
      ++i;
    }
  return (1);
}

void		change_tild_into_home(t_params *params, char *path)
{
  int		i;
  char		*home;

  i = 0;
  if (char_is_in_str(path, '~') == 0)
    {
      while (path[i++] != '~')
	if ((i == 1) || (path[i] == ' ') || (path[i] == '&') ||
	    (path[i] == ';') || (path[i] == '|'))
	  {
	    if ((home = get_env("HOME=", params->env)))
	      {
		home = home + 5;
		go_right(i, path + i - 1, my_strlen(path),
			 my_strlen(home) - 1);
		memcpy(path + i - 1, home, my_strlen(home));
	      }
	  }
    }
}

int		read_folder(t_complet *file, DIR *directory, char *path)
{
  struct dirent	*d;
  struct stat	s;
  char		buffer[1024];

  while ((d = readdir(directory)) != NULL)
    {
      strcpy(buffer, path);
      strcat(buffer, d->d_name);
      if (stat(buffer, &s) == -1)
	return (-1);
      memset(buffer, 0, 1024);
      strcpy(buffer, d->d_name);
      if (S_ISDIR(s.st_mode))
	strcat(buffer, "/");
      add_elem_to_complet(file, strdup(buffer));
    }
  return (0);
}

int		open_file_tab(t_params *params, t_compl_par *complete,
			      char *path)
{
  DIR		*directory;

  change_tild_into_home(params, path);
  if ((directory = opendir(path)) != NULL)
    {
      if ((complete->file_opened = malloc(sizeof(t_complet))) == NULL)
	return (-1);
      complete->file_opened->name = NULL;
      complete->file_opened->next = complete->file_opened;
      complete->file_opened->prev = complete->file_opened;
      if (read_folder(complete->file_opened, directory, path) == -1)
	return (-1);
      closedir(directory);
    }
  return (0);
}

int		get_tab_file(t_params *params, t_compl_par *complete)
{
  int		i;
  char		path[BUFF];

  i = complete->offset_begin - 1;
  while ((i >= 0) && (complete->buffer[i] != ' ') &&
	 (complete->buffer[i] != '|') && (complete->buffer[i] != '&') &&
	 (complete->buffer[i] != ';'))
    --i;
  memset(path, 0, BUFF);
  strncpy(path, complete->buffer + i + 1, complete->offset_begin - i + 1);
  i = my_strlen(path) - 1;
  while (path[i] != '/')
    --i;
  path[i + 1] = 0;
  if (open_file_tab(params, complete, path) == -1)
    return (-1);
  return (0);
}
