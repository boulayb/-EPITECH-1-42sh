/*
** clear_screen.c for shell_get_line in /home/cassin_f/B2/B2-Systeme_Unix/42sh_cassin/functions
** 
** Made by François CASSIN
** Login   <cassin_f@epitech.net>
** 
** Started on  Mon May 18 14:26:27 2015 François CASSIN
** Last update Wed May 20 11:41:23 2015 François CASSIN
*/

#include "my_get_line.h"

void		delete_back_spec_char(t_line *line, int offset)
{
  int		nb_bytes;

  if ((nb_bytes = analyze_char(line->buffer[offset - 1])) == 1)
    {
      while (line->cursor_offset != 0 &&
	     (nb_bytes = analyze_char(line->buffer[line->cursor_offset - 1]))
	     == 1)
	{
	  --line->cursor_offset;
	  go_left(line->cursor_offset, line->buffer, line->nb_char);
	  --line->nb_char;
	}
      --line->cursor_offset;
      go_left(line->cursor_offset, line->buffer, line->nb_char);
      --line->nb_char;
    }
}

void		del_back(t_params *params, t_line *line)
{
  int		nb_bytes;

  if (line->cursor_offset > 0)
    {
      xtputs(params->caps->left_str, 1, my_putint);
      if ((nb_bytes =
	   analyze_char(line->buffer[line->cursor_offset - 1])) == 0)
	{
	  --line->cursor_offset;
	  go_left(line->cursor_offset, line->buffer, line->nb_char);
	  --line->nb_char;
	}
      else
	delete_back_spec_char(line, line->cursor_offset);
      --line->nb_char_pos;
      --line->cursor_position;
      refresh_screen(line, line->cursor_position, line->buffer, params->caps);
    }
}
