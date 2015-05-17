/*
** main.c for minishell1 in /home/boulay_b/Rendu/PSU/PSU_2014_minishell1
**
** Made by arnaud boulay
** Login   <boulay_b@epitech.net>
**
** Started on  Mon Jan 19 11:23:19 2015 arnaud boulay
** Last update Sun May 17 21:05:44 2015 Dylan Coodien
*/

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include "my.h"
#include "sh42.h"

static t_builtins	gl_builtins[] =
  {
    {"cd", &my_cd},
    {"env", &my_env},
    {"setenv", &my_setenv},
    {"unsetenv", &my_unsetenv},
    {"echo", &my_echo},
    {NULL, NULL}
  };

void			disp_prompt(t_env *env_list)
{
  static int		i;

  my_putstr(BLUE);
  my_putchar('(');
  if (env_list != NULL && get_env("USER=", env_list) != NULL)
    my_putstr(get_env("USER=", env_list) + 5);
  else
    my_putstr("user");
  my_putstr(" - ");
  if (env_list != NULL && get_env("PWD=/", env_list) != NULL)
    my_putstr(get_env("PWD=/", env_list) + 4);
  else
    my_putstr("42sh");
  my_putchar(' ');
  my_putstr(LIGHT_BLUE);
  my_putnbr(i++);
  my_putstr(BLUE);
  my_putstr(")$>");
  my_putstr(LIGHT_BLUE);
}

int			fcnt_ptr(char **tab, char **path, t_env *env_list)
{
  int			status;
  int			i;

  i = -1;
  if (my_strcmp("exit", tab[0]) == 1)
    {
      if (tab[1] != NULL)
	return (my_getnbr(tab[1]));
      else
	return (-2);
    }
  while (gl_builtins[++i].str != NULL)
    {
      if (my_strcmp(tab[0], gl_builtins[i].str) == 1)
	{
	  if (gl_builtins[i].ptr(tab, path, env_list) == -1)
	    return (-1);
	  return (0);
	}
    }
  if ((status = exec_program(tab, path, env_list)) == -1)
    return (-1);
  if (check_status(env_list, status) == -1)
    return (-1);
  return (0);
}

int			my_prompt(char *str, char **path, t_env *env_list)
{
  char			**tabsep;
  int			ret;
  int			i;

  tabsep = NULL;
  i = -1;
  ret = 0;
  if ((tabsep = my_strtowordtab(tabsep, str, ";")) == NULL)
    return (-1);
  while (ret == 0 && tabsep[++i] != NULL)
    {
      if ((ret = logic_sep_and(tabsep[i], path, env_list)) == -1)
	return (-1);
    }
  if (ret == 0)
    disp_prompt(env_list);
  free(str);
  free_tab(tabsep);
  free_tab(path);
  return (ret);
}

int			my_minishell(char **env)
{
  t_env			*env_list;
  int			ret;
  char			**path;
  char			*str;

  path = NULL;
  ret = 0;
  if ((env_list = create_list(env)) == NULL)
    return (-1);
  disp_prompt(env_list);
  my_signal();
  while (ret == 0 && (str = get_next_line(0)) != NULL)
    {
      if (check_env(env_list) == -1)
	return (-1);
      if ((path = my_strtowordtab(path, get_env("PATH=", env_list) + 5, ":"))
	  == NULL)
	return (-1);
      if ((ret = my_prompt(str, path, env_list)) == -1)
	return (-1);
    }
  rm_list(env_list);
  return (ret);
}

int			main(int ac, char **av, char **env)
{
  int			ret;

  (void)ac;
  (void)av;
  signal(SIGINT, sign);
  if ((ret = my_minishell(env)) == -1)
    return (-1);
  printf("exit\n");
  my_putstr(DEFAULT);
  if (ret == -2)
    return (0);
  return (ret);
}
