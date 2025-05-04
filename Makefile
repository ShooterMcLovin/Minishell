#------------------------------------------------------------------------------#
#                                  GENERICS                                    #
#------------------------------------------------------------------------------#

# Special variables
DEFAULT_GOAL: all
.DELETE_ON_ERROR: $(NAME)
.PHONY: all bonus clean fclean re
# 'HIDE = @' will hide all terminal output from Make
HIDE = @


#------------------------------------------------------------------------------#
#                                VARIABLES                                     #
#------------------------------------------------------------------------------#

# Compiler and flags
CC		=	gcc
CFLAGS	=	-Wall -Wextra 
RM		=	rm -f

# Output file name
NAME	=	minishell

# Sources are all .c files
SRCDIR	=	src/
SRCS	= src/absolute_path.c  \
src/builtins.c \
src/builtins2.c \
src/dollar.c \
src/env.c \
src/env2.c \
src/env_test.c \
src/err_codes.c \
src/err_msg.c \
src/exec.c \
src/exec2.c \
src/exit.c \
src/export.c \
src/free.c \
src/ft_cd.c \
src/heredoc.c \
src/main.c \
src/mini_split.c \
src/parsing.c \
src/parsing2.c \
src/pipes.c \
src/pipes2.c \
src/prompt.c \
src/redir.c \
src/redir2.c \
src/set_shlvl.c \
src/signals.c \
src/tokenize.c \
src/tokenize2.c \
src/utils.c \
src/utils2.c \
src/utils3.c \

# Objects are all .o files
OBJDIR	=	bin/
OBJS	=	$(patsubst $(SRCDIR)%.c,$(OBJDIR)%.o,$(SRCS))

# Includes are all .h files
INCDIR	=	include/
TEMP	=	.temp
RL_DIR	=	Readline/
RL_A	=	Readline/libreadline.a
INC		=	include/minishell.h

#------------------------------------------------------------------------------#
#                                 TARGETS                                      #
#------------------------------------------------------------------------------#

all: $(NAME) 
	@echo "$(Y)MINISHELL READY$(RT)"
	$(HIDE)stty -echoctl
# Generates output file
$(NAME): $(OBJS)
	$(HIDE)$(MAKE) -C libft
	$(HIDE)$(CC) $(CFLAGS) -lreadline -lncurses readline/libreadline.a libft/libft.a -o $@ $^

# Compiles sources into objects  
$(OBJS): $(OBJDIR)%.o : $(SRCDIR)%.c $(INCRL) $(INC) | $(OBJDIR)
	$(HIDE)$(CC) $(CFLAGS) -c $< -o $@
	@echo "$(G)Compiling : $(notdir $<) $(RT)"

# Creates directory for binaries
$(OBJDIR):
	$(HIDE)mkdir -p $@

clean:
	$(HIDE)$(RM) $(OBJS)
	$(HIDE)$(MAKE) -C libft clean
	$(HIDE)rm -f $(TEMP)

# Removes objects and executables
fclean: clean
	$(HIDE)$(RM) $(NAME)
	$(HIDE)$(MAKE) -C libft fclean
	$(HIDE)rm -rf bin/

# Removes objects and executables and remakes
re: clean all
	$(HIDE)$(MAKE) -C libft clean
	./minishell

RT	:= \033[0m
BK 	:= \033[90;1m
R 	:= \033[91;1m
G	:= \033[92;1m
Y	:= \033[93;1m
B 	:= \033[94;1m
P	:= \033[95;1m
C	:= \033[96;1m
W	:= \033[97;1m
