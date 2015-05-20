/*
** analyze_char.c for shell_get_line in /home/cassin_f/42sh_cassin
** 
** Made by François CASSIN
** Login   <cassin_f@epitech.net>
** 
** Started on  Tue May 19 15:28:47 2015 François CASSIN
** Last update Wed May 20 10:58:21 2015 François CASSIN
*/

#include "my_get_line.h"

int		analyze_char(char c)
{
  char		save;
  int		i;

  i = 0;
  while (i < 7)
    {
      save = (c >> (7 - i));
      if ((save & 1) == 0)
	return (i);
      ++i;
    }
  return (i);
}

void		del_from_begin_spec_char(t_line *line, int offset,
					 int nb_bytes)
{
  while (line->buffer[offset] && nb_bytes > 0)
    {
      go_left(offset, line->buffer, line->nb_char);
      --line->nb_char;
      --nb_bytes;
    }
}

void		delete_char(t_line *line, int offset)
{
  int		nb_bytes;

  nb_bytes = analyze_char(line->buffer[offset]);
  if (nb_bytes == 0)
    {
      go_left(offset, line->buffer, line->nb_char);
      --line->nb_char;
    }
  else if (nb_bytes == 1)
    {
      while (offset != 0 && analyze_char(line->buffer[offset]) == 1)
	{
	  go_left(offset, line->buffer, line->nb_char);
	  --offset;
	  --line->nb_char;
	}
      go_left(offset, line->buffer, line->nb_char);
      --line->nb_char;
    }
  else if (nb_bytes > 1)
    del_from_begin_spec_char(line, offset, nb_bytes);
}
