/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinto <apinto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 10:24:47 by apinto            #+#    #+#             */
/*   Updated: 2021/04/05 13:24:57 by apinto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	count_separators(const char *s, char c)
{
	while (*s && *s == c)
	{
		s++;
		if (*s == 0)
			return (0);
	}
	while (*s && *s != c)
	{
		s++;
		if (*s == c || *s == 0)
			return (1 + count_separators(s, c));
	}
	return (0);
}

static	void	handle_copies(char **array, const char *s, int size)
{
	char	*segment;

	segment = ft_calloc(sizeof(char), size + 1);
	ft_strlcpy(segment, s, size + 1);
	*array = segment;
}

void	aux_split(char **res, char const *s, int nos, char c)
{
	int		pos;
	int		i;
	int		j;

	i = 0;
	pos = 0;
	while (s[i] && pos < nos)
	{
		while (s[i] && s[i] == c)
			i++;
		j = i;
		while (s[j] && s[j] != c)
			j++;
		handle_copies(&res[pos++], &s[i], j - i);
		i = j + 1;
	}
	res[nos] = 0;
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	int		number_of_segments;

	if (!s)
		return (0);
	number_of_segments = count_separators(s, c);
	res = ft_calloc(sizeof(char *), number_of_segments + 1);
	if (!res)
		return (0);
	aux_split(res, s, number_of_segments, c);
	return (res);
}
