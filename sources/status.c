/*
** status.c for 42sh in /home/boulay_b/Work/SE2/PSU/42sh/PSU_2014_minishell2
**
** Made by Arnaud Boulay
** Login   <boulay_b@epitech.net>
**
** Started on  Fri May 15 00:29:03 2015 Arnaud Boulay
** Last update Sat May 23 15:36:12 2015 danilov dimitri
*/

#include <stdio.h>
#include <stdlib.h>
#include "my.h"

static t_status	gl_status[] =
    {
      {126, "Cannot execute command.\n"},
      {127, "Command not found.\n"},
      {128, "Invalid argument.\n"},
      {136, "Floating point exception.\n"},
      {139, "Segmentation Fault.\n"},
      {141, "Broken Pipe.\n"},
      {255, "Exit status out of range.\n"},
      {0, NULL}
    };

char		*itoa(int nb)
{
  int		mul;
  int		i;
  int		len;
  int		tmp;
  char		*rslt;

  tmp = nb;
  len = 1;
  i = -1;
  mul = 1;
  while ((tmp = tmp / 10) != 0)
    {
      mul = mul * 10;
      ++len;
    }
  if ((rslt = malloc(sizeof(char) * (len + 1))) == NULL)
    return (NULL);
  while (mul / 10 > 0)
    {
      rslt[++i] = (((nb - (nb % mul)) / mul) % 10) + 48;
      mul = mul / 10;
    }
  rslt[++i] = (((nb - (nb % mul)) / mul) % 10) + 48;
  rslt[++i] = '\0';
  return (rslt);
}

int		change_status(t_env *env_list, int status)
{
  char		*nb;
  char		*stat;

  remove_env(env_list, "?=");
  if ((nb = itoa(status)) == NULL)
    return (-1);
  if ((stat = my_strcatdup("?=", nb, 1, ' ')) == NULL)
    return (-1);
  free(nb);
  if (add_chain(env_list, stat) == -1)
    return (-1);
  free(stat);
  return (0);
}

int		check_status(t_env *env_list, int status)
{
  int		i;

  i = -1;
  while (gl_status[++i].mess != NULL)
    {
      if (gl_status[i].nb == status)
	printf("%s", gl_status[i].mess);
    }
  if (change_status(env_list, status) == -1)
    return (-1);
  return (0);
}
