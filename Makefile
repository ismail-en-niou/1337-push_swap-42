# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ien-niou <ien-niou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/02 17:26:52 by ien-niou          #+#    #+#              #
#    Updated: 2025/01/04 13:10:00 by ien-niou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = swap.a
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


SRC = ./includes/creat_node.c ./includes/ft_lstadd_back_bonus.c ./includes/ft_putchar.c ./includes/ft_putnbr_pf.c ./includes/ft_putstr_pf.c \
      ./includes/ft_split.c ./includes/ft_atoi.c ./includes/ft_printf.c ./includes/ft_puthex_pf.c ./includes/ft_putptr_pf.c ./includes/ft_putuint_pf.c \
      ./includes/ft_isallready.c ./moves/ft_moves.c ./includes/ft_lstadd_front_bonus.c ./moves/ft_moves1.c \
      ./includes/ft_lstsize_bonus.c ./includes/logic.c ./sorts/sort.c ./includes/helpers.c ./sorts/sort2.c ./includes/ft_putstr_fd.c

OBJS = $(SRC:.c=.o)
SW = push_swap.c
BONUS_FLAG = .bonus

all: push_swap

$(NAME): $(OBJS)
	@$(AR) $(NAME) $(OBJS)

push_swap: $(NAME) $(SW)
	@$(CC) $(FLAGS) $(SW) $(NAME) -o push_swap
	@echo "$(GREEN)Compilation successful!$(RESET)"

%.o: %.c ./includes/ft_printf.h ./includes/push_swap.h
	@$(CC) $(FLAGS) -c $< -o $@

bonus: $(BONUS_FLAG)

$(BONUS_FLAG): 
	@if [ ! -f $(BONUS_FLAG) ]; then \
		$(MAKE) -C bonus; \
		mkdir $(BONUS_FLAG); \
		echo "$(CYAN)Bonus compilation complete!$(RESET)"; \
		mv ./bonus/checker .; \
	else \
		echo "$(YELLOW)Bonus not built, skipping...$(RESET)"; \
	fi

clean:
	@echo "$(YELLOW)Object files removed.$(RESET)"
	@$(RM) -rf $(OBJS) $(BONUS_FLAG)
	@if [ -d "bonus" ]; then \
		$(MAKE) -C bonus clean; \
	fi

fclean: clean
	@echo "$(RED)All files cleaned.$(RESET)"
	@$(RM) $(NAME)
	@$(RM) push_swap checker
	@if [ -d "bonus" ]; then \
		$(MAKE) -C bonus fclean; \
	fi

re: fclean all
	@echo "$(CYAN)Rebuilt everything.$(RESET)"

.PHONY: all clean fclean re bonus
