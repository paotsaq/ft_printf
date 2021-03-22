/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_strings.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinto <apinto@student.42lisboa.c>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 07:21:40 by apinto            #+#    #+#             */
/*   Updated: 2021/03/22 05:18:04 by apinto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (unsigned char)c)
			return (char *)s;
		s++;
	}
	if (c == 0)
		return (char *)s;
	return (0);
}

int		ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

//	goes into libft
static	int		ft_strindex(char *str, char c)
{
	int i;

	if (!str)
		return (-1);
	i = -1;
	while (str[++i])
		if (str[i] == c)
			return (i);
	return (-1);
}

char	*strrev(char *s1)
{
	char	swp;
	int		i;
	int		len;

	i = -1;
	len = strlen(s1);
	while (++i < len / 2)
	{
		swp = s1[i];
		s1[i] = s1[len - i - 1];
		s1[len - i - 1] = swp;
	}
	return (s1);
}
