/*
** reddir_right.c for reddir_right in /home/dcoodien/rendu/SysUnix/B2/coodie/src
**
** Made by Dylan Coodien
** Login   <coodie_d@epitech.eu>
**
** Started on  Sun May 10 17:05:10 2015 Dylan Coodien
** Last update Sun May 24 19:41:24 2015 Sebastien BOULOC
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include "sh42.h"

t_list	*create_file(t_list *tmp, int fd_tmp)
{
  int	fd;
  char	buf[5001];
  int	n;

  fd = 1;
  while (tmp->back->act == RIGHT || tmp->back->act == DRIGHT)
    {
      if (tmp->back->act == RIGHT &&
	  ((fd = open(tmp->av[0], O_CREAT | O_TRUNC | O_RDWR,
		      S_IRUSR | S_IWUSR | S_IRGRP
		      | S_IWGRP | S_IROTH)) == -1))
	return (NULL);
      else if (tmp->back->act == DRIGHT &&
	       ((fd = open(tmp->av[0], O_CREAT | O_RDWR | O_APPEND,
			   S_IRUSR | S_IWUSR | S_IRGRP
			   | S_IWGRP | S_IROTH)) == -1))
	return (NULL);
      tmp = tmp->next;
    }
  while ((n = read(fd_tmp, buf, 5000)) > 0)
    {
      buf[n] = 0;
      write(fd, buf, strlen(buf));
    }
  return (tmp);
}
