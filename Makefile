# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ien-niou <ien-niou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/02 17:26:52 by ien-niou          #+#    #+#              #
#    Updated: 2025/01/03 10:44:11 by ien-niou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = swap.a
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


SRC = creat_node.c ft_lstadd_back_bonus.c ft_putchar.c ft_putnbr_pf.c ft_putstr_pf.c \
      ft_split.c ft_atoi.c ft_printf.c ft_puthex_pf.c ft_putptr_pf.c ft_putuint_pf.c \
      ft_isallready.c ./moves/ft_moves.c ft_lstadd_front_bonus.c ./moves/ft_moves1.c \
	  ft_lstsize_bonus.c logic.c ./sorts/sort.c helpers.c ./sorts/sort2.c

OBJS = $(SRC:.c=.o)
SW = push_swap.c


all: push_swap

$(NAME): $(OBJS)
	@$(AR) $(NAME) $(OBJS)

push_swap: $(NAME)
	@$(CC) $(FLAGS) $(SW) $(NAME) -o push_swap
	@echo "$(GREEN)Compilation successful!$(RESET)"


%.o: %.c ft_printf.h push_swap.h
	@$(CC) $(FLAGS) -c $< -o $@

clean:
	@echo "$(YELLOW)Object files removed.$(RESET)"
	@$(RM) $(OBJS)

fclean: clean
	@echo "$(RED)All files cleaned.$(RESET)"
	@$(RM) $(NAME)
	@$(RM) push_swap

re: fclean all
	@echo "$(CYAN)Rebuilt everything.$(RESET)"

.PHONY: all clean fclean re
