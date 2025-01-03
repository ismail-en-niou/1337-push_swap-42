/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ien-niou <ien-niou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 10:33:57 by ien-niou          #+#    #+#             */
/*   Updated: 2025/01/03 15:33:50 by ien-niou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	max_r(t_stack *a)
{
	int	max;

	max = ft_lstsize(a);
	printf("size the list %d \n", max);
	if (max <= 15)
		return (max * 0.045);
	return (max * 0.045 + 10);
}

void	ft_list_handeler(t_stack **a, t_stack **b)
{
	t_sort	sort;

	sort.max_range = max_r(*a);
	sort.min_range = 0;
	while ((*a))
	{
		if ((*a)->index > sort.max_range)
			_rotat(a, "ra");
		else if (((*a)->index < sort.min_range)
			|| ((*a)->index >= sort.min_range && (*a)->index <= sort.max_range))
		{
			if ((*a)->index < sort.min_range)
				_rotat(b, "rb");
			_push(b, a, "pb");
			sort.max_range++;
			sort.min_range++;
		}
	}
}

void	ft_swap_if_needed(t_stack **b)
{
	if ((*b)->next && (*b)->content > (*b)->next->content)
		_swap(b, "sb");
}
