/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isallready.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ien-niou <ien-niou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 16:40:25 by ien-niou          #+#    #+#             */
/*   Updated: 2024/12/30 16:52:42 by ien-niou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int if_allready(t_stack *stack) {
    t_stack *current = stack;
    t_stack *runner;

    while (current) {
        runner = current->next;
        while (runner) {
            if (current->content == runner->content) {
                return 1;
            }
            runner = runner->next;
        }
        current = current->next;
    }
    return 0;
}