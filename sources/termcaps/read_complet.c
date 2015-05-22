/*
** read_complet.c for shell_get_line in /home/cassin_f/B2/B2-Systeme_Unix/42sh_cassin
**
** Made by François CASSIN
** Login   <cassin_f@epitech.net>
**
** Started on  Mon May 18 00:08:36 2015 François CASSIN
** Last update Fri May 22 13:55:05 2015 Sebastien BOULOC
*/

#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>
#include "my.h"
#include "my_get_line.h"

static int	check_already(t_complet *cmds, char *str)
{
  t_complet	*tmp;

  tmp = cmds->next;
  while (tmp != cmds)
    {
      if (my_strcmp(tmp->name, str) == 1)
	return (1);
      tmp = tmp->next;
    }
  return (0);
}

void		add_elem_to_complet(t_complet *cmds, char *str)
{
  t_complet	*new;

  if ((new = malloc(sizeof(t_complet))) != NULL)
    {
      new->name = str;
      new->next = cmds;
      new->prev = cmds->prev;
      cmds->prev->next = new;
      cmds->prev = new;
    }
}

void		read_path(t_complet *path, DIR *dir, char *path_str)
{
  char		buffer[1024];
  struct stat	s;
  struct dirent	*d;

  while ((d = readdir(dir)) != NULL)
    {
      strcpy(buffer, path_str);
      strcat(buffer, "/");
      strcat(buffer, d->d_name);
      if ((access(buffer, X_OK) != -1) && stat(buffer, &s) != -1)
	if (S_ISREG(s.st_mode))
	  {
	    if (check_already(path, d->d_name) == 0)
	      add_elem_to_complet(path, strdup(d->d_name));
	  }
    }
}

void		read_local(t_complet *path, DIR *dir)
{
  char		buffer[1024];
  struct stat	s;
  struct dirent	*d;

  while ((d = readdir(dir)) != NULL)
    {
      if (access(d->d_name, X_OK) != -1)
	{
	  if (stat(d->d_name, &s) != -1)
	    {
	      strcpy(buffer, d->d_name);
	      if (S_ISDIR(s.st_mode))
		strcat(buffer, "/");
	      if (check_already(path, buffer) == 0)
		add_elem_to_complet(path, strdup(buffer));
	    }
	}
    }
}
