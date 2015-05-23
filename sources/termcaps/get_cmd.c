/*
** get_cmd.c for shell_get_line in /home/cassin_f/B2/B2-Systeme_Unix/42sh_cassin
**
** Made by François CASSIN
** Login   <cassin_f@epitech.net>
**
** Started on  Mon May 18 02:17:56 2015 François CASSIN
** Last update Sat May 23 14:31:51 2015 François CASSIN
*/

#include <unistd.h>
#include <string.h>
#include "my_get_line.h"

int		check_ctrl(char buff[])
{
  if (buff[1] == 0)
    return (buff[0]);
  return (-1);
}

int		check_overflow(t_caps *cap, t_line *line, int len)
{
  if (my_strlen(line->buffer + len) > BUFF - 2)
    {
      xtputs(cap->rescu_str, 1, my_putint);
      xtputs(cap->cl_cureos_str, 1, my_putint);
      memset(line->buffer, 0, BUFF);
      line->cursor_offset = 0;
      line->nb_char = 0;
      return (1);
    }
  return (0);
}

static int	add_new_char(t_line *line, t_caps *cap)
{
  char		save[BUFF];

  if (line->character[0] == 27)
    return (0);
  if (check_overflow(cap, line, my_strlen(line->character)))
    return (-1);
  line->nb_char = line->nb_char + my_strlen(line->character);
  memset(save, 0, BUFF);
  memcpy(save, line->buffer + line->cursor_offset,
	 my_strlen(&line->buffer[line->cursor_offset]));
  memcpy(line->buffer + line->cursor_offset, line->character,
	 my_strlen(line->character));
  line->cursor_offset = line->cursor_offset + my_strlen(line->character);
  memcpy(line->buffer + line->cursor_offset, save, my_strlen(save));
  ++line->cursor_position;
  ++line->nb_char_pos;
  if (line->buffer[my_strlen(line->buffer) - 1] == '\n')
    {
      line->buffer[my_strlen(line->buffer) - 1] = 0;
      --line->cursor_position;
    }
  refresh_screen(line, line->cursor_position, line->buffer, cap);
  return (0);
}

int		return_zero_new_line()
{
  my_fputchar(1, '\n');
  return (0);
}

int		get_cmd(t_line *line, t_params *params)
{
  int		ret;
  int		key;
  static void	(*fkey[14])(t_params *params, t_line *line) =
    {del_char, beg_line, end_line, myclear_screen, del_line, exchange, del_all,
     del_word, down_histo, up_histo, backward, foreward, del_back, complete};

  while (42)
    {
      memset(line->character, 0, BUFF);
      if ((ret = read(0, line->character, BUFF)) == -1)
	return (1);
     if (my_strcmp(line->character, "\n") == 1 ||
	 check_ctrl(line->character) == CTRL_J)
       return (return_zero_new_line());
     if (((line->nb_char == 0) &&
	  (check_ctrl(line->character) == CTRL_D)) || ret == 0)
	return (1);
      else if ((key = get_key(line)) != -1)
	fkey[key](params, line);
      else if (add_new_char(line, params->caps) == -1)
	return (0);
     if (line->character[my_strlen(line->character) - 1] == '\n')
       return (return_zero_new_line());
    }
  return (0);
}
