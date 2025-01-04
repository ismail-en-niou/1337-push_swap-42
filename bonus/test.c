/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ien-niou <ien-niou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 11:59:57 by ien-niou          #+#    #+#             */
/*   Updated: 2025/01/04 12:55:21 by ien-niou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	check_str( t_stack **a, t_stack **b, char *str)
{
	if (!ft_strncmp(str, "sa\n", 3))
		_swap(a, "");
	else if (!ft_strncmp(str, "sb\n", 3))
		_swap(b, "");
	else if (!ft_strncmp(str, "ss\n", 3))
		_ss(a, b, "");
	else if (!ft_strncmp(str, "pa\n", 3))
		_push(a, b, "");
	else if (!ft_strncmp(str, "pb\n", 3))
		_push(b, a, "");
	else if (!ft_strncmp(str, "ra\n", 3))
		_rotat(a, "");
	else if (!ft_strncmp(str, "rb\n", 3))
		_rotat(b, "");
	else if (!ft_strncmp(str, "rr\n", 3))
		_rr(a, b, false, "");
	else if (!ft_strncmp(str, "rrr\n", 4))
		_rr(a, b, true, "");
	else if (!ft_strncmp(str, "rra\n", 4))
		_revrotate(a, "");
	else if (!ft_strncmp(str, "rrb\n", 4))
		_revrotate(b, "");
	else
        {
            ft_printf("Error\n");
		    exit(2);
        }
}