/*
** shell_get_line_init.c for shell_get_line in /home/cassin_f/PSU_2014_42sh
** 
** Made by François CASSIN
** Login   <cassin_f@epitech.net>
** 
** Started on  Fri May 22 17:56:44 2015 François CASSIN
** Last update Sun May 24 20:15:02 2015 Sebastien BOULOC
*/

#include "my_get_line.h"

void	init_params(t_params *params, t_env *env, t_caps *cap,
		    t_line *line)
{
  params->caps = cap;
  params->env = env;
  refresh_screen(line, line->cursor_position, line->buffer, cap);
}

void	init_params_his_compl(t_params *params, t_history *history,
			      t_completion *completion)
{
  params->history = history;
  params->completion = completion;
}
