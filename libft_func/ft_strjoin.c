/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinto <apinto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 15:22:46 by apinto            #+#    #+#             */
/*   Updated: 2021/02/22 18:22:04 by apinto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	int		size;

	if (!s1 && !s2)
		return (0);
	if (!s1)
		return ((char *)s2);
	if (!s2)
		return ((char *)s1);
	size = ft_strlen(s1) + ft_strlen(s2) + 1;
	res = ft_calloc(size, 1);
	if (res)
	{
		ft_strlcat(res, s1, size);
		ft_strlcat(res, s2, size);
		return (res);
	}
	return (0);
}
