/*
** refresh_screen.c for shell_get_line.c in /home/cassin_f/B2/B2-Systeme_Unix/42sh_cassin
** 
** Made by François CASSIN
** Login   <cassin_f@epitech.net>
** 
** Started on  Mon May 18 01:59:34 2015 François CASSIN
** Last update Wed May 20 11:07:33 2015 François CASSIN
*/

#include "my_get_line.h"

// 28 lignes

void		refresh_screen(t_line *line, int cursor_off, char buffer[],
			       t_caps *cap)
{
  int		save;

  save = line->line_nb;
  line->line_nb = (cursor_off + line->cursor_begin - 1) / cap->column;
  if ((line->line_begin + line->line_nb >= cap->line + 1) &&
      (save != line->line_nb) && ((line->line_begin--) || 1))
    {
      my_fputchar(1, '\n');
      xtputs(cap->rescu_str, 1, my_putint);
      xtputs_param(cap->UP_str, 1, my_putint, 1);
      xtputs(cap->savecu_str, 1, my_putint);
    }
  xtputs(cap->rescu_str, 1, my_putint);
  xtputs(cap->cl_cureos_str, 1, my_putint);
  my_fputstr(1, buffer);
  xtputs(cap->rescu_str, 1, my_putint);
  if (line->line_nb)
    xtputs_param(cap->DOWN_str, 1, my_putint, line->line_nb);
  if ((cursor_off + line->cursor_begin - 1) % cap->column -
      (line->cursor_begin - 1) > 0)
    xtputs_param(cap->RIGHT_str, 1, my_putint,
		 (cursor_off + line->cursor_begin - 1) % cap->column -
		 (line->cursor_begin - 1));
  else if ((cursor_off + line->cursor_begin - 1) % cap->column -
	   (line->cursor_begin - 1) < 0)
    xtputs_param(cap->LEFT_str, 1, my_putint,
		 -((line->cursor_begin + cursor_off - 1) %
		   cap->column - (line->cursor_begin - 1)));
}
