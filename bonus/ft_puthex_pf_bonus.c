/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_pf_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ien-niou <ien-niou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 14:48:11 by ien-niou          #+#    #+#             */
/*   Updated: 2025/01/05 16:40:14 by ien-niou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	ft_putnbr_hex_pf(unsigned long num, size_t *counter, int base)
{
	char	*hex_digits;

	if (base)
	{
		hex_digits = HEX_LOW_BASE;
	}
	else
		hex_digits = HEX_UPP_BASE;
	if (num >= 16)
	{
		ft_putnbr_hex_pf(num / 16, counter, base);
		ft_putnbr_hex_pf(num % 16, counter, base);
	}
	else
	{
		ft_putchar_pf(hex_digits[num], counter);
	}
}
