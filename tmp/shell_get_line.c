/*
** shell_get_line.c for 42sh_getline in /home/cassin_f/B2/B2-Systeme_Unix/42sh_cassin
** 
** Made by François CASSIN
** Login   <cassin_f@epitech.net>
** 
** Started on  Tue May 12 15:52:55 2015 François CASSIN
** Last update Wed May 20 15:30:49 2015 François CASSIN
*/

#include <stdlib.h>
#include <string.h>
#include <ncurses/curses.h>
#include <term.h>
#include <termios.h>
#include <unistd.h>
#include "my_get_line.h"

void			init_line(t_line *line, t_caps *cap)
{
  line->nb_char_pos = 0;
  line->nb_char = 0;
  line->cursor_offset = 0;
  memset(line->buffer, 0, BUFF);
  line->history_offset = 0;
  line->cursor_position = 0;
  line->line_nb = 0;
  xtputs(cap->savecu_str, 1, my_putint);
  get_cursor_pos(&line->cursor_begin, &line->line_begin);
  xtputs(cap->cl_cureos_str, 1, my_putint);
  xtputs(cap->rescu_str, 1, my_putint);
}

int			get_capacities(t_caps *cap)
{
  cap->column = xtgetnum("co");
  cap->line = xtgetnum("li");
  cap->clear_str = xtgetstr("cl", NULL);
  cap->down_str = xtgetstr("do", NULL);
  cap->DOWN_str = xtgetstr("DO", NULL);
  cap->up_str = xtgetstr("up", NULL);
  cap->UP_str = xtgetstr("UP", NULL);
  cap->left_str = xtgetstr("le", NULL);
  cap->LEFT_str = xtgetstr("LE", NULL);
  cap->right_str = xtgetstr("nd", NULL);
  cap->RIGHT_str = xtgetstr("RI", NULL);
  cap->cl_cureos_str = xtgetstr("cd", NULL);
  cap->savecu_str = xtgetstr("sc", NULL);
  cap->rescu_str = xtgetstr("rc", NULL);
  return (0);
}

int			init_term_attr(struct termios *t_attr, t_caps *cap)
{
  if ((tcgetattr(0, t_attr)) < 0)
    {
      my_fputstr(2, "Can't get term attributes\n");
      return (-1);
    }
  t_attr->c_lflag &= ~ICANON;
  t_attr->c_lflag &= ~ECHO;
  t_attr->c_cc[VMIN] = 1;
  t_attr->c_cc[VTIME] = 0;
  if (tcsetattr(0, TCSANOW, t_attr) < 0)
    {
      my_fputstr(2, "Can't set term attributes\n");
      return (-1);
    }
  return (get_capacities(cap));
}

int			init_termcaps(t_env *env, struct termios *t_attr,
				      t_caps *cap)
{
  char			*term;

  if ((term = get_env("TERM=", env)) == NULL)
    {
      my_fputstr(2, "Can't get terminal, can't init_termcaps\n");
      return (-1);
    }
  term = term + 5;
  if (tgetent(NULL, term) == ERR)
    {
      my_fputstr(2, "Can't get termcaps base\n");
      return (-1);
    }
  return (init_term_attr(t_attr, cap));
}

char			**shell_get_line(t_env *env, int *stop)
{
  int			ret;
  struct termios	t_attr;
  t_line		line;
  t_caps		cap;
  t_completion		complet;
  t_history		history;
  t_params		params;

  if (init_termcaps(env, &t_attr, &cap) == -1)
    return (NULL);
  init_line(&line, &cap);
  if (init_completion(&complet, env) == -1)
    return (NULL);
  complete_history(&history, env);
  params.history = &history;
  params.completion = &complet;
  params.caps = &cap;
  params.env = env;
  refresh_screen(&line, line.cursor_position, line.buffer, &cap);
  if ((ret = get_cmd(&line, &params)) == 1)
    *stop = 1;
  free_params(&params);
  if (put_term_back(&t_attr) == -1)
    return (NULL);
  if (ret == -1)
    return (NULL);
  return (my_str_to_cmdtab(line.buffer));
}
