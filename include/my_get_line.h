/*
** my_get_line.h for 42sh_getline in /home/cassin_f/B2/B2-Systeme_Unix/42sh_cassin
**
** Made by François CASSIN
** Login   <cassin_f@epitech.net>
**
** Started on  Tue May 12 15:58:29 2015 François CASSIN
** Last update Thu May 21 15:23:09 2015 danilov dimitri
*/

#ifndef MY_GET_LINE_H_
# define MY_GET_LINE_H_

#include <termios.h>
#include <sys/types.h>
#include <dirent.h>
#include "my.h"

# define BUFF		10000

# define HISTORY_FILE	".42sh_history"

// CTRL_KEYS

# define CTRL_A		1
# define CTRL_B		2
# define CTRL_D		4
# define CTRL_E		5
# define CTRL_F		6
# define CTRL_H		8
# define CTRL_J		10
# define CTRL_K		11
# define CTRL_L		12
# define CTRL_N		14
# define CTRL_P		16
# define CTRL_T		20
# define CTRL_U		21
# define CTRL_W		23

// ACTIONS_KEYS

# define DELETE		0
# define BEG_LINE	1
# define END_LINE	2
# define CLEAR_SCREEN	3
# define DEL_LINE	4
# define EXCHANGE	5
# define DEL_ALL	6
# define DEL_WORD	7

# define DO_HISTO	8
# define UP_HISTO	9
# define BACK		10
# define FORE		11
# define DEL_BACK	12
# define COMPLET	13

# define DELETE_KEY	127

# define FILE		0
# define WORD		1
# define UNKNOWN	2

struct		s_line
{
  char		buffer[BUFF];
  char		character[BUFF];
  int		cursor_offset;
  int		cursor_position;
  int		history_offset;
  int		nb_char;
  int		nb_char_pos;
  int		cursor_begin;
  int		line_begin;
  int		line_nb;
};

typedef	struct s_line		t_line;

t_line		*g_line;

struct		s_caps
{
  int		column;
  int		line;
  char		*clear_str;
  char		*down_str;
  char		*DOWN_str;
  char		*up_str;
  char		*UP_str;
  char		*left_str;
  char		*LEFT_str;
  char		*right_str;
  char		*RIGHT_str;
  char		*cl_cureos_str;
  char		*savecu_str;
  char		*rescu_str;
};

typedef	struct s_caps		t_caps;

struct			s_complet
{
  char			*name;
  struct s_complet	*next;
  struct s_complet	*prev;
};

typedef	struct s_complet	t_complet;

struct		s_completion
{
  t_complet	*path;
  t_complet	*local;
};

typedef struct s_completion	t_completion;

struct		s_history
{
  char		*history_tab[1000];
  int		nb_max;
};

typedef struct s_history	t_history;

struct		s_params
{
  t_history	*history;
  t_completion	*completion;
  t_caps	*caps;
  t_env		*env;
};

typedef struct s_params		t_params;

struct		s_compl_par
{
  char		buffer[BUFF];
  int		offset_begin;
  int		type;
  t_complet	*file_opened;
  t_complet	*list_of_matched;
};

typedef	struct s_compl_par	t_compl_par;

char		**my_str_to_cmdtab(char *str);
char		*shell_get_line(t_env *env_list, int *stop);
void		my_fputchar(int fd, char c);
void		my_fputstr(int fd, char *str);
void		my_fputnbr(int fd, int nb);
char		*xtgetstr(char *id, char **area);
int		xtgetnum(char *id);
int		xtputs(char *str, int affcnt, int (*putc)(int));
int		xtputs_param(char *str, int affcnt, int (*putc)(int),
			     int param);
int		put_term_back(struct termios *t_attr);
int		init_completion(t_completion *complet, t_env *env);
void		free_tab(char **tabf);
int		init_path(t_complet *path, t_env *env);
int		init_local(t_complet *local);
void		add_elem_to_complet(t_complet *to_complet, char *str);
void		read_path(t_complet *path, DIR *dir, char *str);
void		read_local(t_complet *path, DIR *dir);
int		my_putint(int i);
int		my_getnbr(char *str);
void		get_cursor_pos(int *x, int *y);
void		refresh_screen(t_line *line, int cursor_off, char buffer[],
			       t_caps *cap);
int		get_cmd(t_line *line, t_params *params);
int		get_key(t_line *line);
int		check_ctrl(char buff[]);
int		my_strlen(char *str);
int		complete_history(t_history *history, t_env *env);
int		check_overflow(t_caps *cap, t_line *line, int len);
void		complete_matched_tab(t_compl_par *complete, t_line *line,
				     t_params *params);
void		aff_all_possibilities(t_params *params, t_complet *matched);
int		analyze_char(char c);
int		count_char_pos(char buff[], int offset);
void		free_complete(t_complet *to_free);
void		free_params(t_params *params);

//functions

void		del_char(t_params *params, t_line *line);
void		beg_line(t_params *params, t_line *line);
void		end_line(t_params *params, t_line *line);
void		del_line(t_params *params, t_line *line);
void		exchange(t_params *params, t_line *line);
void		del_all(t_params *params, t_line *line);
void		del_word(t_params *params, t_line *line);
void		down_histo(t_params *params, t_line *line);
void		up_histo(t_params *params, t_line *line);
void		backward(t_params *params, t_line *line);
void		foreward(t_params *params, t_line *line);
void		del_back(t_params *params, t_line *line);
void		complete(t_params *params, t_line *line);
void		myclear_screen(t_params *params, t_line *line);

void		go_left(int offset, char buff[], int nb_char);
void		go_right(int offset, char buff[], int nb_char, int len);

int		get_tab_file(t_params *params, t_compl_par *complete);


#endif /* !MY_GET_LINE_H_ */
