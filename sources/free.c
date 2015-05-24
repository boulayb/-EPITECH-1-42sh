/*
** free.c for free in /home/danilo_d/semestre2/PSU_2014_42sh/sources
**
** Made by danilov dimitri
** Login   <danilo_d@epitech.eu>
**
** Started on  Sat May 23 15:50:53 2015 danilov dimitri
** Last update Sun May 24 19:15:51 2015 Sebastien BOULOC
*/

#include <stdlib.h>
#include "sh42.h"

void		free_list2(t_data *data)
{
  t_data	*tmp;

  tmp = data->next;
  while (tmp != data)
    {
      tmp = tmp->next;
      if (tmp->back->line != NULL)
	free(tmp->back->line);
      free(tmp->back);
    }
  if (data != NULL)
    free(data);
}
