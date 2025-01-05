/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isallready.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ien-niou <ien-niou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 16:40:25 by ien-niou          #+#    #+#             */
/*   Updated: 2025/01/02 17:25:58 by ien-niou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	if_allready(t_stack *stack)
{
	t_stack	*current;
	t_stack	*runner;

	current = stack;
	while (current)
	{
		runner = current->next;
		while (runner)
		{
			if (current->content == runner->content)
			{
				return (1);
			}
			runner = runner->next;
		}
		current = current->next;
	}
	return (0);
}
