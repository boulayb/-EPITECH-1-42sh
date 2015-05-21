/*
** aff_all_possibilities.c for shell_get_line in /home/cassin_f/B2/B2-Systeme_Unix/42sh_cassin
**
** Made by François CASSIN
** Login   <cassin_f@epitech.net>
**
** Started on  Mon May 18 22:51:43 2015 François CASSIN
** Last update Thu May 21 14:16:04 2015 Sebastien BOULOC
*/

#include <unistd.h>
#include <string.h>
#include "my_get_line.h"

static int	count_elem(t_complet *list)
{
  t_complet	*tmp;
  int		count;

  count = 0;
  tmp = list->next;
  while (tmp != list)
    {
      ++count;
      tmp = tmp->next;
    }
  return (count);
}

char		wait_for_y_or_n()
{
  char		buffer[BUFF];
  int		ret;

  if ((ret = read(0, buffer, BUFF)) == -1)
    return ('n');
  buffer[ret] = 0;
  while (strcmp(buffer, "n") != 0 && strcmp(buffer, "y"))
    {
      if ((ret = read(0, buffer, BUFF)) == -1)
	return ('n');
      buffer[ret] = 0;
    }
  return (buffer[0]);
}

void		aff_possibilities(t_complet *matched)
{
  t_complet	*tmp;

  tmp = matched->next;
  while (tmp != matched)
    {
      my_fputstr(1, tmp->name);
      my_fputchar(1, '\n');
      tmp = tmp->next;
    }
}

void		aff_all_possibilities(t_params *params, t_complet *matched)
{
  int		count_possib;
  char		answer;

  count_possib = count_elem(matched);
  answer = 'y';
  if (params->caps->line - 1 < count_possib)
    {
      my_fputstr(1, "Display all ");
      my_fputnbr(1, count_possib);
      my_fputstr(1, " possibilities? (y or n)");
      answer = wait_for_y_or_n();
    }
  if (answer == 'y')
    aff_possibilities(matched);
  else
    my_fputchar(1, '\n');
}
