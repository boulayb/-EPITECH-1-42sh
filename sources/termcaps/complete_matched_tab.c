/*
** complete_matched_tab.c for shell_get_line in /home/cassin_f/B2/B2-Systeme_Unix/42sh_cassin
**
** Made by François CASSIN
** Login   <cassin_f@epitech.net>
**
** Started on  Mon May 18 20:13:24 2015 François CASSIN
** Last update Wed May 20 18:25:09 2015 danilov dimitri
*/

#include <string.h>
#include "my_get_line.h"

void		add_to_buff(t_params *params, t_line *line, char buff[])
{
  if (check_overflow(params->caps, line, my_strlen(buff)) == 0)
    {
      line->nb_char = line->nb_char + my_strlen(buff);
      line->nb_char_pos = count_char_pos(line->buffer, line->nb_char - 1);
      go_right(line->cursor_offset, line->buffer, line->nb_char,
	       my_strlen(buff));
      memcpy(line->buffer + line->cursor_offset, buff, my_strlen(buff));
      line->cursor_offset = line->cursor_offset + my_strlen(buff);
      line->cursor_position = count_char_pos(line->buffer,
					     line->cursor_offset);
    }
}

int		get_same_begin(t_complet *matched)
{
  t_complet	*tmp;
  int		nb_chars;
  char		buffer[BUFF];

  nb_chars = 0;
  while (42)
    {
      memset(buffer, 0, BUFF);
      strncpy(buffer, matched->next->name, nb_chars + 1);
      tmp = matched->next;
      while (tmp != matched)
	{
	  if (strncmp(buffer, tmp->name, nb_chars + 1))
	    return (nb_chars);
	  tmp = tmp->next;
	}
      ++nb_chars;
    }
}

void		do_multiple_matched(t_params *params, t_compl_par *complete,
				    t_line *line, char new_chars[])
{
  int		begin_idem;

  my_fputchar(1, '\n');
  begin_idem = get_same_begin(complete->list_of_matched);
  memset(new_chars, 0, BUFF);
  memcpy(new_chars, complete->list_of_matched->next->name, begin_idem);
  add_to_buff(params, line, new_chars + my_strlen(complete->buffer +
						  complete->offset_begin));
  aff_all_possibilities(params, complete->list_of_matched);
  disp_prompt(params->env);
  get_cursor_pos(&line->cursor_begin, &line->line_begin);
  xtputs(params->caps->savecu_str, 1, my_putint);
  refresh_screen(line, line->cursor_position, line->buffer, params->caps);
}

void		complete_matched_tab(t_compl_par *complete, t_line *line,
				     t_params *params)
{
  char		new_chars[BUFF];

  if (complete->list_of_matched != NULL)
    {
      if (complete->list_of_matched->next->name != NULL)
	{
	  if (complete->list_of_matched->next->next ==
	      complete->list_of_matched)
	    {
	      strcpy(new_chars, complete->list_of_matched->next->name +
		     my_strlen(complete->buffer + complete->offset_begin));
	      add_to_buff(params, line, new_chars);
	      if (new_chars[my_strlen(new_chars) - 1] != '/')
		add_to_buff(params, line, " ");
	      refresh_screen(line, line->cursor_position, line->buffer,
			     params->caps);
	    }
	  else
	    do_multiple_matched(params, complete, line, new_chars);
	}
      free_complete(complete->list_of_matched);
    }
}
