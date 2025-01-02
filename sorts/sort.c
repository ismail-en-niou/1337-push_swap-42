/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ien-niou <ien-niou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 11:33:53 by ien-niou          #+#    #+#             */
/*   Updated: 2025/01/02 17:37:28 by ien-niou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	max_r(t_stack *a)
{
	int	max;

	max = ft_lstsize(a);
	printf("size the list %d \n", max);
	if (max <= 15)
		return (max * 0.45);
	return (max * 0.45 + 10);
}

t_stack	*ft_lstmax(t_stack *lst)
{
	t_stack	*max;

	if (!lst)
		return (NULL);
	max = create_node(0);
	while (lst)
	{
		if (max->content < lst->content)
		{
			free(max);
			max = create_node(lst->content);
		}
		lst = lst->next;
	}
	return (max);
}

int	find_min_index(t_stack *lst)
{
	int	min;

	min = 0;
	while (lst)
	{
		if (min > lst->index)
		{
			min = lst->index;
		}
		lst = lst->next;
	}
	return (min);
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
	free(max);
}

void	ft_list4_5(t_stack **a, t_stack **b)
{
	int	size;

	size = ft_lstsize(*a);
	if (size == 4)
		_push(b, a, "pb");
	else if (size == 5)
	{
		_push(b, a, "pb");
		_push(b, a, "pb");
	}
	ft_list3(a);
	while (*b)
	{
		if ((*b)->next && (*b)->content > (*b)->next->content)
			_swap(b, "sb");
		_push(a, b, "pa");
		while (!is_sorted(*a))
		{
			if ((*a)->index > ft_lstlast(*a)->index)
				_rotat(a, "ra");
		}
	}
}

void	sort(t_stack **a, t_stack **b)
{
	size_t	list_size;

	(void)b;
	list_size = ft_lstsize(*a);
	if (list_size == 2)
		_swap(a, "sa");
	else if (list_size == 3)
		ft_list3(a);
	else if (list_size == 5 || list_size == 4)
		ft_list4_5(a, b);
}
