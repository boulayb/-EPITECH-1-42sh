/*
** clear_screen.c for shell_get_line in /home/cassin_f/B2/B2-Systeme_Unix/42sh_cassin/functions
** 
** Made by François CASSIN
** Login   <cassin_f@epitech.net>
** 
** Started on  Mon May 18 14:26:27 2015 François CASSIN
** Last update Fri May 22 14:23:12 2015 Sebastien BOULOC
*/

#include "my_get_line.h"

static void	decale_bytes_right(t_line *line, int offset)
{
  int		nb_bytes;

  if ((nb_bytes = analyze_char(line->buffer[offset])) == 0)
    ++line->cursor_offset;
  else
    {
      while ((line->cursor_offset < line->nb_char)  && (nb_bytes > 0))
	{
	  ++line->cursor_offset;
	  --nb_bytes;
	}
    }
}

void		foreward(t_params *params, t_line *line)
{
  if (line->cursor_offset < line->nb_char)
    {
      if (((line->cursor_begin + line->cursor_position - 1) %
	   params->caps->column + 1) == params->caps->column)
	{
	  xtputs_param(params->caps->DOWN_str, 1, my_putint, 1);
	  xtputs_param(params->caps->LEFT_str, 1, my_putint,
		       params->caps->column - 1);
	}
      else
	xtputs(params->caps->right_str, 1, my_putint);
      decale_bytes_right(line, line->cursor_offset);
      ++line->cursor_position;
    }
}
