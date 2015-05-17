/*
** xmalloc.c for xmalloc in /home/dcoodien/rendu/SysUnix/B2/coodie/src
**
** Made by Dylan Coodien
** Login   <coodie_d@epitech.eu>
**
** Started on  Sun May  3 17:33:04 2015 Dylan Coodien
** Last update Fri May 15 15:11:42 2015 danilov dimitri
*/

#include <stdlib.h>
#include <stdio.h>

void	*xmalloc(size_t size)
{
  void	*str;

  if ((str = malloc(size)) == NULL)
    {
      fprintf((FILE *)2, "Malloc failed\n");
      return (NULL);
    }
  return (str);
}
