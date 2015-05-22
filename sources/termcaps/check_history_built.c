/*
** check_history_built.c for shell_get_line in /home/cassin_f/42sh_cassin
**
** Made by François CASSIN
** Login   <cassin_f@epitech.net>
**
** Started on  Thu May 21 22:10:02 2015 François CASSIN
** Last update Fri May 22 11:48:56 2015 Dylan Coodien
*/

#include <string.h>
#include "my_get_line.h"

int		get_cmd_len(char buff[], int i)
{
  if (buff[i + 1] && buff[i + 1] == '!')
    return (i + 2);
  while (buff[i] && buff[i] != ' ' && buff[i] != '\t' && buff[i] != '|' &&
	 buff[i] != '&' && buff[i] != ';' && buff[i] != '>' && buff[i] != '<'
	 && buff[i] != '"')
    ++i;
  return (i);
}

int		replace_history(char buff[], int i, int len, char *history)
{
  char		save[BUFF];

  if (((my_strlen(buff) + my_strlen(history)) <= BUFF - 2) && history != NULL)
    {
      memset(save, 0, BUFF);
      memcpy(save, buff + len, my_strlen(buff + len));
      memcpy(buff + i, history, my_strlen(history));
      buff[i + my_strlen(history)] = 0;
      memcpy(buff + i + my_strlen(history), save, my_strlen(save));
    }
  return (0);
}

int		replace_by_history(t_history *history, t_line *line, int i,
				   int len)
{
  int		n;

  if (strncmp("!!", line->buffer + i, 2) == 0)
    return (replace_history(line->buffer, i, len,
			    history->history_tab[history->nb_max - 1]));
  else
    {
      n = history->nb_max - 1;
      while (n >= 0)
	{
	  if (line->buffer[i + 1])
	    {
	      if (history->history_tab[n] != NULL &&
		  strncmp(line->buffer + i + 1,
			  history->history_tab[n], len - 1 - i) == 0)
		{
		  replace_history(line->buffer, i, len,
				  history->history_tab[n]);
		  return (0);
		}
	    }
	  --n;
	}
    }
  return (1);
}

int		is_in_double_quotes(char buff[], int offset)
{
  int		i;
  int		quotes;

  i = 0;
  quotes = 0;
  while (buff[i] && i < offset)
    {
      if (buff[i] == '"')
	++quotes;
      ++i;
    }
  if ((quotes % 2) == 1)
    return (0);
  else
    return (1);
}

void		check_history_replace(t_history *history, t_line *line)
{
  int		i;
  int		cmd_len;
  int		done;

  i = 0;
  done = 0;
  while (line->buffer[i])
    {
      if (line->buffer[i] == '!' && line->buffer[i + 1])
	{
	  cmd_len = get_cmd_len(line->buffer, i);
	  if (history->nb_max != 0 &&
	      is_in_double_quotes(line->buffer, i) != 0)
	    done = (replace_by_history(history, line, i, cmd_len) == 0 ? 1:0);
	  i = i + cmd_len;
	}
      else
	++i;
    }
  if (done == 1)
    {
      my_fputstr(1, line->buffer);
      my_fputchar(1, '\n');
    }
}
