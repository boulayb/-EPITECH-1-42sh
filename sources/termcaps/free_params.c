/*
** free_params.c for  in /home/cassin_f/42sh_cassin
** 
** Made by François CASSIN
** Login   <cassin_f@epitech.net>
** 
** Started on  Wed May 20 14:58:39 2015 François CASSIN
** Last update Wed May 20 15:21:07 2015 François CASSIN
*/

#include <stdlib.h>
#include "my_get_line.h"

void		free_history(t_history *history)
{
  int		i;

  while (i < history->nb_max)
    {
      free(history->history_tab[i]);
      ++i;
    }
}

void		free_params(t_params *params)
{
  free_complete(params->completion->path);
  free_complete(params->completion->local);
}
