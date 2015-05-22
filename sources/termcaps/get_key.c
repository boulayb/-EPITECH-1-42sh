/*
** get_key.c for shell_get_line in /home/cassin_f/B2/B2-Systeme_Unix/42sh_cassin
**
** Made by François CASSIN
** Login   <cassin_f@epitech.net>
**
** Started on  Mon May 18 03:16:57 2015 François CASSIN
** Last update Fri May 22 14:30:10 2015 Sebastien BOULOC
*/

#include "my.h"
#include "my_get_line.h"

static int	get_key2(t_line *line)
{
  char		*str;

  str = line->character;
  if ((str[0] == 27 && str[1] == 91 && str[2] == 66 && str[3] == 0)||
      check_ctrl(line->character) == CTRL_N)
    return (DO_HISTO);
  else if ((str[0] == 27 && str[1] == 91 && str[2] == 65 && str[3] == 0) ||
	   check_ctrl(line->character) == CTRL_P)
    return (UP_HISTO);
  else if ((str[0] == 27 && str[1] == 91 && str[2] == 68 && str[3] == 0) ||
	  check_ctrl(line->character) == CTRL_B)
    return (BACK);
  else if ((str[0] == 27 && str[1] == 91 && str[2] == 67 && str[3] == 0) ||
	   check_ctrl(line->character) == CTRL_F)
    return (FORE);
  else if ((str[0] == 27 && str[1] == 91 && str[2] == 51 &&
	    str[3] == 126 && str[4] == 0) ||
	   check_ctrl(line->character) == CTRL_D)
    return (DELETE);
  else if (my_strcmp(line->character, "\t") == 1)
    return (COMPLET);
  return (-1);
}

int		get_key(t_line *line)
{
  if ((line->character[0] == DELETE_KEY && line->character[1] == 0) ||
      (line->nb_char && check_ctrl(line->character) == CTRL_H))
    return (DEL_BACK);
  else if (check_ctrl(line->character) == CTRL_A)
    return (BEG_LINE);
  else if (check_ctrl(line->character) == CTRL_E)
    return (END_LINE);
  else if (check_ctrl(line->character) == CTRL_L)
    return (CLEAR_SCREEN);
  else if (check_ctrl(line->character) == CTRL_K)
    return (DEL_LINE);
  else if (check_ctrl(line->character) == CTRL_T)
    return (EXCHANGE);
  else if (check_ctrl(line->character) == CTRL_U)
    return (DEL_ALL);
  else if (check_ctrl(line->character) == CTRL_W)
    return (DEL_WORD);
  return (get_key2(line));
}
