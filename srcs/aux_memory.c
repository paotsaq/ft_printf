/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_memory.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinto <apinto@student.42lisboa.c>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 09:51:16 by apinto            #+#    #+#             */
/*   Updated: 2021/03/21 05:36:44 by apinto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	initializes_tr(t_flags *tr)
{
	tr->zero = 0;
	tr->minus = 0;
	tr->width = 0;
	tr->w_aster = 0;
	tr->p_aster = 0;
	tr->prec = 0;
}

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

void	*ft_reallocates_memory(void *old, size_t count, size_t size, int offset)
{
	void	*ptr;
	int		i;

	i = -1;
	if (count == 0 || size == 0)
		free(old);
	ptr = ft_calloc(count, size);
	if (ptr)
	{
		while (++i < (int)count - 1)
			if (size == 1)
				((char*)ptr)[i] = ((char*)old)[i + offset];
			else
				((char**)ptr)[i] = ((char**)old)[i + offset];
		if (size == 1)
			((char*)ptr)[i] = 0;
		else
			((char**)ptr)[i] = 0;
		free(old);
	}
	return (ptr);
}
