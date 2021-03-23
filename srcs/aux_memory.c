/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_memory.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinto <apinto@student.42lisboa.c>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 09:51:16 by apinto            #+#    #+#             */
/*   Updated: 2021/03/23 08:43:53 by apinto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	initializes_tr(t_info *tr)
{
	tr->zero = 0;
	tr->minus = 0;
	tr->width = 0;
	tr->w_aster = 0;
	tr->p_aster = 0;
	tr->prec = 0;
	tr->type = 0;
	tr->len = 0;
	tr->base = 0;
	tr->negative = 0;
	tr->invalid = 0;
}

void	char_family_allocation(t_info *tr, va_list *pargs)
{
	char *prov_str;

	if (tr->type == 'c')
	{
		(tr->content) = malloc(2 * sizeof(char));
		if (!tr->content)
			return;
		*(char *)(tr->content) = va_arg(*pargs, int);
		tr->len = 1;
	}
	else if (tr->type == 's')
	{
		prov_str = va_arg(*pargs, char *);
		(tr->content) = malloc(2 * strlen(prov_str));
		if (!tr->content)
			return;
		(tr->content) = strdup(prov_str);
		tr->len = strlen(prov_str);
	}
	// needs to be done!
	else if (tr->type == 'p')
		return;
}

void	int_family_allocation(t_info *tr, va_list *pargs)
{
	int				prov_number;
	unsigned int	number;

	if (tr->type == 'd' || tr->type == 'i')
	{
		prov_number = va_arg(*pargs, int);
		if (prov_number < 0)
		{
			tr->negative = 1;
			prov_number *= -1;
		}
		ft_putnbr_base(tr, (unsigned int)prov_number, DEC_BASE);
	}
	else
	{
		number = va_arg(*pargs, unsigned int);
		if (tr->type == 'u')
			ft_putnbr_base(tr, number, DEC_BASE);
		else
			ft_putnbr_base(tr, number, HEX_BASE);
	}
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
