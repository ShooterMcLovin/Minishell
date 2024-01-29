
BK		:= \033[30;1m
R		:= \033[31;1m
G		:= \033[32;1m
Y		:= \033[33;1m
B		:= \033[34;1m
M		:= \033[35;1m
C		:= \033[36;1m
WHITE	:= \033[37;1m
RESET	:= \033[0m

NAME = libft.a

SRCS	=	src/ftpnb.c src/ft_atoi.c src/ft_bzero.c src/ft_calloc.c src/ft_isalnum.c src/ft_isalpha.c src/ft_isascii.c src/ft_isdigit.c src/ft_isprint.c src/ft_itoa.c src/ft_memchr.c src/ft_memcmp.c src/ft_memcpy.c src/ft_memmove.c src/ft_memset.c src/ft_putchar_fd.c src/ft_putendl_fd.c src/ft_putnbr_fd.c src/ft_putstr_fd.c src/ft_split.c src/ft_strchr.c src/ft_strdup.c src/ft_striteri.c src/ft_strjoin.c src/ft_strlcat.c src/ft_strlcpy.c src/ft_strlen.c src/ft_strmapi.c src/ft_strncmp.c src/ft_strnstr.c src/ft_strrchr.c src/ft_strtrim.c src/ft_substr.c src/ft_tolower.c src/ft_toupper.c src/ft_lstnew.c src/ft_lstadd_front.c src/utils.c src/ft_lstsize.c src/ft_lstlast.c src/ft_lstadd_back.c src/ft_lstdelone.c src/ft_strdup2.c src/ft_lstclear.c src/ft_lstiter.c src/ft_lstmap.c \
			src/get_next_line.c src/get_next_line_utils.c \
			src/ft_printf.c src/ft_printptr.c src/ft_printstr.c src/ft_printnbr_base.c src/ft_printnbr.c src/ft_printf_utils.c\

INC = include/libft.h \

CC = gcc
CFLAGS = -Wall -Werror -Wextra -I. -I./$(INCDIR)
RM = rm -f
AR = ar -rcs

SRCDIR	=	src/
OBJDIR	=	bin/
OBJS	=	$(patsubst $(SRCDIR)%.c,$(OBJDIR)%.o,$(SRCS))
INCDIR	=	include/

all: $(NAME)
	@echo "$(Y) LIBFT IS UP TO DATE$(RESET)"

$(NAME): $(OBJS)
	@$(AR) $@ $^

$(OBJS): $(OBJDIR)%.o : $(SRCDIR)%.c $(INC) | $(OBJDIR)
	@echo "$(G)Compiling: $(B)$<$(RESET)"
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR):
	$(HIDE)mkdir -p $@

clean:
	@$(RM) $(OBJS) 

fclean: clean
	@$(RM) $(NAME)

re: fclean all
