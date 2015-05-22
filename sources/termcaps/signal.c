/*
** signal.c for signal in /home/danilo_d/semestre2/42sh_jeudi/sources/termcaps
**
** Made by danilov dimitri
** Login   <danilo_d@epitech.eu>
**
** Started on  Thu May 21 15:11:56 2015 danilov dimitri
** Last update Fri May 22 16:09:05 2015 François CASSIN
*/

#include <signal.h>
#include <stdlib.h>
#include <string.h>
#include "my_get_line.h"
#include "my.h"

void	catch_signal(int signal)
{
  if (signal == SIGINT || signal == SIGSTOP)
    {
      my_putchar('\n');
      if (g_line != NULL)
	{
	  g_line->cursor_position = 0;
	  g_line->cursor_offset = 0;
	  g_line->nb_char = 0;
	  g_line->nb_char_pos = 0;
	  memset(g_line->buffer, 0, BUFF);
	  memset(g_line->character, 0, BUFF);
	  disp_prompt(g_env);
	  get_cursor_pos(&g_line->cursor_begin, &g_line->line_begin);
	  if (g_caps != NULL)
	    xtputs(g_caps->savecu_str, 1, my_putint);
	}
    }
}
