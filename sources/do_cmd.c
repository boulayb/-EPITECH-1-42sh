/*
** do_cmd.c for do_cmd in /home/dcoodien/rendu/SysUnix/B2/coodie/src
**
** Made by Dylan Coodien
** Login   <coodie_d@epitech.eu>
**
** Started on  Sun May  3 17:15:22 2015 Dylan Coodien
** Last update Tue May 19 14:32:16 2015 danilov dimitri
*/

#define _GNU_SOURCE

#include <string.h>
#include <stdlib.h>
#include "my.h"
#include "sh42.h"

int		find_correct_return(int status)
{
  if (WIFSIGNALED(status))
    status = 128 + WTERMSIG(status);
  else
    status = WEXITSTATUS(status);
  return (status);
}

int		do_cmd(char **tab, char **path, char **env)
{
  t_list	*list;
  int		i;
  int		n;
  int		nb;
  int		av_nbr;

  nb = 0;
  av_nbr = 0;
  if ((list = xmalloc(sizeof(*list))) == NULL)
    return (-1);
  list->next = list;
  list->back = list;
  list->act = -1;
  if ((i = count_moves(tab)) == -1)
    return (-1);
  n = -2;
  while (++n < i)
    {
      if (my_put_in_list(list, tab, &nb, &av_nbr) != 0)
	return (-1);
    }
  if ((verify_access(list, path)) != 0)
    return (127);
  i = start_cmd(list, env);
  return (find_correct_return(i));
}

int		exec_program(char **tab, char **path, t_env *env_list)
{
  char		**env;
  int		ret;

  env = NULL;
  if (tab == NULL || tab[0] == NULL)
    return (0);
  if ((env = my_listtotab(env, env_list)) == NULL)
    return (-1);
  ret = do_cmd(tab, path, env);
  free_tab(env);
  return (ret);
}