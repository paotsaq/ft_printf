/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_memory.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinto <apinto@student.42lisboa.c>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 09:51:16 by apinto            #+#    #+#             */
/*   Updated: 2021/04/02 17:28:35 by apinto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	initializes_info(t_info *info)
{
	info->zero = 0;
	info->minus = 0;
	info->width = 0;
	info->w_aster = 0;
	info->p_aster = 0;
	info->w_inp = 0;
	info->p_inp = 0;
	info->prec = 0;
	info->type = 0;
	info->chr = 0;
	info->content = 0;
	info->len = 0;
	info->negative = 0;
	info->invalid = 0;
}

void	char_family_allocation(t_info *info, va_list *pargs)
{
	if (ft_strchr("c%",info->type))
	{
		if (info->type == 'c')
			info->chr = va_arg(*pargs, int);
		else
			info->chr = '%';
		info->len = 1;
	}
	else if (info->type == 's')
	{
		(info->content) = va_arg(*pargs, char *);
		info->len = ft_strlen(info->content);
	}
	// needs to be done!
	else if (info->type == 'p')
		return;
}

void	int_family_allocation(t_info *info, va_list *pargs, char *buffer)
{
	long long		prov_number;

	if (ft_strchr("diuxX", info->type))
	{
		prov_number = va_arg(*pargs, int);
		if (prov_number < 0)
		{
			info->negative = 1;
			prov_number *= -1;
		}
		ft_bzero(buffer, 12);
		if (info->type == 'd' || info->type == 'i')
			number_to_string(info, prov_number, DEC_BASE, buffer);
		else if (info->type == 'u')
			number_to_string(info, prov_number, DEC_BASE, buffer);
		else
			number_to_string(info, prov_number, HEX_BASE, buffer);
	}
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
