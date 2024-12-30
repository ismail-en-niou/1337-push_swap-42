/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ien-niou <ien-niou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 17:49:45 by ien-niou          #+#    #+#             */
/*   Updated: 2024/12/28 18:41:43 by ien-niou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_space(char c)
{
	return (c == ' ' || (c >= 9 && c <= 13));
}

static void	*ft_free(char **res, int j)
{
	while (j > 0)
		free(res[--j]);
	free(res);
	return (NULL);
}

static char	*ft_strcpy_w(char const *src, char sep)
{
	int		len;
	char	*word;
	int		i;

	len = 0;
	i = 0;
	while (src[len] && src[len] != sep)
		len++;
	word = malloc(len + 1);
	if (!word)
		return (NULL);
	while (i < len)
	{
		word[i] = src[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

int	count_word(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (!str)
		return (0);
	while (is_space(str[i]))
		i++;
	while (str[i])
	{
		if (!is_space(str[i]))
		{
			count++;
			while (str[i] && !is_space(str[i]))
				i++;
		}
		else
			i++;
	}
	return (count);
}

char	**split(char *s)
{
	int		i;
	int		j;
	char	**res;

	i = 0;
	j = 0;
	res = malloc((count_word(s) + 1) * sizeof(char *));
	if (!s || !(res))
		return (NULL);
	while (s[i])
	{
		while (s[i] && s[i] == ' ')
			i++;
		if (s[i])
		{
			res[j] = ft_strcpy_w(&s[i], ' ');
			if (!res[j++])
				return (ft_free(res, j - 1));
			while (s[i] && s[i] != ' ')
				i++;
		}
	}
	res[j] = NULL;
	return (res);
}
