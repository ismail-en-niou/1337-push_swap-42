/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ien-niou <ien-niou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 17:29:49 by ien-niou          #+#    #+#             */
/*   Updated: 2024/12/30 17:30:14 by ien-niou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"
#include "ft_printf.h"

void ft_print_list(t_stack *s) {
    if (!s)
        return;
    while (s) {
        ft_printf("%d index : %d\n", s->content , s->index);
        s = s->next;
    }
}

void edit_index(t_stack *s) {
    if (!s)
        return;

    t_stack *temp1 = s;
    t_stack *temp2;
    int index;

    while (temp1) {
        temp2 = s; 
        index = 0;
        while (temp2) {
            if (temp1->content > temp2->content)
                index++;
            temp2 = temp2->next;
        }
        temp1->index = index;
        temp1 = temp1->next;
    }
}


int is_valid(char *str) {
    int i = 0;

    if (str[0] == '-' || str[0] == '+')
        i++;
    while (str[i]) {
        if (str[i] >= '0' && str[i] <= '9')
            i++;
        else
            return 0;
    }
    return 1;
}

void free_stack(t_stack **stack) {
    t_stack *temp;

    while (*stack) {
        temp = *stack;
        *stack = (*stack)->next;
        free(temp);
    }
}

t_stack *create_node(int value) {
    t_stack *node = (t_stack *)malloc(sizeof(t_stack));
    if (!node)
        return NULL;
    node->content = value;
    node->index = 0 ;
    node->next = NULL;
    return node;
}

int process_input(t_stack **a, char **av, int ac) {
    int i = 1;
    int j;
    char **res;

    while (i < ac) {
        res = ft_split(av[i], ' ');
        if (!res)
            return 0;

        j = 0;
        while (res[j]) {
            if (!is_valid(res[j])) {
                free(res[j]);
                free(res);
                free_stack(a);
                return 0;
            }
            t_stack *new_node = create_node(ft_atoi(res[j]));
            if (!new_node) {
                free(res[j]);
                free(res);
                free_stack(a);
                return 0;
            }
            ft_lstadd_back(a, new_node);
            free(res[j]);
            j++;
        }
        free(res);
        i++;
    }
    return 1;
}

int main(int ac, char *av[]) {
    t_stack *a = NULL;
    t_stack *b = NULL;

    if (ac == 1 || (ac == 2 && av[1][0] == '\0'))
        return 0;

    if (!process_input(&a, av, ac) || if_allready(a)) {
        ft_printf("Error\n");
        return 1;
    }
    edit_index(a);
    ft_print_list(a);
    
    free_stack(&a);
    free_stack(&b);
    return 0;
}
