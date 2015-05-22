/*
** put_term_back.c for shell_get_line in /home/cassin_f/B2/B2-Systeme_Unix/42sh_cassin
**
** Made by François CASSIN
** Login   <cassin_f@epitech.net>
**
** Started on  Sun May 17 22:43:05 2015 François CASSIN
** Last update Fri May 22 11:28:56 2015 danilov dimitri
*/

#include <ncurses/curses.h>
#include <term.h>
#include <unistd.h>
#include <stdlib.h>
#include "my_get_line.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int     put_term_back(struct termios *t_attr)
{
  int	fd;

  if ((fd = open("/dev/tty", O_RDWR)) == -1)
    return (-1);
  t_attr->c_lflag |= ICANON;
  t_attr->c_lflag |= ECHO;
  if (tcsetattr(fd, TCSANOW, t_attr) == -1)
    {
      my_fputstr(2, "error tcsetattr : could not set attributes\n");
      return (-1);
    }
  return (0);
}
