/*
** clear_screen.c for shell_get_line in /home/cassin_f/B2/B2-Systeme_Unix/42sh_cassin/functions
** 
** Made by François CASSIN
** Login   <cassin_f@epitech.net>
** 
** Started on  Mon May 18 14:26:27 2015 François CASSIN
** Last update Wed May 20 13:31:54 2015 François CASSIN
*/

#include <string.h>
#include "my_get_line.h"

int		get_char_first_offset(char buff[], int offset)
{
  int		nb_bytes;

  if ((nb_bytes = analyze_char(buff[offset])) != 1)
    return (offset);
  else
    {
      while (offset != 0 && (nb_bytes = analyze_char(buff[offset])) == 1)
	--offset;
      return (offset);
    }
}

int		get_char_len(char c)
{
  int		res;

  if ((res = analyze_char(c)) == 0)
    return (1);
  else
    return (res);
}

int		exchange_chars(char buff[], int offset)
{
  int		first_char_off;
  int		sec_char_off;
  int		first_char_len;
  int		sec_char_len;
  char		tmp[8];

  first_char_off = get_char_first_offset(buff, offset);
  if (first_char_off != 0)
    {
      sec_char_off = get_char_first_offset(buff, first_char_off - 1);
      first_char_len = get_char_len(buff[first_char_off]);
      sec_char_len = get_char_len(buff[sec_char_off]);
      memset(tmp, 0, 8);
      memcpy(tmp, buff + first_char_off, first_char_len);
      memcpy(tmp + first_char_len, buff + sec_char_off, sec_char_len);
      memcpy(buff + sec_char_off, tmp, first_char_len + sec_char_len);
    }
  return (first_char_len);
}

void		exchange(t_params *params, t_line *line)
{
  int		ret;

  if (line->cursor_offset != 0 && line->cursor_position < line->nb_char_pos)
    {
      ret = exchange_chars(line->buffer, line->cursor_offset);
      ++line->cursor_position;
      line->cursor_offset = line->cursor_offset + ret;
    }
  else if (line->cursor_offset != 0 && line->nb_char_pos > 1)
    exchange_chars(line->buffer, line->cursor_offset - 1);
  refresh_screen(line, line->cursor_position, line->buffer, params->caps);
}
