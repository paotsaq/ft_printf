/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinto <apinto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 09:38:43 by apinto            #+#    #+#             */
/*   Updated: 2021/02/23 06:34:04 by apinto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*res;
	int		size;

	if (s)
	{
		if (start >= ft_strlen(s) - 1)
		{
			res = ft_calloc(sizeof(char), 1);
			if (!res)
				return (0);
		}
		else
		{
			if (ft_strlen(s) <= len)
				size = ft_strlen(s);
			else
				size = len;
			res = ft_calloc(sizeof(char), size + 1);
			if (!res)
				return (0);
			ft_strlcpy(res, s + start, size + 1);
		}
		return (res);
	}
	return (0);
}
