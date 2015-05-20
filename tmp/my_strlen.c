/*
** my_strlen.c for shell_get_env in /home/cassin_f/B2/B2-Systeme_Unix/42sh_cassin
** 
** Made by François CASSIN
** Login   <cassin_f@epitech.net>
** 
** Started on  Mon May 18 03:38:57 2015 François CASSIN
** Last update Mon May 18 03:39:15 2015 François CASSIN
*/

int		my_strlen(char *str)
{
  int		i;

  i = 0;
  while (str[i])
    i = i + 1;
  return (i);
}
