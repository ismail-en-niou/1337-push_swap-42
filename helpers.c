/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ien-niou <ien-niou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 17:17:30 by ien-niou          #+#    #+#             */
/*   Updated: 2025/01/02 17:22:34 by ien-niou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_print_list(t_stack *s)
{
	if (!s)
		return ;
	while (s)
	{
		ft_printf("%d index: %d\n", s->content, s->index);
		s = s->next;
	}
}

void	edit_index(t_stack *s)
{
	t_stack	*temp1;
	t_stack	*temp2;
	int		index;

	if (!s)
		return ;
	temp1 = s;
	while (temp1)
	{
		temp2 = s;
		index = 0;
		while (temp2)
		{
			if (temp1->content > temp2->content)
				index++;
			temp2 = temp2->next;
		}
		temp1->index = index;
		temp1 = temp1->next;
	}
}

int	is_number(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '-' || str[0] == '+')
		i++;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			i++;
		else
			return (0);
	}
	return (1);
}

void	free_stack(t_stack **stack)
{
	t_stack	*temp;

	while (*stack)
	{
		temp = *stack;
		*stack = (*stack)->next;
		free(temp);
	}
}
