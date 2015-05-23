/*
** print_list.c for print_list in /home/dcoodien/rendu/SysUnix/B2/PSU_2014_42sh
**
** Made by Dylan Coodien
** Login   <coodie_d@epitech.eu>
**
** Started on  Tue May 19 14:38:35 2015 Dylan Coodien
** Last update Sat May 23 13:47:46 2015 danilov dimitri
*/

#include <string.h>
#include <unistd.h>
#include "sh42.h"

extern	int	g_fd;

int		print_list(t_data *list)
{
  t_data	*tmp;
  int		nw_fd[2];

  pipe(nw_fd);
  tmp = list->next;
  while (tmp != list)
    {
      write(nw_fd[1], tmp->line, strlen(tmp->line));
      write(nw_fd[1], "\n", 1);
      tmp = tmp->next;
    }
  close(nw_fd[1]);
  g_fd = nw_fd[0];
  return (0);
}
