/*
** clear_screen.c for shell_get_line in /home/cassin_f/B2/B2-Systeme_Unix/42sh_cassin/functions
** 
** Made by François CASSIN
** Login   <cassin_f@epitech.net>
** 
** Started on  Mon May 18 14:26:27 2015 François CASSIN
** Last update Fri May 22 19:03:38 2015 François CASSIN
*/

#include <stdlib.h>
#include <string.h>
#include "my_get_line.h"

void		change_new_current(t_history *history, t_line *line)
{
  if (history->history_tab != NULL)
    {
      if (history->history_tab[history->nb_max -
			       (line->history_offset)] != NULL)
	free(history->history_tab[history->nb_max -
				  (line->history_offset)]);
      history->history_tab[history->nb_max -
			   (line->history_offset)] = strdup(line->buffer);
    }
}

void		up_histo(t_params *params, t_line *line)
{
  char		*str;

  if (line->history_offset < params->history->nb_max)
    {
      change_new_current(params->history, line);
      memset(line->buffer, 0, BUFF);
      str = params->history->history_tab[params->history->nb_max -
					 (line->history_offset + 1)];
      if (str != NULL)
	{
	  memcpy(line->buffer, str, my_strlen(str));
	  line->cursor_offset = my_strlen(line->buffer);
	  line->nb_char = line->cursor_offset;
	  line->cursor_position = count_char_pos(line->buffer, line->nb_char);
	  line->nb_char_pos = line->cursor_position;
	}
      refresh_screen(line, line->cursor_position, line->buffer, params->caps);
      ++line->history_offset;
    }
}
