/*
** my_str_to_cmdtab.c for my_str_to_cmdtab.c in /home/bouloc_s/str_to_tab_42sh
**
** Made by Sebastien BOULOC
** Login   <bouloc_s@epitech.net>
**
** Started on  Tue May 19 15:43:11 2015 Sebastien BOULOC
** Last update Sun May 24 20:10:51 2015 Sebastien BOULOC
*/

#include <stdlib.h>

static int	my_str_to_cmdtab5(char **tab, char *str, int *i, int *a)
{
  int		b;

  b = 0;
  while (str[*i] != ' ' && str[*i] != '\t' && str[*i] != '\n' && str[*i]
	 && str[*i] != '|' && str[*i] != '&' && str[*i] != ';'
	 && str[*i] != '>' && str[*i] != '<' && str[*i] != '"')
    {
      tab[*a][b] = str[*i];
      ++b;
      ++(*i);
    }
  tab[*a][b] = '\0';
  return (b);
}

static int	my_str_to_cmdtab4(char **tab, char *str, int *i, int *a)
{
  int		b;

  b = 0;
  if ((str[*i] == ';') || (str[*i] == '|' && str[*i + 1] != '|') ||
      (str[*i] == '&' && str[*i + 1] != '&') || (str[*i] == '>' &&
       str[*i + 1] != '>') || (str[*i] == '<' && str[*i + 1] != '<'))
    {
      tab[*a][b] = str[*i];
      ++b;
      ++(*i);
    }
  else
    {
      while ((str[*i] == '|' || str[*i] == '&' || str[*i] == '>' ||
	      str[*i] == '<') && str[*i] != '\n' && str[*i] &&
	     str[*i] != ' ' && str[*i] != '\t' && b != 2)
	{
	  tab[*a][b] = str[*i];
	  ++b;
	  ++(*i);
	}
    }
  tab[*a][b] = '\0';
  return (b);
}

static char	**my_str_to_cmdtab3(char **tab, char *str, int *i, int *a)
{
  int		b;

  b = 0;
  if (str[*i] == '|' || str[*i] == '&' || str[*i] == ';'
      || str[*i] == '>' || str[*i] == '<')
    b = my_str_to_cmdtab4(tab, str, i, a);
  else if (str[*i] == '"')
    {
      ++(*i);
      while (str[*i] != '"' && str[*i] != '\n' && str[*i])
	{
	  tab[*a][b] = str[*i];
	  ++b;
	  ++(*i);
	}
      if (str[*i] != '\0' && str[*i] != '\n')
	++(*i);
      tab[*a][b] = '\0';
    }
  else
    b = my_str_to_cmdtab5(tab, str, i, a);
  return (tab);
}

static char	**my_str_to_cmdtab2(char **tab, char *str, int size)
{
  int		i;
  int		a;

  a = 0;
  i = 0;
  while (str[i] != '\0' && str[i] != '\n')
    {
      while ((str[i] == ' ' || str[i] == '\t') && str[i] != '\n' && str[i])
	++i;
      if ((tab[a] = malloc(size + 1)) == NULL)
	return (NULL);
      if (my_str_to_cmdtab3(tab, str, &i, &a) == NULL)
	return (NULL);
      while ((str[i] == ' ' || str[i] == '\t') && str[i] != '\n' && str[i])
	++i;
      ++a;
    }
  tab[a] = NULL;
  return (tab);
}

char		**my_str_to_cmdtab(char *str)
{
  int		size;
  char		**tab;

  size = 0;
  if (str == NULL)
    return (NULL);
  while (str[size] != '\0' && str[size] != '\n')
    ++size;
  if ((tab = malloc(sizeof(char *) * (size + 1))) == NULL)
    return (NULL);
  if ((tab = my_str_to_cmdtab2(tab, str, size)) == NULL)
    return (NULL);
  return (tab);
}
