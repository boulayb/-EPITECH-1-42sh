##
## Makefile for minishell2 in /home/boulay_b/Rendu/SE2/PSU/PSU_2014_minishell2
##
## Made by Boulay Arnaud
## Login   <boulay_b@epitech.net>
##
## Started on  Wed Mar 11 19:12:25 2015 Boulay Arnaud
## Last update Sun Jun  7 17:14:58 2015 Dylan Coodien
##

NAME	= 42sh

SRCSFO	= sources/

SRCSTO	= sources/termcaps/

SRCS	= $(SRCSFO)main.c \
	  $(SRCSFO)my_wait.c \
	  $(SRCSFO)change_tild.c \
	  $(SRCSTO)new_history_file.c \
	  $(SRCSTO)shell_get_line_init.c \
	  $(SRCSTO)get_42shrc.c \
	  $(SRCSFO)epur_str.c \
	  $(SRCSTO)check_history_built.c \
	  $(SRCSTO)signal.c \
	  $(SRCSTO)my_fput.c \
	  $(SRCSTO)shell_get_line.c \
	  $(SRCSTO)xtputs.c \
	  $(SRCSTO)put_term_back.c \
	  $(SRCSTO)init_completion.c \
	  $(SRCSTO)init_local.c \
	  $(SRCSTO)init_path.c \
	  $(SRCSTO)read_complet.c \
	  $(SRCSTO)my_putint.c \
	  $(SRCSTO)get_cursor_pos.c \
	  $(SRCSTO)refresh_screen.c \
	  $(SRCSTO)get_cmd.c \
	  $(SRCSTO)get_key.c \
	  $(SRCSTO)history.c \
	  $(SRCSTO)del_char.c \
	  $(SRCSTO)beg_line.c \
	  $(SRCSTO)end_line.c \
	  $(SRCSTO)clear_screen.c \
	  $(SRCSTO)del_line.c \
	  $(SRCSTO)exchange.c \
	  $(SRCSTO)del_all.c \
	  $(SRCSTO)del_word.c \
	  $(SRCSTO)down_histo.c \
	  $(SRCSTO)up_histo.c \
	  $(SRCSTO)backward.c \
	  $(SRCSTO)foreward.c \
	  $(SRCSTO)del_back.c \
	  $(SRCSTO)complete.c \
	  $(SRCSTO)move.c \
	  $(SRCSTO)get_tab_file.c \
	  $(SRCSTO)complete_matched_tab.c \
	  $(SRCSTO)aff_all_possibilities.c \
	  $(SRCSTO)analyze_char.c \
	  $(SRCSTO)my_str_to_cmdtab.c \
	  $(SRCSTO)free_complete.c \
	  $(SRCSTO)free_params.c \
	  $(SRCSFO)get_next_line.c \
	  $(SRCSFO)xmalloc.c \
	  $(SRCSFO)count_moves.c \
	  $(SRCSFO)manip_list.c \
	  $(SRCSFO)verify_access.c \
	  $(SRCSFO)execute.c \
	  $(SRCSFO)reddir_left.c \
	  $(SRCSFO)free.c \
	  $(SRCSFO)reddir_right.c \
	  $(SRCSFO)do_cmd.c \
	  $(SRCSFO)pwd.c \
	  $(SRCSFO)cd.c \
	  $(SRCSFO)env.c \
	  $(SRCSFO)env_builtin.c \
	  $(SRCSFO)logic.c \
	  $(SRCSFO)list.c \
	  $(SRCSFO)is_cmd.c \
	  $(SRCSFO)inside.c \
	  $(SRCSFO)status.c \
	  $(SRCSFO)signal.c \
	  $(SRCSFO)count_quotes.c \
	  $(SRCSFO)strtowordtab.c \
	  $(SRCSFO)listtotab.c \
	  $(SRCSFO)string.c \
	  $(SRCSFO)builtins.c \
	  $(SRCSFO)tools.c \
	  $(SRCSFO)syntax.c \
	  $(SRCSFO)alias.c \
	  $(SRCSFO)tablen.c \
	  $(SRCSFO)my_word.c \
	  $(SRCSFO)my_history.c \
	  $(SRCSFO)alias_list.c \
	  $(SRCSFO)is_alias.c \
	  $(SRCSFO)alias_done.c \
	  $(SRCSFO)exec_alias.c \
	  $(SRCSFO)tabtostr.c \
	  $(SRCSFO)quotetowordtab.c \
	  $(SRCSFO)print_list.c

OBJS	= $(SRCS:.c=.o)

CFLAGS	+= -Iinclude/ -Wall -Wextra -Werror -lncurses

all: $(NAME)

$(NAME): $(OBJS)
	cc -o $(NAME) $(OBJS) $(CFLAGS)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
