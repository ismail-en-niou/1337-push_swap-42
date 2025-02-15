/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moves1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ien-niou <ien-niou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 13:11:18 by ien-niou          #+#    #+#             */
/*   Updated: 2025/01/02 17:34:27 by ien-niou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack	*secondlast(t_stack *head)
{
	if (!head || !head->next)
		return (NULL);
	while (head->next && head->next->next)
		head = head->next;
	return (head);
}

void	_revrotate(t_stack **head, char *msg)
{
	t_stack	*tmp;
	t_stack	*tmp2;

	if (!head || !*head || !(*head)->next)
		return ;
	tmp = ft_lstlast(*head);
	tmp2 = secondlast(*head);
	tmp2->next = NULL;
	tmp->next = *head;
	*head = tmp;
	ft_printf("%s\n", msg);
}

void	_rr(t_stack **a, t_stack **b, bool isrev, char *msg)
{
	if (isrev)
	{
		_revrotate(a, "");
		_revrotate(b, "");
		ft_printf("%s\n", msg);
		return ;
	}
	_rotat(a, "");
	_rotat(b, "");
	ft_printf("%s\n", msg);
}
