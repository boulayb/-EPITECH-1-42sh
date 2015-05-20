##
## Makefile for 42sh_getline in /home/cassin_f/B2/B2-Systeme_Unix/42sh_cassin
## 
## Made by François CASSIN
## Login   <cassin_f@epitech.net>
## 
## Started on  Tue May 12 15:49:00 2015 François CASSIN
## Last update Wed May 20 15:04:21 2015 François CASSIN
##

CC	= gcc

RM	= rm -f

CFLAGS	+= -Wall -Werror -Wextra
CFLAGS	+= -I./

NAME	= get_line42sh

SRCS	= main.c \
	  shell_get_line.c \
	  env.c \
	  list.c \
	  xtputs.c \
	  put_term_back.c \
	  my_strcmp.c \
	  free_tab.c \
	  init_completion.c \
	  init_local.c \
	  init_path.c \
	  read_complet.c \
	  my_putint.c \
	  my_getnbr.c \
	  get_cursor_pos.c \
	  refresh_screen.c \
	  get_cmd.c \
	  get_key.c \
	  my_strlen.c \
	  history.c \
	  get_next_line.c \
	  ./functions/del_char.c \
	  ./functions/beg_line.c \
	  ./functions/end_line.c \
	  ./functions/clear_screen.c \
	  ./functions/del_line.c \
	  ./functions/exchange.c \
	  ./functions/del_all.c \
	  ./functions/del_word.c \
	  ./functions/down_histo.c \
	  ./functions/up_histo.c \
	  ./functions/backward.c \
	  ./functions/foreward.c \
	  ./functions/del_back.c \
	  ./functions/complete.c \
	  ./functions/move.c \
	  ./functions/get_tab_file.c \
	  ./nmatch.c \
	  ./functions/complete_matched_tab.c \
	  ./functions/aff_all_possibilities.c \
	  ./analyze_char.c \
	  ./my_str_to_cmdtab.c \
	  ./functions/free_complete.c \
	  ./free_params.c

OBJS	= $(SRCS:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJS)
		$(CC) -o $(NAME) $(OBJS) -lncurses

clean:
		$(RM) $(OBJS)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all

.PHONY:		all clean fclean re
