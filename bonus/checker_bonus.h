/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ien-niou <ien-niou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 10:14:00 by ien-niou          #+#    #+#             */
/*   Updated: 2025/01/07 10:15:27 by ien-niou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# include "../ft_printf.h"
# include "get_next_line_bonus.h"
# include <limits.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int				content;
	int				index;
	struct s_stack	*next;
}					t_stack;

void				check_str(t_stack **a, t_stack **b, char *str);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					process_value(t_stack **a, char **res, int j);
int					process_input(t_stack **a, char **av, int ac);
char				**ft_split(char const *s, char c);
void				edit_index(t_stack *s);
int					is_number(char *str);
int					is_empty_or_whitespace(char **str, int ac);
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
void				_ss(t_stack **a, t_stack **b, char *msg);
void				_rr(t_stack **a, t_stack **b, bool isrev, char *msg);
void				_revrotate(t_stack **head, char *msg);

// sort
void				sort(t_stack **a, t_stack **b);
void				ft_list_handeler(t_stack **a, t_stack **b);

#endif