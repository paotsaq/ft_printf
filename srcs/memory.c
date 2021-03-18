/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinto <apinto@student.42lisboa.c>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 09:51:16 by apinto            #+#    #+#             */
/*   Updated: 2021/03/18 09:51:34 by apinto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	*ft_calloc(size_t count, size_t size)
{
	void			*mem;
	unsigned char	*iter;
	int				len;

	len = count * size;
	mem = (char *)malloc(len);
	if (!mem)
		return (0);
	iter = (unsigned char *)mem;
	while (len-- != 0)
		*iter++ = 0;
	return (mem);
}

