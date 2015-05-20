/*
** free_tab.c for shell_get_line.c in /home/cassin_f/B2/B2-Systeme_Unix/42sh_cassin
** 
** Made by François CASSIN
** Login   <cassin_f@epitech.net>
** 
** Started on  Mon May 18 00:04:55 2015 François CASSIN
** Last update Mon May 18 00:05:25 2015 François CASSIN
*/

#include <stdlib.h>

void		free_tab(char **tab)
{
  int		i;

  i = 0;
  while (tab[i])
    {
      free(tab[i]);
      i = i + 1;
    }
  free(tab);
}
