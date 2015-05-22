/*
** get_next_line.c for get_next_line in /home/boulay_b/Rendu/CPE_2014_get_next_line
**
** Made by arnaud boulay
** Login   <boulay_b@epitech.net>
**
** Started on  Wed Nov 19 15:55:19 2014 arnaud boulay
** Last update Fri May 22 17:52:47 2015 Sebastien BOULOC
*/

#include <stdlib.h>
#include <unistd.h>
#include "my.h"

static int	my_strlen_gnl(char *str)
{
  int		i;

  i = 0;
  if (str == NULL)
    return (-1);
  while (str[i] != '\0')
    ++i;
  return (i);
}

static char	*init_buffer(char *buffer, int j, int len)
{
  while (j != (len + BUFFER_SIZE + 1))
    {
      buffer[j] = '\0';
      ++j;
    }
  return (buffer);
}

static char	*remalloc_gnl(char *src)
{
  char		*dest;
  int		i;

  i = 0;
  dest = malloc(my_strlen_gnl(src) + BUFFER_SIZE + 1);
  if (dest == NULL)
    return (NULL);
  while (src[i] != '\0')
    {
      dest[i] = src[i];
      ++i;
    }
  dest = init_buffer(dest, i, my_strlen_gnl(src));
  free(src);
  return (dest);
}

static char	*my_strcpy_gnl(char *dest, char *src, int *i, int *j)
{
  while (src[*j] == '\n')
    ++(*j);
  while (src[*j] != '\0' && src[*j] != '\n')
    {
      dest[*i] = src[*j];
      ++(*i);
      ++(*j);
    }
  dest = remalloc_gnl(dest);
  return (dest);
}

char		*get_next_line(const int fd)
{
  char		*str;
  int		i;
  static int	ret = 1;
  static int	j = BUFFER_SIZE;
  static char	buffer[BUFFER_SIZE + 1];

  ret = 1;
  i = 0;
  if (((str = malloc(BUFFER_SIZE + 1)) == NULL) || BUFFER_SIZE == 0)
    return (NULL);
  str = init_buffer(str, 0, 0);
  while (ret > 0 && buffer[j] != '\n')
    if (buffer[j] == '\0')
      {
	init_buffer(buffer, 0, 0);
	if (((ret = read(fd, buffer, BUFFER_SIZE)) <= 0) &&
	    my_strlen_gnl(str) <= 0)
	  return (NULL);
	j = 0;
      }
    else if (ret > 0)
      if ((str = my_strcpy_gnl(str, buffer, &i, &j)) == NULL)
	return (NULL);
  ++j;
  return (str);
}
