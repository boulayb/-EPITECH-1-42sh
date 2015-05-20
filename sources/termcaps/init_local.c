/*
** init_local.c for shell_get_line in /home/cassin_f/B2/B2-Systeme_Unix/42sh_cassin
** 
** Made by François CASSIN
** Login   <cassin_f@epitech.net>
** 
** Started on  Mon May 18 00:28:37 2015 François CASSIN
** Last update Mon May 18 00:40:44 2015 François CASSIN
*/

#include <sys/types.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include "my_get_line.h"

int		init_local(t_complet *local)
{
  DIR		*dir;
  struct dirent	*d;
  struct stat	s;
  char		buffer[1024];

  if ((dir = opendir(".")) != NULL)
    {
      while ((d = readdir(dir)) != NULL)
	{
	  strcpy(buffer, d->d_name);
	  if (stat(buffer, &s) == -1)
	    return (-1);
	  if (S_ISDIR(s.st_mode))
	    strcat(buffer, "/");
	  add_elem_to_complet(local, strdup(buffer));
	}
    }
  closedir(dir);
  return (0);
}
