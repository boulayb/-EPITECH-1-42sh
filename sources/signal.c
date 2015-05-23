/*
** signal.c for minishell1 in /home/boulay_b/Rendu/PSU/PSU_2014_minishell1
**
** Made by arnaud boulay
** Login   <boulay_b@epitech.net>
**
** Started on  Sun Feb  1 14:49:42 2015 arnaud boulay
** Last update Sat May 23 13:59:23 2015 danilov dimitri
*/

#include <signal.h>
#include "my.h"

void		my_signal(void)
{
  signal(SIGINT, catch_signal);
  signal(SIGTSTP, catch_signal);
}
