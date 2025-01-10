/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ien-niou <ien-niou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 17:17:54 by ien-niou          #+#    #+#             */
/*   Updated: 2025/01/10 11:20:47 by ien-niou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	ft_lstadd_front(t_stack **lst, t_stack *new)
{
	if (new && lst)
	{
		new->next = *lst;
		*lst = new;
	}
	else
		return ;
}
