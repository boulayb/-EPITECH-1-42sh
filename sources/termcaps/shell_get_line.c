/*
** shell_get_line.c for 42sh_getline in /home/cassin_f/B2/B2-Systeme_Unix/42sh_cassin
**
** Made by François CASSIN
** Login   <cassin_f@epitech.net>
**
** Started on  Tue May 12 15:52:55 2015 François CASSIN
** Last update Sun May 24 00:24:38 2015 François CASSIN
*/

#include <stdlib.h>
#include <string.h>
#include <ncurses/curses.h>
#include <term.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "my_get_line.h"

static void		init_line(t_line *line, t_caps *cap)
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
  g_line = line;
  g_caps = cap;
}

static int		get_capacities(t_caps *cap)
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

static int		init_term_attr(struct termios *t_attr, t_caps *cap)
{
  int			fd;

  if ((fd = open("/dev/tty", O_RDWR)) == -1)
    return (-1);
  if ((tcgetattr(fd, t_attr)) < 0)
    return (-1);
  t_attr->c_lflag &= ~ICANON;
  t_attr->c_lflag &= ~ECHO;
  t_attr->c_cc[VMIN] = 1;
  t_attr->c_cc[VTIME] = 0;
  if (tcsetattr(fd, TCSANOW, t_attr) < 0)
    return (-1);
  return (get_capacities(cap));
}

static int		init_termcaps(t_env *env, struct termios *t_attr,
				      t_caps *cap)
{
  char			*term;

  if ((term = get_env("TERM=", env)) == NULL)
    return (-1);
  if (tgetent(NULL, term + 5) == ERR)
    return (-1);
  return (init_term_attr(t_attr, cap));
}

char			*shell_get_line(t_env *env, int *stop)
{
  struct termios	t_attr;
  t_line		line;
  t_caps		cap;
  t_completion		complet;
  t_history		history;
  t_params		params;
  char			*s;

  if ((s = check_42shrc(env, stop)) != NULL)
    return (s);
  if (init_termcaps(env, &t_attr, &cap) == -1)
    return (get_next_line(0));
  init_line(&line, &cap);
  if (init_completion(&complet, env) == -1)
    return (NULL);
  complete_history(&history, env);
  init_params_his_compl(&params, &history, &complet);
  init_params(&params, env, &cap, &line);
  if (get_cmd(&line, &params) == 1)
    *stop = 1;
  rewrite_history(&line, params.history, params.env);
  free_params(&params);
  if (put_term_back(&t_attr) == -1)
    return (NULL);
  return (strdup(line.buffer));
}
