/*
** my_wait.c for my_wait in /home/coodie_d/PSU_2014_42sh
** 
** Made by Dylan Coodien
** Login   <coodie_d@epitech.eu>
** 
** Started on  Sun Jun  7 17:11:59 2015 Dylan Coodien
** Last update Sun Jun  7 17:12:59 2015 Dylan Coodien
*/

#include <sys/wait.h>
#include "sh42.h"

t_list	*my_wait(int *status, pid_t pid, t_list *cmd)
{
  while (waitpid(pid, status, WUNTRACED) > 0);
  return (cmd);
}
