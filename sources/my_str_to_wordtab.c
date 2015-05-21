/*
** my_str_to_wordtab.c for minishell1 in /home/cassin_f/B1-Systeme_Unix/PSU_2014_minishell1
**
** Made by François CASSIN
** Login   <cassin_f@epitech.net>
**
** Started on  Thu Jan 22 12:43:23 2015 François CASSIN
** Last update Wed May 20 19:37:51 2015 danilov dimitri
*/

#include <string.h>
#include <stdlib.h>

static int	how_much_words(char *str)
{
  int		i;
  int		count;

  i = 0;
  count = 0;
  while (str[i])
    {
      if (str[i] != ' ' && str[i] != '\t' && str[i] != '"')
	{
	  count = count + 1;
	  while (str[i] != ' ' && str[i] != '\t' && str[i] && str[i] != '"')
	    i = i + 1;
	}
      else if (str[i] == '"')
	{
	  count = count + 1;
	  i = i + 1;
	  while (str[i] != '"' && str[i])
	    i = i + 1;
	  if (str[i] == '"')
	    i = i + 1;
	}
      else
	i = i + 1;
    }
  return (count);
}

char	**malloc_str_to_tab(char *str)
{
  char	**tab;
  int	i;
  int	size;

  size = how_much_words(str);
  i = 0;
  if ((tab = malloc(sizeof(char *) * (size + 1))) == NULL)
    return (NULL);
  while (i < size)
    {
      if ((tab[i] = malloc(sizeof(char) * (strlen(str) + 1))) == NULL)
	return (NULL);
      i = i + 1;
    }
  tab[i] = NULL;
  return (tab);
}

void	copy_in_quotes(char *str, char **tab, int *i, int *n)
{
  int	j;

  j = 0;
  *i = *i + 1;
  while (str[*i] != '"' && str[*i])
    {
      tab[*n][j] = str[*i];
      *i = *i + 1;
      j = j + 1;
    }
  tab[*n][j] = 0;
  if (str[*i] == '"')
    *i = *i + 1;
}

void	copy_my_word(char **tab, char *str, int *i, int *n)
{
  int	j;

  j = 0;
  if (str[*i])
    {
      if (str[*i] == '"')
	copy_in_quotes(str, tab, i, n);
      else
	{
	  while (str[*i] && str[*i] != ' ' && str[*i] != '\t' &&
		 str[*i] != '"')
	    {
	      tab[*n][j] = str[*i];
	      *i = *i + 1;
	      j = j + 1;
	    }
	  tab[*n][j] = 0;
	}
      *n = *n + 1;
    }
}

char	**my_str_to_wordtab(char *str)
{
  int	i;
  char	**tab;
  int	n;

  i = 0;
  n = 0;
  if ((tab = malloc_str_to_tab(str)) == NULL)
    return (NULL);
  while (str[i])
    {
      while (str[i] && (str[i] == ' ' || str[i] == '\t'))
	i = i + 1;
      copy_my_word(tab, str, &i, &n);
    }
  tab[n] = NULL;
  return (tab);
}
