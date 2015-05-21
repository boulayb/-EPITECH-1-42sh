/*
** move.c for shell_get_line in /home/cassin_f/B2/B2-Systeme_Unix/42sh_cassin
** 
** Made by François CASSIN
** Login   <cassin_f@epitech.net>
** 
** Started on  Mon May 18 15:01:51 2015 François CASSIN
** Last update Mon May 18 16:23:53 2015 François CASSIN
*/

#include "my_get_line.h"

void		go_left(int offset, char buff[], int nb_char)
{
  while (offset < nb_char)
    {
      buff[offset] = buff[offset + 1];
      ++offset;
    }
}

void		go_right(int offset, char buff[], int nb_char, int len)
{
  while (nb_char + len - 1 > offset)
    {
      buff[nb_char + len - 1] = buff[nb_char - 1];
      --nb_char;
    }
}
