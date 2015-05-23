/*
** strtowordtab.c for 42sh in /home/boulay_b/Work/SE2/PSU/42sh/PSU_2014_42sh
**
** Made by Arnaud Boulay
** Login   <boulay_b@epitech.net>
**
** Started on  Sat May 23 18:35:27 2015 Arnaud Boulay
** Last update Sat May 23 18:59:16 2015 Arnaud Boulay
*/

#include <stdlib.h>
#include "my.h"

static int	count_words(char *str, char *sep)
{
  int		words;
  int		i;

  i = -1;
  if (count_quotes(str) == -1)
    return (0);
  words = 0;
  while (str[++i] != '\0')
    if (is_cinside(sep, str[i]) == 0 && str[i] != '\t' &&
	(is_cinside(sep, str[i + 1]) == 1 ||
	 str[i + 1] == '\t' || str[i + 1] == '\0'))
      ++words;
  return (words);
}

static int	my_wordlen(char *str, int *i, char *sep)
{
  int		j;

  j = 0;
  while (str[++(*i)] != '\0')
    if (is_cinside(sep, str[*i]) == 0 && str[*i] != '\t')
      {
	++j;
	if (is_cinside(sep, str[*i + 1]) == 1 ||
	    str[*i + 1] == '\t' || str[*i + 1] == '\0')
	  return (j);
      }
  return (-1);
}

static char	*my_wordcpy(char *tab, char *str, int *i, char *sep)
{
  int		j;

  j = -1;
  while (str[++(*i)] != '\0')
    if (is_cinside(sep, str[*i]) == 0 && str[*i] != '\t')
      {
	tab[++j] = str[*i];
	if (is_cinside(sep, str[*i + 1]) == 1 ||
	    str[*i + 1] == '\t' || str[*i + 1] == '\0')
	  {
	    tab[++j] = '\0';
	    return (tab);
	  }
      }
  return (NULL);
}

char		**my_strtowordtab(char *str, char *sep)
{
  char		**tab;
  int		words;
  int		len;
  int		i;
  int		j;
  int		k;

  i = -1;
  j = -1;
  k = -1;
  if (str == NULL)
    return (NULL);
  words = count_words(str, sep);
  if ((tab = malloc(sizeof(char *) * (words + 1))) == NULL)
    return (NULL);
  while (++i < words)
    {
      if ((len = my_wordlen(str, &j, sep)) == -1 ||
	  (tab[i] = malloc(sizeof(char) * (len + 1))) == NULL)
	return (NULL);
      tab[i] = my_wordcpy(tab[i], str, &k, sep);
    }
  tab[i] = NULL;
  return (tab);
}
