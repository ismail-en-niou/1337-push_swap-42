/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ien-niou <ien-niou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 10:28:20 by ien-niou          #+#    #+#             */
/*   Updated: 2024/12/30 17:07:45 by ien-niou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>


typedef struct s_stack
{
    int content;
    int index;
    struct s_stack *next;
}t_stack;

char	**split(char *s);
t_stack *create_node(int content);
int if_allready(t_stack *stack) ;
void	ft_lstadd_back(t_stack **lst, t_stack *new);

#endif