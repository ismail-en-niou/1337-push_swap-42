# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ien-niou <ien-niou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/04 11:28:25 by ien-niou          #+#    #+#              #
#    Updated: 2025/01/04 13:19:58 by ien-niou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = checker.a
CC = gcc
FLAGS = -Wall -Werror -Wextra
RM = rm -rf
AR = ar crs

# Colors
GREEN = \033[0;32m
YELLOW = \033[0;33m
RED = \033[0;31m
CYAN = \033[0;36m
RESET = \033[0m


SRC =	checker.c get_next_line.c get_next_line_utils.c  is_sorted.c \
		ft_strncmp.c creat_node.c \
		creat_node.c ft_lstadd_back_bonus.c ft_putchar.c ft_putnbr_pf.c ft_putstr_pf.c \
      ft_split.c ft_atoi.c ft_printf.c ft_puthex_pf.c ft_putptr_pf.c ft_putuint_pf.c \
      ft_isallready.c  ft_lstadd_front_bonus.c ./moves/ft_moves.c  ./moves/ft_moves1.c \
	  ft_lstsize_bonus.c logic.c  helpers.c test.c

OBJS = $(SRC:.c=.o)
SW = checker.c


all: checker

$(NAME): $(OBJS)
	@$(AR) $(NAME) $(OBJS)

checker: $(NAME)
	@$(CC) $(FLAGS) $(SW) $(NAME) -o checker
	@echo "$(GREEN)Compilation successful!$(RESET)"


%.o: %.c checker.h get_next_line.h 
	@$(CC) $(FLAGS) -c $< -o $@

clean:
	@echo "$(YELLOW)Object files removed.$(RESET)"
	@$(RM) $(OBJS)

fclean: clean
	@echo "$(RED)All files cleaned.$(RESET)"
	@$(RM) $(NAME)
	@$(RM) checker

re: fclean all
	@echo "$(CYAN)Rebuilt everything.$(RESET)"

.PHONY: all clean fclean re





