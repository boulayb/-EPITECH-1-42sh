/*
** get_cursor_pos.c for shell_get_line in /home/cassin_f/B2/B2-Systeme_Unix/42sh_cassin
**
** Made by François CASSIN
** Login   <cassin_f@epitech.net>
**
** Started on  Mon May 18 01:35:40 2015 François CASSIN
** Last update Fri May 22 14:28:59 2015 Sebastien BOULOC
*/

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include "my_get_line.h"

static void	get_coord(int *x, int *y, char *buff)
{
  int		i;
  int		save;

  save = 0;
  i = 0;
  while (buff[i])
    {
      if (buff[i] == ';')
	{
	  buff[i] = 0;
	  *y = my_getnbr(buff + 2);
	  save = i + 1;
	}
      else if (buff[i] == 'R')
	{
	  buff[i] = 0;
	  *x = my_getnbr(buff + save);
	}
      ++i;
    }
}

void		get_cursor_pos(int *x, int *y)
{
  int		fd;
  char		buff[400];
  char		cmd[4];

  cmd[0] = 27;
  cmd[1] = '[';
  cmd[2] = '6';
  cmd[3] = 'n';
  if ((fd = open("/dev/tty", O_RDWR)) < 0)
    {
      *x = 0;
      *y = 0;
    }
  else
    {
      memset(buff, 0, 400);
      write(fd, cmd, 4);
      read(fd, buff, 400);
      get_coord(x, y, buff);
    }
}
