/*
** free_params.c for  in /home/cassin_f/42sh_cassin
** 
** Made by François CASSIN
** Login   <cassin_f@epitech.net>
** 
** Started on  Wed May 20 14:58:39 2015 François CASSIN
** Last update Fri May 22 14:43:05 2015 Sebastien BOULOC
*/

#include <stdlib.h>
#include "my_get_line.h"

static void	free_history(t_history *history)
{
  int		i;

  i = 0;
  while (i < 999)
    {
      if (history->history_tab[i] != NULL)
	free(history->history_tab[i]);
      ++i;
    }
}

static void	free_caps(t_caps *cap)
{
  free(cap->clear_str);
  free(cap->down_str);
  free(cap->DOWN_str);
  free(cap->up_str);
  free(cap->UP_str);
  free(cap->left_str);
  free(cap->LEFT_str);
  free(cap->right_str);
  free(cap->RIGHT_str);
  free(cap->cl_cureos_str);
  free(cap->savecu_str);
  free(cap->rescu_str);
}

void		free_params(t_params *params)
{
  free_complete(params->completion->path);
  free_complete(params->completion->local);
  free_caps(params->caps);
  free_history(params->history);
}
