/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ien-niou <ien-niou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 13:38:14 by ien-niou          #+#    #+#             */
/*   Updated: 2025/01/07 13:58:32 by ien-niou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void ft_str_fd(char *str)
{
    int i ;

    i = 0;
    while (str[i])
    {
        write(2,&str[i],1);
        i++;
    }
    
}