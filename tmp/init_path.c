/*
** init_path.c for shell_get_line in /home/cassin_f/B2/B2-Systeme_Unix/42sh_cassin
** 
** Made by François CASSIN
** Login   <cassin_f@epitech.net>
** 
** Started on  Sun May 17 23:47:38 2015 François CASSIN
** Last update Mon May 18 03:47:50 2015 François CASSIN
*/

#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <dirent.h>
#include "my_get_line.h"

static int      how_much_words(char *str)
{
  int           i;
  int           count;

  i = 0;
  count = 0;
  while (str[i])
    {
      if (str[i] != ':')
	{
          count = count + 1;
          while (str[i] != ':' && str[i])
            i = i + 1;
        }
      i = i + 1;
    }
  return (count);
}

static char     **malloc_str_to_tab(char *str)
{
  char          **tab;
  int           i;
  int           size;

  size = how_much_words(str);
  i = 0;
  if ((tab = malloc(sizeof(char *) * (size + 1))) == NULL)
    return (NULL);
  while (i < size)
    {
      if ((tab[i] = malloc(sizeof(char) * (my_strlen(str) + 1))) == NULL)
        return (NULL);
      i = i + 1;
    }
  tab[i] = NULL;
  return (tab);
}

char    **copy_path_to_wordtab(char *str)
{
  int   i;
  char  **tab;
  int   n;
  int   j;

  i = 0;
  n = 0;
  if ((tab = malloc_str_to_tab(str)) == NULL)
    return (NULL);
  while (str[i])
    {
      while (str[i] == ':' && str[i])
        i = i + 1;
      j = 0;
      while (str[i] != ':' && str[i])
        {
          tab[n][j] = str[i];
          i = i + 1;
          j = j + 1;
        }
      tab[n][j] = 0;
      n = n + 1;
    }
  tab[n] = NULL;
  return (tab);
}

int		init_path(t_complet *path, t_env *env)
{
  DIR		*dir;
  char		**path_tab;
  char		*path_str;
  int		i;

  if ((path_str = get_env("PATH=", env) + 5) == NULL)
    return (-1);
  if ((path_tab = copy_path_to_wordtab(path_str)) == NULL)
    return (-1);
  i = -1;
  while (path_tab[++i])
    {
      if ((dir = opendir(path_tab[i])) != NULL)
	{
	  read_path(path, dir, path_tab[i]);
	  closedir(dir);
	}
    }
  if ((dir = opendir(".")) != NULL)
    {
      read_local(path, dir);
      closedir(dir);
    }
  free_tab(path_tab);
  return (0);
}
