/*
** inside.c for 42sh in /home/boulay_b/Work/SE2/PSU/42sh/PSU_2014_minishell2
**
** Made by Arnaud Boulay
** Login   <boulay_b@epitech.net>
**
** Started on  Thu May 14 20:53:43 2015 Arnaud Boulay
** Last update Thu May 14 20:53:44 2015 Arnaud Boulay
*/

int	is_char_inside(char *str, char c)
{
  int	i;

  i = -1;
  while (str[++i] != '\0')
    if (str[i] == c)
      return (1);
  return (0);
}

int	is_inside(char *str, char *str2)
{
  int	i;
  int	j;

  i = -1;
  j = 0;
  while (str[++i] != '\0')
    if (str[i] == str2[j])
      {
	if (str2[++j] == '\0')
	  return (1);
      }
    else if (j != 0)
      return (0);
  return (0);
}
