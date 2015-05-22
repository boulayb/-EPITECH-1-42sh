/*
** clear_screen.c for shell_get_line in /home/cassin_f/B2/B2-Systeme_Unix/42sh_cassin/functions
** 
** Made by François CASSIN
** Login   <cassin_f@epitech.net>
** 
** Started on  Mon May 18 14:26:27 2015 François CASSIN
** Last update Fri May 22 13:32:25 2015 Sebastien BOULOC
*/

#include <stdlib.h>
#include <string.h>
#include "my_get_line.h"

void	down_histo(t_params *params, t_line *line)
{
  char	*str;

  if (line->history_offset != 0)
    {
      change_new_current(params->history, line);
      memset(line->buffer, 0, BUFF);
      str = params->history->history_tab[params->history->nb_max -
					 (line->history_offset - 1)];
      if (str != NULL)
	{
	  memcpy(line->buffer, str, my_strlen(str));
	  line->cursor_offset = my_strlen(line->buffer);
	  line->nb_char = line->cursor_offset;
	  line->cursor_position = count_char_pos(line->buffer, line->nb_char);
	  line->nb_char_pos = line->cursor_position;
	}
      refresh_screen(line, line->cursor_position, line->buffer, params->caps);
      --line->history_offset;
    }
}
