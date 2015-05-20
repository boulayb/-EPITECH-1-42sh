/*
** end_line.c for shell_get_line in /home/cassin_f/B2/B2-Systeme_Unix/42sh_cassin/functions
** 
** Made by François CASSIN
** Login   <cassin_f@epitech.net>
** 
** Started on  Mon May 18 14:25:58 2015 François CASSIN
** Last update Wed May 20 11:06:41 2015 François CASSIN
*/

#include "my_get_line.h"

void		end_line(t_params *params, t_line *line)
{
  if (line->cursor_offset < line->nb_char)
    {
      xtputs(params->caps->rescu_str, 1, my_putint);
      if (line->line_nb)
	xtputs_param(params->caps->DOWN_str, 1, my_putint, line->line_nb);
      if ((line->cursor_begin + line->nb_char_pos - 1) % params->caps->column -
	  (line->cursor_begin - 1) > 0)
	xtputs_param(params->caps->RIGHT_str, 1, my_putint,
	       (line->cursor_begin + line->nb_char_pos - 1) %
	       params->caps->column - (line->cursor_begin - 1));
      else if ((line->cursor_begin + line->nb_char_pos - 1) %
	       params->caps->column - (line->cursor_begin - 1) < 0)
	xtputs_param(params->caps->LEFT_str, 1, my_putint,
	       -((line->cursor_begin + line->nb_char_pos - 1) %
		 params->caps->column - (line->cursor_begin - 1)));
    }
  line->cursor_offset = line->nb_char;
  line->cursor_position = line->nb_char_pos;
}
