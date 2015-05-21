/*
** xtputs.c for shell_get_line in /home/cassin_f/B2/B2-Systeme_Unix/42sh_cassin
**
** Made by François CASSIN
** Login   <cassin_f@epitech.net>
**
** Started on  Sun May 17 22:21:50 2015 François CASSIN
** Last update Wed May 20 15:40:06 2015 danilov dimitri
*/

#include <ncurses/curses.h>
#include <term.h>
#include <stdlib.h>
#include "my_get_line.h"

char		*xtgetstr(char *id, char **area)
{
  char		*ret;

  if (id == NULL)
    {
      my_fputstr(2, "Error tgetstr\n");
      return (NULL);
    }
  else
    {
      if ((ret = tgetstr(id, area)) == NULL)
	{
	  my_fputstr(2, "Error tgetstr\n");
	  return (NULL);
	}
      else
	return (ret);
    }
}

char		*xtgoto(char *cap, int col, int row)
{
  char		*ret;

  if (cap == NULL)
    {
      my_fputstr(2, "Error tgoto\n");
      return (NULL);
    }
  else
    {
      if ((ret = tgoto(cap, col, row)) == NULL)
	{
	  my_fputstr(2, "Error tputs\n");
	  return (NULL);
	}
      else
	return (ret);
    }
}

int		xtputs(char *str, int affcnt, int (*putc)(int))
{
  if (str == NULL)
    {
      my_fputstr(2, "Error tputs\n");
      return (-1);
    }
  else
    {
      if (tputs(str, affcnt, putc) == ERR)
	{
	  my_fputstr(2, "Error tputs\n");
	  return (ERR);
	}
      else
	return (OK);
    }
}

int		xtputs_param(char *str, int affcnt, int (*putc)(int),
			     int param)
{
  if (str == NULL)
    {
      my_fputstr(2, "Error tputs\n");
      return (-1);
    }
  else
    {
      return (xtputs(tparm(str, param), affcnt, putc));
    }
}

int		xtgetnum(char *id)
{
  int		ret;

  if (id == NULL)
    {
      my_fputstr(2, "Error tgetnum\n");
      return (ERR);
    }
  if ((ret = tgetnum(id)) == ERR)
    {
      my_fputstr(2, "Error tgetnum\n");
      return (ERR);
    }
  return (ret);
}
