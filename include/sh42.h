/*
** 42sh.h for 42sh in /home/dcoodien/rendu/SysUnix/B2/coodie
**
** Made by Dylan Coodien
** Login   <coodie_d@epitech.eu>
**
** Started on  Tue Apr 28 11:38:58 2015 Dylan Coodien
** Last update Sat May 23 15:54:21 2015 danilov dimitri
*/

#ifndef SH42_H_
# define SH42_H_

# define LEFT	1
# define DLEFT	2
# define RIGHT	3
# define DRIGHT	4
# define PIPE	5
# define ENDACT	42

typedef struct	s_data
{
  char		*line;
  struct s_data	*next;
  struct s_data	*back;
}		t_data;

typedef struct	s_list
{
  char		**av;
  char		act;
  struct s_list	*next;
  struct s_list	*back;
}		t_list;

int		count_av(char **av, int *);
int		count_moves(char **av);
int		my_put_in_list(t_list *list, char **av, int *, int *);
void		*xmalloc(size_t size);
int		start_cmd(t_list *list, char **env);
int		verify_access(t_list *comm, char **path);
t_list		*write_on_std_output(t_list *tmp);
t_list		*create_file(t_list *tmp, int fd_tmp);
t_list		*go_trough_left_reddir(t_list *tmp);
t_list          *write_on_std_output(t_list *tmp);
int		dleft_reddirection(t_list *tmp, int flag);
t_list		*check_left_reddir(t_list *list, t_list *tmp2);
void		free_tab(char **tab);
int		print_list(t_data *list);
char		*concat_string(char *command, char *path);
void		free_list2(t_data *data);

#endif /* !SH42_H_ */
