/*
** del_char.c for shell_get_line in /home/cassin_f/B2/B2-Systeme_Unix/42sh_cassin/functions
** 
** Made by François CASSIN
** Login   <cassin_f@epitech.net>
** 
** Started on  Mon May 18 14:25:02 2015 François CASSIN
** Last update Wed May 20 11:32:19 2015 François CASSIN
*/

#include "my_get_line.h"

void		delete_spec_char(t_line *line, int offset)
{
  int		nb_bytes;

  if ((nb_bytes = analyze_char(line->buffer[offset])) == 1)
    {
      while ((nb_bytes = analyze_char(line->buffer[line->cursor_offset])) == 1)
	{
	  go_left(line->cursor_offset, line->buffer, line->nb_char);
	  --line->nb_char;
	  --line->cursor_offset;
	}
      go_left(line->cursor_offset, line->buffer, line->nb_char);
      --line->nb_char;
      --line->cursor_offset;
    }
  else
    {
      while (nb_bytes > 0)
	{
	  go_left(line->cursor_offset, line->buffer, line->nb_char);
	  --line->nb_char;
	  --nb_bytes;
	}
    }
}

void		del_char(t_params *params, t_line *line)
{
  int		nb_bytes;

  if (line->cursor_offset < line->nb_char)
    {
      if ((nb_bytes = analyze_char(line->buffer[line->cursor_offset])) == 0)
	{
	  go_left(line->cursor_offset, line->buffer, line->nb_char);
	  line->nb_char = line->nb_char - 1;
	}
      else
	delete_spec_char(line, line->cursor_offset);
      --line->nb_char_pos;
      refresh_screen(line, line->cursor_position, line->buffer, params->caps);
    }
}
