/*
** tabtostr.c for 42sh in /home/boulay_b/Work/SE2/PSU/42sh/PSU_2014_42sh
**
** Made by Arnaud Boulay
** Login   <boulay_b@epitech.net>
**
** Started on  Sun May 24 00:19:46 2015 Arnaud Boulay
** Last update Sun May 24 02:38:42 2015 Arnaud Boulay
*/

#include <string.h>
#include <stdlib.h>
#include "my.h"

static char	*my_strcatspace(char *dest, char *src)
{
  int		i;
  int		j;

  i = 0;
  j = -1;
  while (dest[i] != '\0')
    ++i;
  dest[i] = ' ';
  while (src[++j] != '\0')
    dest[++i] = src[j];
  dest[++i] = '\0';
  return (dest);
}

char		*my_tabtostr(char **tab)
{
  char		*str;
  int		i;
  int		len;

  len = 0;
  i = -1;
  while (tab[++i] != NULL)
    len += strlen(tab[i]);
  len += tablen(tab);
  i = 0;
  if ((str = malloc(sizeof(char) * len)) == NULL)
    return (NULL);
  str = strcpy(str, tab[0]);
  while (tab[++i] != NULL)
    str = my_strcatspace(str, tab[i]);
  return (str);
}
