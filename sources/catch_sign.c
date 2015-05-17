/*
** catch_sign.c for catch_sign in /home/dcoodien/coodie/includes/42sh
** 
** Made by Dylan Coodien
** Login   <coodie_d@epitech.eu>
** 
** Started on  Sun May 17 21:01:29 2015 Dylan Coodien
** Last update Sun May 17 21:05:36 2015 Dylan Coodien
*/

#include <signal.h>
#include "sh42.h"

void	sign(int sig)
{
  (void)sig;
  printf("\n(user - 42sh )$>");
  signal(SIGINT, sign);
}
