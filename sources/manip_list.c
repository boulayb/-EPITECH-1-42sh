/*
** manip_list.c for manip_list in /home/dcoodien/rendu/SysUnix/B2/coodie/src
**
** Made by Dylan Coodien
** Login   <coodie_d@epitech.eu>
**
** Started on  Mon May  4 12:25:43 2015 Dylan Coodien
** Last update Thu May 21 23:28:05 2015 danilov dimitri
*/

#define _GNU_SOURCE

#include <stdlib.h>
#include <string.h>
#include "sh42.h"

char		**set_av(char **av, int nb, int *av_nbr)
{
  char		**argv;
  int		i;

  i = 0;
  if ((argv = xmalloc(sizeof(char *) * (nb + 2))) == NULL)
    return (NULL);
  while (i < nb)
    {
      if ((argv[i] = strdup(av[*av_nbr])) == NULL)
	return (NULL);
      ++(*av_nbr);
      ++i;
    }
  argv[i] = NULL;
  return (argv);
}

void		fill_act(t_list *list, char **av, int *av_nbr)
{
  if (av[*av_nbr] != NULL)
    {
      if (strcmp(av[*av_nbr], "|") == 0)
	list->act = PIPE;
      if (strcmp(av[*av_nbr], ">") == 0)
	list->act = RIGHT;
      if (strcmp(av[*av_nbr], "<") == 0)
	list->act = LEFT;
      if (strcmp(av[*av_nbr], ">>") == 0)
	list->act = DRIGHT;
      if (strcmp(av[*av_nbr], "<<") == 0)
	list->act = DLEFT;
      *av_nbr += 1;
    }
  else
    list->act = ENDACT;
}

int		my_put_in_list(t_list *list, char **av, int *i, int *av_nbr)
{
  t_list	*elem;
  int		nb;

  if ((elem = xmalloc(sizeof(*elem))) == NULL)
    return (-1);
  nb = count_av(av, i);
  if ((elem->av = set_av(av, nb, av_nbr)) == NULL)
    return (-1);
  fill_act(elem, av, av_nbr);
  elem->back = list->back;
  elem->next = list;
  list->back->next = elem;
  list->back = elem;
  return (0);
}
