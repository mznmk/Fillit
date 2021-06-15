# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmizuno <mmizuno@student.42tokyo.jp>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/14 13:32:12 by mmizuno           #+#    #+#              #
#    Updated: 2021/06/15 09:21:18 by mmizuno          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ================================= Variable ================================= #

NAME				= fillit

PRJ_DIR				= ./

FILLIT_DIR			= $(PRJ_DIR)
FILLIT_INCDIR		= $(FILLIT_DIR)include/
FILLIT_SRCDIR		= $(FILLIT_DIR)source/
FILLIT_SRCNAME		= print_message.c \
					  read_tetrimino.c \
					  validate_tetrimino.c \
					  parse_tetrimino.c \
					  print_tetrimino.c \
					  main.c
FILLIT_SRCS			= $(addprefix $(FILLIT_SRCDIR), $(FILLIT_SRCNAME))
FILLIT_OBJS			= $(FILLIT_SRCS:.c=.o)

LIBFT_NAME			= libft.a
LIBFT_LIBNAME		= ft
LIBFT_DIR			= ./libft/
LIBFT_INCDIR		= $(LIBFT_DIR)includes/

CC					= gcc
CFLAGS				= -Wall -Wextra -Werror -g -fsanitize=address
INCDIR				= -I $(FILLIT_INCDIR)
INCDIR				+= -I $(LIBFT_INCDIR)
LIBDIR				= -L $(LIBFT_DIR)
LIBS				= -l $(LIBFT_LIBNAME)

RM					= rm -f

# ---------------------------------- color ----------------------------------- #

ESC_RESET			= \033[0m
ESC_FNT_BOLD		= \033[1m
ESC_FNT_FINE		= \033[2m
ESC_FNT_ITALIC		= \033[3m
ESC_FNT_ULINE		= \033[4m
ESC_CLR_BLACK		= \033[38;5;00m
ESC_CLR_RED			= \033[38;5;01m
ESC_CLR_GREEN		= \033[38;5;02m
ESC_CLR_YELLOW		= \033[38;5;03m
ESC_CLR_BLUE		= \033[38;5;04m
ESC_CLR_MAGENTA		= \033[38;5;05m
ESC_CLR_CYAN		= \033[38;5;06m
ESC_CLR_WHITE		= \033[38;5;07m
ESC_CLR_PINK		= \033[38;5;213m

# =============================== Make Command =============================== #

# ---------------------------------- .c.o ------------------------------------ #

.c.o:
					$(CC) $(CFLAGS) $(INCDIR) -c $< -o $(<:.c=.o)

# --------------------------------- $(NAME) ---------------------------------- #

$(NAME):			$(FILLIT_OBJS)
					@make $(LIBFT_NAME)
					$(CC) $(CFLAGS) $(FILLIT_OBJS) $(LIBDIR) $(LIBS) -o $(NAME)
					@echo "$(ESC_FNT_BOLD)$(ESC_CLR_GREEN)[ $(NAME) successfully compiled !! ]$(ESC_RESET)"

# ----------------------------------- all ------------------------------------ #

all: 				$(NAME)

# --------------------------------- $(LIBFT) --------------------------------- #

$(LIBFT_NAME):
					@cd $(LIBFT_DIR) && make

# -------------------------------- mandatory --------------------------------- #

mandatory:			$(NAME)

# ---------------------------------- bonus ----------------------------------- #

bonus:				$(NAME)

# ---------------------------------- clean ----------------------------------- #

clean:
					@cd $(LIBFT_DIR) && make clean
					$(RM) $(FILLIT_OBJS)

# ---------------------------------- fclean ---------------------------------- #

fclean:				clean
					@cd $(LIBFT_DIR) && make fclean
					$(RM) $(NAME)

# ------------------------------------ re ------------------------------------ #

re:					fclean all

# ---------------------------------- .PHONY ---------------------------------- #

.PHONY:				all clean fclean re mandatory bonus
