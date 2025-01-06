/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ien-niou <ien-niou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 11:33:53 by ien-niou          #+#    #+#             */
/*   Updated: 2025/01/04 10:30:34 by ien-niou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	find_min_index(t_stack *lst)
{
	int	min_index;

	if (!lst)
		return (-1);
	min_index = lst->index;
	while (lst)
	{
		if (lst->index < min_index)
			min_index = lst->index;
		lst = lst->next;
	}
	return (min_index);
}

void	ft_list3(t_stack **a)
{
	t_stack	*max;

	max = ft_lstmax(*a);
	if (max->content == (*a)->content)
		_rotat(a, "ra");
	else if (max->content == (*a)->next->content)
		_revrotate(a, "rra");
	if ((*a)->content > (*a)->next->content)
		_swap(a, "sa");
}

void	push_min_to_b(t_stack **a, t_stack **b, int times)
{
	int	min_index;

	while (times--)
	{
		min_index = find_min_index(*a);
		while ((*a)->index != min_index)
			_rotat(a, "ra");
		_push(b, a, "pb");
	}
}

void	ft_list4_5(t_stack **a, t_stack **b)
{
	int	size;

	size = ft_lstsize(*a);
	if (size == 4)
		push_min_to_b(a, b, 1);
	else if (size == 5)
		push_min_to_b(a, b, 2);
	ft_list3(a);
	while (*b)
		_push(a, b, "pa");
}

void	sort(t_stack **a, t_stack **b)
{
	size_t	list_size;

	list_size = ft_lstsize(*a);
	if (list_size == 2)
		_swap(a, "sa");
	else if (list_size == 3)
		ft_list3(a);
	else if (list_size == 5 || list_size == 4)
		ft_list4_5(a, b);
	else if (list_size > 5)
		ft_list_handeler(a, b);
}
