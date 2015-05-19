##
## Makefile for minishell2 in /home/boulay_b/Rendu/SE2/PSU/PSU_2014_minishell2
##
## Made by Boulay Arnaud
## Login   <boulay_b@epitech.net>
##
## Started on  Wed Mar 11 19:12:25 2015 Boulay Arnaud
## Last update Tue May 19 14:40:28 2015 Dylan Coodien
##

NAME	= 42sh

SRCSFO	= sources/

SRCS	= $(SRCSFO)main.c \
	  $(SRCSFO)catch_sign.c \
	  $(SRCSFO)get_next_line.c \
	  $(SRCSFO)xmalloc.c \
	  $(SRCSFO)count_moves.c \
	  $(SRCSFO)manip_list.c \
	  $(SRCSFO)verify_access.c \
	  $(SRCSFO)execute.c \
	  $(SRCSFO)reddir_left.c \
	  $(SRCSFO)reddir_right.c \
	  $(SRCSFO)do_cmd.c \
	  $(SRCSFO)pwd.c \
	  $(SRCSFO)cd.c \
	  $(SRCSFO)env.c \
	  $(SRCSFO)env_builtin.c \
	  $(SRCSFO)logic.c \
	  $(SRCSFO)list.c \
	  $(SRCSFO)inside.c \
	  $(SRCSFO)status.c \
	  $(SRCSFO)signal.c \
	  $(SRCSFO)strtowordtab.c \
	  $(SRCSFO)listtotab.c \
	  $(SRCSFO)string.c \
	  $(SRCSFO)builtins.c \
	  $(SRCSFO)tools.c \
	  $(SRCSFO)print_list.c

OBJS	= $(SRCS:.c=.o)

CFLAGS	= -Iinclude/ -Wall -Wextra -Werror -ansi -pedantic

all: $(NAME)

debug: CFLAGS += -g3
debug: all

$(NAME): $(OBJS)
	cc -o $(NAME) $(OBJS) $(CFLAGS)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
