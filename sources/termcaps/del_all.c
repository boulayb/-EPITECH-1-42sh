/*
** clear_screen.c for shell_get_line in /home/cassin_f/B2/B2-Systeme_Unix/42sh_cassin/functions
** 
** Made by François CASSIN
** Login   <cassin_f@epitech.net>
** 
** Started on  Mon May 18 14:26:27 2015 François CASSIN
** Last update Fri May 22 13:30:02 2015 Sebastien BOULOC
*/

#include <string.h>
#include "my_get_line.h"

void	del_all(t_params *params, t_line *line)
{
  if (line->nb_char != 0)
    {
      xtputs(params->caps->rescu_str, 1, my_putint);
      xtputs(params->caps->cl_cureos_str, 1, my_putint);
      memset(line->buffer, 0, BUFF);
      line->cursor_offset = 0;
      line->cursor_position = 0;
      line->nb_char = 0;
      line->nb_char_pos = 0;
    }
}
