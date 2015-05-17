/*
** free_tab.c for minishell1 in /home/cassin_f/B1-Systeme_Unix/PSU_2014_minishell1
** 
** Made by François CASSIN
** Login   <cassin_f@epitech.net>
** 
** Started on  Thu Jan 22 17:35:39 2015 François CASSIN
** Last update Wed Jan 28 18:34:22 2015 François CASSIN
*/

#include <stdlib.h>

void	free_tab(char **tab)
{
  int	i;

  while (tab[i])
    {
      free(tab[i]);
      tab[i] = NULL;
      i = i + 1;
    }
  free(tab);
  tab = NULL;
}
