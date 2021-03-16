/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinto <apinto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 09:36:33 by apinto            #+#    #+#             */
/*   Updated: 2021/02/23 05:21:06 by apinto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*res;
	int		i;

	i = -1;
	if (!s || !f)
		return (0);
	res = ft_calloc(1, ft_strlen(s) + 1);
	if (!res)
		return (res);
	while (s[++i])
		res[i] = (*f)(i, s[i]);
	return (res);
}
