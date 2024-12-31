NAME	=	swap.a
cc = gcc 
SRC	= creat_node.c            ft_lstadd_back_bonus.c  ft_putchar.c            ft_putnbr_pf.c          ft_putstr_pf.c          ft_split.c \
ft_atoi.c               ft_printf.c             ft_puthex_pf.c          ft_putptr_pf.c          ft_putuint_pf.c     ft_isallready.c 

OBJS = $(SRC:.c=.o)
SW = push_swap.c

CC = cc
FLAGS = -Wall -Werror -Wextra
RM = rm -rf
AR = ar crs

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)
	$(CC) $(FLAGS) $(SW) $(NAME) -o push_swap 

all: $(NAME)

%.o: %.c ft_printf.h
	$(CC) $(FLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(NAME)		
	$(RM) push_swap 

re:	fclean all

.PHONY:	all clean fclean re