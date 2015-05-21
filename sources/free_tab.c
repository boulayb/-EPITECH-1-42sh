/*
** free_tab.c for minishell1 in /home/cassin_f/B1-Systeme_Unix/PSU_2014_minishell1
** 
** Made by François CASSIN
** Login   <cassin_f@epitech.net>
** 
** Started on  Thu Jan 22 17:35:39 2015 François CASSIN
** Last update Thu May 21 12:54:31 2015 Sebastien BOULOC
*/

#include <stdlib.h>

void	free_tab(char **tab)
{
  int	i;

  i = 0;
  while (tab[i])
    {
      free(tab[i]);
      tab[i] = NULL;
      ++i;
    }
  free(tab);
  tab = NULL;
}
