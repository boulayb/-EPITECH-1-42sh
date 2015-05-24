/*
** my_word.c for my_word in /home/danilo_d/semestre2/PSU_2014_42sh
**
** Made by danilov dimitri
** Login   <danilo_d@epitech.eu>
**
** Started on  Sun May 24 17:50:15 2015 danilov dimitri
** Last update Sun May 24 17:54:00 2015 danilov dimitri
*/

int	if_wordlen(char *str, int *i, int *quote)
{
  if (str[*i] == '"')
    {
      if (*quote == 0)
	*quote = 1;
      else
	*quote = 0;
    }
  return (0);
}
