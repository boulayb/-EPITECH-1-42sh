/*
** execute.c for execute in /home/dcoodien/rendu/SysUnix/B2/coodie/src
**
** Made by Dylan Coodien
** Login   <coodie_d@epitech.eu>
**
** Started on  Wed May  6 16:00:05 2015 Dylan Coodien
** Last update Sun May 24 17:07:34 2015 Dylan Coodien
*/

#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include "sh42.h"

int	g_fd;

static int	son(int *fd_in, int p[2], t_list *cmd, char **env)
{
  signal(SIGINT, SIG_DFL);
  signal(SIGTSTP, SIG_IGN);
  if (g_fd != -1)
    {
      dup2(g_fd, 0);
      g_fd = -1;
    }
  dup2(*fd_in, 0);
  if (cmd->act != ENDACT && cmd->act != LEFT && cmd->act != DLEFT)
    dup2(p[1], 1);
  close(p[0]);
  if ((execve(cmd->av[0], cmd->av, env)) == -1)
    {
      kill(getpid(), SIGTERM);
    }
  return (0);
}

static t_list	*execute_pipe(t_list *cmd, int *fd_in,
			      int *status, char **env)
{
  int		p[2];
  pid_t		pid;

  *fd_in = 0;
  while (cmd->act != -1)
    {
      pipe(p);
      if ((pid = fork()) == -1)
	return (NULL);
      else if (pid == 0)
	son(fd_in, p, cmd, env);
      else
	{
	  close(p[1]);
	  *fd_in = p[0];
	  if (cmd->act != PIPE)
	    {
	      while (waitpid(pid, status, WUNTRACED) > 0);
	      return (cmd);
	    }
	  cmd = cmd->next;
	}
    }
  while (waitpid(pid, status, WUNTRACED) > 0);
  return (cmd);
}

int		start_cmd(t_list *list, char **env)
{
  t_list	*tmp;
  int		fd_tmp;
  t_list	*tmp2;
  int		status;

  g_fd = -1;
  fd_tmp = 1;
  tmp = list->next;
  tmp2 = list->next;
  while (tmp != list)
    {
      if ((tmp2 = check_left_reddir(list, tmp2)) == NULL)
	return (status);
      if ((tmp = execute_pipe(tmp, &fd_tmp, &status, env)) == NULL)
	return (status);
      if (tmp->act == ENDACT)
	return (status);
      tmp = tmp->next;
      if (tmp->back->act == LEFT || tmp->back->act == DLEFT)
	tmp = go_trough_left_reddir(tmp);
      if ((tmp->back->act == RIGHT || tmp->back->act == DRIGHT) &&
	  ((tmp = create_file(tmp, fd_tmp)) == NULL))
	return (status);
    }
  return (status);
}
