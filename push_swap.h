/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ien-niou <ien-niou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 10:28:20 by ien-niou          #+#    #+#             */
/*   Updated: 2025/01/03 15:34:56 by ien-niou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "ft_printf.h"
# include <limits.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

#define THRESHOLD_FACTOR 0.045
#define THRESHOLD_OFFSET 10

typedef struct s_stack
{
	int				content;
	int				index;
	struct s_stack	*next;
}					t_stack;

typedef struct sort_list
{
	int				min_range;
	int				max_range;
	int				iter;
}					t_sort;
int					process_value(t_stack **a, char **res, int j);
int					process_input(t_stack **a, char **av, int ac);
char				**ft_split(char const *s, char c);
void				edit_index(t_stack *s);
int					is_number(char *str);
// free
void				free_stack(t_stack **stack);
size_t				ft_atoi(char *str);
// list
t_stack				*create_node(int content);
t_stack				*create_node(int value);
void				ft_swap_if_needed(t_stack **b);
void				ft_print_list(t_stack *s);
int					if_allready(t_stack *stack);
void				ft_lstadd_back(t_stack **lst, t_stack *new);
void				ft_lstadd_front(t_stack **lst, t_stack *new);
t_stack				*ft_lstlast(t_stack *lst);
t_stack				*secondlast(t_stack *head);
int					is_sorted(t_stack *a);
int					ft_lstsize(t_stack *lst);
int					max_r(t_stack *a);
t_stack				*create_node(int value);
t_stack				*ft_lstmax(t_stack *lst);
void				ft_print_list(t_stack *s);
// moves
void				_swap(t_stack **head, char *msg);
void				_push(t_stack **head_a, t_stack **head_b, char *msg);
void				_rotat(t_stack **head, char *msg);
void				_ss(t_stack **a, t_stack **b);
void				_rr(t_stack **a, t_stack **b, bool isrev, char *msg);
void				_revrotate(t_stack **head, char *msg);

// sort
void				sort(t_stack **a, t_stack **b);
void				ft_list_handeler(t_stack **a, t_stack **b);

#endif