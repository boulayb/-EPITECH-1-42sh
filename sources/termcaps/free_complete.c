/*
** free_complete.c for shell_get_line in /home/cassin_f/42sh_cassin
** 
** Made by François CASSIN
** Login   <cassin_f@epitech.net>
** 
** Started on  Wed May 20 14:52:49 2015 François CASSIN
** Last update Wed May 20 14:55:01 2015 François CASSIN
*/

#include <stdlib.h>
#include "my_get_line.h"

void		free_complete(t_complet *to_free)
{
  t_complet	*tmp;
  t_complet	*tmp2;

  if (to_free != NULL)
    {
      tmp = to_free->next;
      while (tmp != to_free)
	{
	  tmp2 = tmp->next;
	  free(tmp);
	  tmp = tmp2;
	}
      free(to_free);
    }
}
