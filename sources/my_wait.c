/*
** my_wait.c for my_wait in /home/coodie_d/PSU_2014_42sh
** 
** Made by Dylan Coodien
** Login   <coodie_d@epitech.eu>
** 
** Started on  Sun Jun  7 17:11:59 2015 Dylan Coodien
** Last update Sun Jun  7 19:47:03 2015 François CASSIN
*/

#include <sys/wait.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <signal.h>
#include "sh42.h"

int		use_tty(pid_t gid)
{
  int		fd;

  if ((fd = open("/dev/tty", O_RDWR)) == -1)
    return (-1);
  signal(SIGTTOU, SIG_IGN);
  tcsetpgrp(fd, gid);
  close(fd);
  return (0);
}

t_list	*my_wait(int *status, pid_t pid, t_list *cmd)
{
  while (waitpid(pid, status, WUNTRACED) > 0);
  use_tty(getpgrp());
  return (cmd);
}
