/*
** clear_screen.c for shell_get_line in /home/cassin_f/B2/B2-Systeme_Unix/42sh_cassin/functions
**
** Made by François CASSIN
** Login   <cassin_f@epitech.net>
**
** Started on  Mon May 18 14:26:27 2015 François CASSIN
** Last update Fri May 22 13:28:19 2015 Sebastien BOULOC
*/

#include "my_get_line.h"

void	myclear_screen(t_params *params, t_line *line)
{
  xtputs(params->caps->clear_str, 1, my_putint);
  disp_prompt(params->env);
  xtputs(params->caps->savecu_str, 1, my_putint);
  refresh_screen(line, line->cursor_position, line->buffer, params->caps);
}
