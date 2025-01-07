# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ien-niou <ien-niou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/04 11:28:25 by ien-niou          #+#    #+#              #
#    Updated: 2025/01/05 16:43:21 by ien-niou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = checker.a
CC = cc
FLAGS = -Wall -Werror -Wextra
RM = rm -rf
AR = ar crs

# Colors
GREEN = \033[0;32m
YELLOW = \033[0;33m
RED = \033[0;31m
CYAN = \033[0;36m
RESET = \033[0m


SRC =	checker_bonus.c get_next_line_bonus.c get_next_line_utils_bonus.c  is_sorted_bonus.c \
		ft_strncmp_bonus.c creat_node_bonus.c \
		creat_node_bonus.c ft_lstadd_back_bonus.c ft_putchar_bonus.c ft_putnbr_pf_bonus.c ft_putstr_pf_bonus.c \
      ft_split_bonus.c ft_atoi_bonus.c ft_printf_bonus.c ft_puthex_pf_bonus.c ft_putptr_pf_bonus.c ft_putuint_pf_bonus.c \
      ft_isallready_bonus.c  ft_lstadd_front_bonus.c ./moves/ft_moves_bonus.c  ./moves/ft_moves1_bonus.c \
	  ft_lstsize_bonus.c logic_bonus.c  helpers_bonus.c test_bonus.c ft_putstr_fd.c

OBJS = $(SRC:.c=.o)
SW = checker_bonus.c


all: checker

$(NAME): $(OBJS)
	@$(AR) $(NAME) $(OBJS)

checker: $(NAME)
	@$(CC) $(FLAGS) $(SW) $(NAME) -o checker


%.o: %.c checker_bonus.h get_next_line_bonus.h 
	@$(CC) $(FLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJS)

fclean: clean
	@$(RM) $(NAME)
	@$(RM) checker

re: fclean all

.PHONY: all clean fclean re





