/*
** clear_screen.c for shell_get_line in /home/cassin_f/B2/B2-Systeme_Unix/42sh_cassin/functions
** 
** Made by François CASSIN
** Login   <cassin_f@epitech.net>
** 
** Started on  Mon May 18 14:26:27 2015 François CASSIN
** Last update Wed May 20 12:15:03 2015 François CASSIN
*/

#include <string.h>
#include "my_get_line.h"

int		count_char_pos(char buff[], int offset)
{
  int		count;
  int		i;

  i = 0;
  count = 0;
  while (i < offset)
    {
      if (analyze_char(buff[i]) != 1)
	++count;
      ++i;
    }
  return (count);
}

int		get_end_last_word(char buff[], int len)
{
  while (len != 0 && (buff[len] == ' ' || buff[len] == '\t'))
    --len;
  while (len != 0 && buff[len] != ' ' && buff[len] != '\t')
    --len;
  return (len);
}

void		del_word(t_params *params, t_line *line)
{
  int		offset;

  if (my_strlen(line->buffer) != 0)
    {
      offset = get_end_last_word(line->buffer, line->nb_char - 1);
      line->cursor_offset = offset;
      memset(line->buffer + line->cursor_offset, 0, BUFF -
	     line->cursor_offset);
      line->nb_char = line->cursor_offset;
      line->cursor_position = count_char_pos(line->buffer, offset);
      line->nb_char_pos = line->cursor_position;
      refresh_screen(line, line->cursor_position, line->buffer, params->caps);
    }
}
