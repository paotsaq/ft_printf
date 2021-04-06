/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinto <apinto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 09:27:18 by apinto            #+#    #+#             */
/*   Updated: 2021/02/12 07:18:18 by apinto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		size;
	char	*ptr;

	size = ft_strlen(s1);
	ptr = ft_calloc(1, size + 1);
	if (ptr != 0)
	{
		ft_strlcpy(ptr, s1, size + 1);
		return (ptr);
	}
	return (0);
}
