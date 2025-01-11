/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ien-niou <ien-niou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 10:33:57 by ien-niou          #+#    #+#             */
/*   Updated: 2025/01/11 15:47:44 by ien-niou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	max_r(t_stack *a)
{
	int	max;

	max = ft_lstsize(a);
	return (max * 0.048 + 10);
}

int	ft_lstmax_i(t_stack *lst, t_stack *max)
{
	int	pos;
	int	blasa;

	blasa = max->index;
	pos = 0;
	while (lst && lst->index != blasa)
	{
		pos++;
		lst = lst->next;
	}
	return (pos);
}

void	ft_range(t_stack **a, t_stack **b)
{
	int		size;
	t_stack	*max_node;
	int		max_index;

	while ((*b))
	{
		size = ft_lstsize(*b) / 2;
		max_node = ft_lstmax(*b);
		if (!max_node)
			return ;
		max_index = max_node->index;
		if (ft_lstmax_i(*b, max_node) >= size)
		{
			while ((*b) && (*b)->index != max_index)
				_revrotate(b, "rrb");
		}
		else
		{
			while ((*b) && (*b)->index != max_index)
				_rotat(b, "rb");
		}
		_push(a, b, "pa");
	}
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
		else if ((*a)->index < sort.min_range)
		{
			_push(b, a, "pb");
			_rotat(b, "rb");
			sort.max_range++;
			sort.min_range++;
		}
		else if ((*a)->index >= sort.min_range && (*a)->index <= sort.max_range)
		{
			_push(b, a, "pb");
			sort.max_range++;
			sort.min_range++;
		}
	}
	ft_range(a, b);
}

t_stack	*ft_lstmax(t_stack *lst)
{
	t_stack	*max;

	if (!lst)
		return (NULL);
	max = lst;
	while (lst)
	{
		if (max->content < lst->content)
		{
			max = lst;
		}
		lst = lst->next;
	}
	return (max);
}
