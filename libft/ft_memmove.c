/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinto <apinto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 17:07:12 by apinto            #+#    #+#             */
/*   Updated: 2021/02/20 16:47:21 by apinto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*destn;
	unsigned char	*sourc;
	int				i;

	destn = (unsigned char*)dst;
	sourc = (unsigned char*)src;
	i = len - 1;
	if (sourc < destn)
	{
		while (i >= 0)
		{
			destn[i] = sourc[i];
			i--;
		}
	}
	else
		ft_memcpy(dst, src, len);
	return (dst);
}
