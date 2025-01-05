/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ien-niou <ien-niou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 17:17:30 by ien-niou          #+#    #+#             */
/*   Updated: 2025/01/05 16:41:11 by ien-niou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	edit_index(t_stack *s)
{
	t_stack	*temp1;
	t_stack	*temp2;
	int		index;

	if (!s)
		return ;
	temp1 = s;
	while (temp1)
	{
		temp2 = s;
		index = 0;
		while (temp2)
		{
			if (temp1->content > temp2->content)
				index++;
			temp2 = temp2->next;
		}
		temp1->index = index;
		temp1 = temp1->next;
	}
}

int	is_number(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '-' || str[0] == '+')
		i++;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			i++;
		else
			return (0);
	}
	return (1);
}

void	free_stack(t_stack **stack)
{
	t_stack	*temp;

	while (*stack)
	{
		temp = *stack;
		*stack = (*stack)->next;
		free(temp);
	}
}

int is_empty_or_whitespace(char **str , int ac)
{
	int i;
	int j;
	
	i = 0;
    while (i < ac)
	{
		j = 0;
		while (str[i][j])
		{
			if ((str[i][j] >= 9 && str[i][j] <= 13) || str[i][j] == 32 )
				return (0);
		}
	}
    return (1);
}
