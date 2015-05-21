/*
** free_params.c for  in /home/cassin_f/42sh_cassin
** 
** Made by François CASSIN
** Login   <cassin_f@epitech.net>
** 
** Started on  Wed May 20 14:58:39 2015 François CASSIN
** Last update Thu May 21 17:15:56 2015 François CASSIN
*/

#include <stdlib.h>
#include "my_get_line.h"

void		free_history(t_history *history)
{
  int		i;

  while (i < 1000)
    {
      if (history->history_tab[i] != NULL)
	free(history->history_tab[i]);
      ++i;
    }
}

void		free_params(t_params *params)
{
  free_complete(params->completion->path);
  free_complete(params->completion->local);
}
