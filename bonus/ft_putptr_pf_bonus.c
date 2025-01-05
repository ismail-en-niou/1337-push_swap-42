/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr_pf_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ien-niou <ien-niou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 14:48:39 by ien-niou          #+#    #+#             */
/*   Updated: 2025/01/05 16:40:30 by ien-niou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	ft_putptr_pf(void *ptr, size_t *counter)
{
	unsigned long	addr;

	if (!ptr)
	{
		ft_putstr_pf("0x0", counter);
		return ;
	}
	addr = (unsigned long)ptr;
	ft_putstr_pf("0x", counter);
	ft_putnbr_hex_pf(addr, counter, 1);
}
