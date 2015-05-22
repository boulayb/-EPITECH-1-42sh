/*
** beg_line.c for shell_get_line in /home/cassin_f/B2/B2-Systeme_Unix/42sh_cassin/functions
** 
** Made by François CASSIN
** Login   <cassin_f@epitech.net>
** 
** Started on  Mon May 18 14:25:31 2015 François CASSIN
** Last update Fri May 22 13:27:21 2015 Sebastien BOULOC
*/

#include "my_get_line.h"

void	beg_line(t_params *params, t_line *line)
{
  xtputs(params->caps->rescu_str, 1, my_putint);
  line->cursor_offset = 0;
  line->cursor_position = 0;
}
