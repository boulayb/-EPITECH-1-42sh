/*
** reddir_left.c for reddir_left in /home/danilo_d/semestre2/coodie
**
** Made by danilov dimitri
** Login   <danilo_d@epitech.eu>
**
** Started on  Sun May 10 16:28:24 2015 danilov dimitri
** Last update Sun May 24 19:42:54 2015 Sebastien BOULOC
*/

#include	<string.h>
#include	<sys/types.h>
#include	<sys/stat.h>
#include	<fcntl.h>
#include	<unistd.h>
#include	<stdlib.h>
#include	<stdio.h>
#include	"sh42.h"

extern int	g_fd;

t_list		*go_trough_left_reddir(t_list *tmp)
{
  while (tmp->back->act == LEFT || tmp->back->act == DLEFT)
    tmp = tmp->next;
  return (tmp);
}

static int	create_new_data(char *line, t_data *list)
{
  t_data	*elem;

  if ((elem = xmalloc(sizeof(t_data))) == NULL)
    return (-1);
  if ((elem->line = strdup(line)) == NULL)
    return (-1);
  elem->back = list->back;
  elem->next = list;
  list->back->next = elem;
  list->back = elem;
  return (0);
}

static int	dleft_reddirection(t_list *tmp, int flag)
{
  char		line[5000];
  t_data	*data;
  int		ret;

  if ((data = xmalloc(sizeof(t_data))) == NULL)
    return (-1);
  data->next = data;
  data->back = data;
  write(1, "> ", 2);
  while ((ret = read(0, line, 4098)) > 0)
    {
      line[ret - 1] = 0;
      if (strcmp(tmp->av[0], line) == 0)
        {
          if (flag == 1)
            print_list(data);
          return (0);
        }
      if (create_new_data(line, data) == -1)
        return (-1);
      write(1, "> ", 2);
    }
  free_list2(data);
  return (0);
}

static t_list	*write_on_std_output(t_list *tmp)
{
  while (tmp->back->act == LEFT || tmp->back->act == DLEFT)
    {
      if (tmp->back->act == LEFT &&
          ((g_fd = open(tmp->av[0], O_RDWR,
                      S_IRUSR | S_IWUSR | S_IRGRP
			| S_IWGRP | S_IROTH)) == -1))
        return (NULL);
      if (tmp->back->act == DLEFT && tmp->act != DLEFT && tmp->act != LEFT)
        dleft_reddirection(tmp, 1);
      else if (tmp->back->act == DLEFT)
        dleft_reddirection(tmp, 0);
      tmp = tmp->next;
    }
  return (tmp);
}

t_list		*check_left_reddir(t_list *list, t_list *tmp2)
{
  t_list	*tmp;
  t_list	*tmp3;

  tmp = tmp2;
  while (tmp != list)
    {
      if (tmp->act == LEFT || tmp->act == DLEFT)
	{
	  tmp = tmp->next;
	  if ((tmp = write_on_std_output(tmp)) == NULL)
	    return (NULL);
	  tmp3 = tmp->back;
	  while (tmp3->back->act == LEFT || tmp3->back->act == DLEFT)
	    {
	      tmp3 = tmp3->back;
	      tmp3->act = tmp3->next->act;
	      sup_elem(tmp3->next);
	    }
	  return (tmp);
	}
      tmp = tmp->next;
    }
  return (tmp);
}
