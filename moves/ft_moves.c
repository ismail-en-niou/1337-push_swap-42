/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moves.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ien-niou <ien-niou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 09:45:53 by ien-niou          #+#    #+#             */
/*   Updated: 2025/01/04 10:42:21 by ien-niou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	_swap(t_stack **head, char *msg)
{
	t_stack	*tmp;

	if (!head || !*head || !(*head)->next)
		return ;
	tmp = *head;
	*head = (*head)->next;
	tmp->next = (*head)->next;
	(*head)->next = tmp;
	ft_printf("%s\n", msg);
}

void	_push(t_stack **head_a, t_stack **head_b, char *msg)
{
	t_stack	*tmp;

	if (!head_b || !(*head_b))
		return ;
	tmp = *head_b;
	*head_b = (*head_b)->next;
	tmp->next = NULL;
	ft_lstadd_front(head_a, tmp);
	ft_printf("%s\n", msg);
}

void	_rotat(t_stack **head, char *msg)
{
	t_stack	*tmp;

	if (!head || !*head || !(*head)->next)
		return ;
	tmp = *head;
	*head = (*head)->next;
	tmp->next = NULL;
	ft_lstlast(*head)->next = tmp;
	ft_printf("%s\n", msg);
}

void	_ss(t_stack **a, t_stack **b)
{
	_swap(a, "");
	_swap(b, "");
	ft_printf("ss");
}
