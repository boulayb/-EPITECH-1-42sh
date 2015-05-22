/*
** magic_quotes.c for magic_quotes in /home/danilo_d/semestre2/PSU_2014_42sh
**
** Made by danilov dimitri
** Login   <danilo_d@epitech.eu>
**
** Started on  Wed May 20 18:32:28 2015 danilov dimitri
** Last update Fri May 22 18:00:12 2015 Sebastien BOULOC
*/

#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "my.h"
#include "sh42.h"

static char	*find_correct_access(char *str, char **path)
{
  int		i;
  char		*command;
  int		ret;

  ret = 1;
  i = 0;
  while (path[i] != NULL && ret != 0)
    {
      if ((command = concat_string(str, path[i])) == NULL)
	return (NULL);
      if ((ret = access(command, F_OK)) == 0)
	if ((str = strdup(command)) == NULL)
	  return (NULL);
      ++i;
    }
  return (command);
}

static char	*read_buffer(int fd)
{
  int		ret;
  char		buffer[BUFFER_SIZE];
  char		*str;

  while ((ret = read(fd, buffer, BUFFER_SIZE - 1)) > 0)
    {
      buffer[ret - 1] = 0;
      if ((str = strdup(buffer)) == NULL)
	return (NULL);
    }
  return (str);
}

char		*magic_quotes(char *str, char **path)
{
  char		**argv;
  int		pid;
  int		fd[2];
  char		*return_str;

  pipe(fd);
  if ((argv = my_str_to_wordtab(str)) == NULL ||
      (argv[0] = find_correct_access(argv[0], path)) == NULL)
    return (NULL);
  pid = fork();
  if (pid == 0)
    {
      dup2(fd[1], 1);
      execve(argv[0], argv, NULL);
    }
  else
    wait(NULL);
  close(fd[1]);
  if ((return_str = read_buffer(fd[0])) == NULL)
    return (NULL);
  return (return_str);
}
