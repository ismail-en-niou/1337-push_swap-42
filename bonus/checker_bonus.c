/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ien-niou <ien-niou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 11:19:58 by ien-niou          #+#    #+#             */
/*   Updated: 2025/01/07 15:13:21 by ien-niou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	free_res_and_stack(char **res, t_stack **a)
{
	int	j;

	j = 0;
	while (res[j])
	{
		free(res[j]);
		j++;
	}
	free(res);
	free_stack(a);
}

int	process_value(t_stack **a, char **res, int j)
{
	long	nb;
	t_stack	*new_node;

	if (((res[j][0] == '-' || res[j][0] == '+') && !res[j][1]))
		return (0);
	nb = ft_atoi(res[j]);
	if (!is_number(res[j]) || (nb) > INT_MAX || nb < INT_MIN)
		return (0);
	new_node = create_node(nb);
	if (!new_node)
		return (0);
	ft_lstadd_back(a, new_node);
	return (1);
}

int	process_input(t_stack **a, char **av, int ac)
{
	int		i;
	int		j;
	char	**res;
	int		k;

	i = 1;
	while (i < ac)
	{
		res = ft_split(av[i++], ' ');
		if (!res)
			return (0);
		j = 0;
		while (res[j])
		{
			if (!process_value(a, res, j++))
			{
				return (free_res_and_stack(res, a), 0);
			}
		}
		k = 0;
		while (res[k] != NULL)
			free(res[k++]);
		free(res);
	}
	return (1);
}

int	validate_input(t_stack **a, char **av, int ac)
{
	if (!process_input(a, av, ac) || if_allready(*a))
	{
		ft_str_fd("Error\n");
		return (0);
	}
	return (1);
}

int	main(int ac, char *av[])
{
	char	*line;
	t_stack	*a;
	t_stack	*b;

	line = NULL;
	a = NULL;
	b = NULL;
	if (ac <= 1 || (ac == 2 && av[1][0] == '\0') || !validate_input(&a, av, ac))
		return (1);
	while (1)
	{
		line = get_next_line(0);
		if (!line)
			break ;
		check_str(&a, &b, line);
		free(line);
	}
	free(line);
	if (!ft_lstsize(b) && is_sorted(a))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	free_stack(&a);
	return (0);
}
