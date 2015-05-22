/*
** clear_screen.c for shell_get_line in /home/cassin_f/B2/B2-Systeme_Unix/42sh_cassin/functions
** 
** Made by François CASSIN
** Login   <cassin_f@epitech.net>
** 
** Started on  Mon May 18 14:26:27 2015 François CASSIN
** Last update Fri May 22 14:11:55 2015 Sebastien BOULOC
*/

#include <stdlib.h>
#include <string.h>
#include "my_get_line.h"

static int	get_word_begin(int offset_cur, char buff[])
{
  int		i;

  i = offset_cur;
  buff[i] = 0;
  while ((i >= 0) && (buff[i] != ' ') && (buff[i] != ';') &&
	 (buff[i] != '&') && (buff[i] != '|') && (buff[i] != '/'))
    --i;
  ++i;
  return (i);
}

static int	get_word_type(t_compl_par *complete)
{
  int		i;

  if (complete->offset_begin == 0)
    return (WORD);
  else if ((complete->buffer[complete->offset_begin - 1] == ' ') ||
	   (complete->buffer[complete->offset_begin - 1] == '|') ||
	   (complete->buffer[complete->offset_begin - 1] == ';') ||
	   (complete->buffer[complete->offset_begin - 1] == '&'))
    {
      i = complete->offset_begin - 1;
      while (complete->buffer[i] == ' ')
	--i;
      if ((complete->buffer[i] == '|') || (complete->buffer[i] == '&') ||
	  (complete->buffer[i] == ';'))
	return (WORD);
    }
  else if (complete->buffer[complete->offset_begin - 1] == '/')
    return (FILE);
  return (UNKNOWN);
}

static void	order_by_asc(t_complet *to_order)
{
  t_complet	*tmp;
  char		*tmp_str;

  tmp = to_order->next;
  if (tmp->name != NULL && tmp->next->name != NULL)
    {
      while (tmp != to_order)
	{
	  if (tmp->next->name != NULL)
	    {
	      if (strcmp(tmp->name, tmp->next->name) < 0)
		{
		  tmp_str = tmp->name;
		  tmp->name = tmp->next->name;
		  tmp->next->name = tmp_str;
		  tmp = to_order->next;
		}
	    }
	  tmp = tmp->next;
	}
    }
}

static int	get_matched_str(t_compl_par *complete, t_complet *list_tab)
{
  t_complet	*tmp;

  if (list_tab == NULL)
    {
      complete->list_of_matched = NULL;
      return (0);
    }
  if ((complete->list_of_matched = malloc(sizeof(t_complet))) == NULL)
    return (-1);
  complete->list_of_matched->name = NULL;
  complete->list_of_matched->next = complete->list_of_matched;
  complete->list_of_matched->prev = complete->list_of_matched;
  tmp = list_tab->next;
  while (tmp != list_tab)
    {
      if (strncmp(tmp->name, complete->buffer + complete->offset_begin,
		  my_strlen(complete->buffer + complete->offset_begin)) == 0)
	add_elem_to_complet(complete->list_of_matched, strdup(tmp->name));
      tmp = tmp->next;
    }
  order_by_asc(complete->list_of_matched);
  return (0);
}

void		complete(t_params *params, t_line *line)
{
  t_compl_par	complete;
  t_complet	*list_tab;

  strcpy(complete.buffer, line->buffer);
  complete.offset_begin = get_word_begin(line->cursor_offset, complete.buffer);
  complete.file_opened = NULL;
  if ((complete.type = get_word_type(&complete)) == FILE)
    get_tab_file(params, &complete);
  if (complete.type == FILE)
    list_tab = complete.file_opened;
  else if (complete.offset_begin == line->cursor_offset)
    list_tab = params->completion->local;
  else if (complete.type == WORD)
    list_tab = params->completion->path;
  else
    list_tab = params->completion->local;
  if (get_matched_str(&complete, list_tab) != -1)
    complete_matched_tab(&complete, line, params);
  free_complete(complete.file_opened);
}
