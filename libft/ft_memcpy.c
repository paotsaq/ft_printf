/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinto <apinto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 18:16:50 by apinto            #+#    #+#             */
/*   Updated: 2021/04/05 13:26:57 by apinto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*iter;

	if (!(src) && !(dst))
		return (0);
	iter = dst;
	while (n-- != 0)
		*(iter++) = *(char *)(src++);
	return (dst);
}
