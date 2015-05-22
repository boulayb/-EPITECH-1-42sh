/*
** clear_screen.c for shell_get_line in /home/cassin_f/B2/B2-Systeme_Unix/42sh_cassin/functions
** 
** Made by François CASSIN
** Login   <cassin_f@epitech.net>
** 
** Started on  Mon May 18 14:26:27 2015 François CASSIN
** Last update Fri May 22 13:30:55 2015 Sebastien BOULOC
*/

#include "my_get_line.h"

void	del_line(t_params *params, t_line *line)
{
  int	i;

  xtputs(params->caps->cl_cureos_str, 1, my_putint);
  i = line->cursor_offset;
  while (i < line->nb_char)
    {
      line->buffer[i] = 0;
      ++i;
    }
  line->nb_char = line->cursor_offset;
  line->nb_char_pos = line->cursor_position;
  line->buffer[line->nb_char] = 0;
}
