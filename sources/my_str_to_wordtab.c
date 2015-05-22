/*
** my_str_to_wordtab.c for minishell1 in /home/cassin_f/B1-Systeme_Unix/PSU_2014_minishell1
**
** Made by François CASSIN
** Login   <cassin_f@epitech.net>
**
** Started on  Thu Jan 22 12:43:23 2015 François CASSIN
** Last update Fri May 22 18:10:04 2015 Sebastien BOULOC
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
	  ++count;
	  while (str[i] != ' ' && str[i] != '\t' && str[i] && str[i] != '"')
	    ++i;
	}
      else if (str[i] == '"')
	{
	  ++count;
	  ++i;
	  while (str[i] != '"' && str[i])
	    ++i;
	  if (str[i] == '"')
	    ++i;
	}
      else
	++i;
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
      ++i;
    }
  tab[i] = NULL;
  return (tab);
}

void	copy_in_quotes(char *str, char **tab, int *i, int *n)
{
  int	j;

  j = 0;
  ++(*i);
  while (str[*i] != '"' && str[*i])
    {
      tab[*n][j] = str[*i];
      ++(*i);
      ++j;
    }
  tab[*n][j] = 0;
  if (str[*i] == '"')
    ++(*i);
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
	      ++(*i);
	      ++j;
	    }
	  tab[*n][j] = 0;
	}
      ++(*n);
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
	++i;
      copy_my_word(tab, str, &i, &n);
    }
  tab[n] = NULL;
  return (tab);
}
